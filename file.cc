/*
 * =====================================================================================
 *
 *       SCFilename:  file.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 09:40:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <fstream>
#include <iostream>
#include <string.h>
#include "file.h"

void SCFile::initFilePart(char *file_name)
{
    ifstream is;
    
    is.open(file_name, ifstream::binary);
    if (!is) {
        cout << "error: unable to open file " << file_name << endl;
    }
    
    is.seekg(0, is.end);
    UINT32 file_size = is.tellg();
    is.seekg(0, is.beg);
    
    char *file_data = new char [file_size];
    is.read(file_data, file_size);
    is.close();
    //this->file_name = new UINT8 [strlen(file_name) + 1];
    //strcpy((char *)this->file_name, file_name);
    //this->file_name[strlen(file_name)] = '\0';
    /* store one file name, and let other attributes point to it */
    this->file_name = (UINT8 *)file_name;

    this->file_size = file_size;
    this->file_data = (UINT8 *)file_data;
    
    fillFilePartContent();
}

void SCFile::fillFilePartContent()
{
    this->file_header = (Elf32_Ehdr *)(this->file_data);
    
    INT16 shstrndx;
    shstrndx = this->file_header->e_shstrndx;
    
    this->section_table = (Elf32_Shdr *)(this->file_data + this->file_header->e_shoff);
    this->section_strn_table = (UINT8 *)(this->file_data + (this->section_table + shstrndx)->sh_offset);
    this->section_number = this->file_header->e_shnum;
}

void SCFile::testSectionTable() const
{
    int numberOfSections = this->file_header->e_shnum;
    for (int i = 0; i < numberOfSections; i++) {
        Elf32_Shdr *cur_section;
        cur_section = this->section_table + i;
        cout << i << " " << hex << cur_section->sh_offset << endl;
    }
}
    

void SCFileREL::init(char *file_name)
{
    initFilePart(file_name);
    
    int numberOfSections;
    numberOfSections = this->file_header->e_shnum;
    
    for (int i = 0; i < numberOfSections; i++) {
        Elf32_Shdr *cur_section;
        cur_section = this->section_table + i;
        
        if (cur_section->sh_type == SHT_SYMTAB) {
            this->sym_table_dr = cur_section;
            this->sym_table = (Elf32_Sym *)(this->file_data + cur_section->sh_offset);
            this->sym_strn_table = this->file_data + (this->section_table + cur_section->sh_link)->sh_offset;
        }
        
        if (cur_section->sh_type == SHT_REL) {
            this->rel_num++;
            this->rel_index.push_back(i);
        }
    }
    
    this->file_type = BINARY_RELOCATABLE_TYPE;
}

void SCFileREL::testRelIndex() const
{
    for (int i = 0; i < this->rel_index.size(); i++)
        cout << i << " " << this->rel_index[i] << endl;
}

void SCFileREL::testSymTable() const
{
    int size, entsize;
    size = this->sym_table_dr->sh_size;
    entsize = this->sym_table_dr->sh_entsize;
    
    for (int i = 0; i < size / entsize; i ++) {
        Elf32_Sym *cur_sym;
        cur_sym = this->sym_table + i;
        
        cout << i << " " << this->sym_strn_table + cur_sym->st_name << " ";
        cout << hex << cur_sym->st_shndx << endl;
    }
}

void SCFileDYN::init(char *file_name)
{
    initFilePart(file_name);
    
    int numberOfSections;
    numberOfSections = this->file_header->e_shnum;
    
    for (int i = 0; i < numberOfSections; i++) {
        Elf32_Shdr *cur_section;
        cur_section = this->section_table + i;
        
        if (cur_section->sh_type == SHT_DYNSYM) {
            this->dynsym_table_dr = cur_section;
            this->dynsym_table = (Elf32_Sym *)(this->file_data + cur_section->sh_offset);
            this->dynsym_strn_table = this->file_data + (this->section_table + cur_section->sh_link)->sh_offset;
        }
    }
    this->file_type = BINARY_SHARED_TYPE;
}

void SCFileDYN::testDynsymTable() const
{
    int size, entsize;
    size = this->dynsym_table_dr->sh_size;
    entsize = this->dynsym_table_dr->sh_entsize;
    
    for (int i = 0; i < size / entsize; i ++) {
        Elf32_Sym *cur_sym;
        cur_sym = this->dynsym_table + i;
        
        cout << i << " " << this->dynsym_strn_table + cur_sym->st_name << " ";
        cout << hex << cur_sym->st_shndx << endl;
    }
}
