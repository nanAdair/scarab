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
#include <stdio.h>
#include "file.h"
#include "utilsGD.h"

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

SCFile::~SCFile()
{
    delete this->file_data;
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

void SCFileEXEC::prepare(SCSectionList *sl)
{
    this->setSectionTable(sl);
    this->setProgramHeader(sl);
    this->makeFileHeader(sl);
    
}

void SCFileEXEC::writeOut(SCSectionList *sl)
{
    ofstream os;
    os.open("output", ofstream::binary);
    //FILE *output;
    //output = fopen("output", "wb");
    
    UINT32 ehdr_size, phdr_size, sectab_size;
    ehdr_size = this->getFileHeader()->e_ehsize;
    phdr_size = this->getFileHeader()->e_phentsize * this->getFileHeader()->e_phnum;
    sectab_size = this->getFileHeader()->e_shentsize * this->getFileHeader()->e_shnum;
    
    os.write((char *)this->getFileHeader(), ehdr_size);
    os.write((char *)this->phdr_data , phdr_size);
    //fwrite((char *)this->getFileHeader(), ehdr_size, 1, output);
    //fwrite((char *)this->phdr_data, phdr_size, 1, output);
    
    UINT8 zero = 0x0;
    UINT32 offset;
    offset = ehdr_size + phdr_size;
    vector<SCSection*>::iterator it;
    for (it = sl->getSectionList()->begin() + 1; it != sl->getSectionList()->end(); ++it) {
        if (offset != (*it)->getSecFileOffset()) {
            for (int i = 0; i < (*it)->getSecFileOffset() - offset; i++)
                os.write((char *)&zero, 1);
                //fwrite(&zero, 1, 1, output);
            offset = (*it)->getSecFileOffset();
        }
        
        if ((*it)->getSecType() == SHT_NOBITS)
            continue;
        
        os.write((char *)(*it)->getSecData(), (*it)->getSecDatasize());
        //fwrite((char *)(*it)->getSecData(), (*it)->getSecDatasize(), 1, output);
        offset += (*it)->getSecDatasize();
    }

    //fclose(output);
    //fwrite((char *)this->exec_sec_table->content, this->exec_sec_table->size, 1, output);
    //os.write((char *)this->exec_sec_table->content, this->exec_sec_table->size);
    os.write((char *)this->exec_sec_table->content, this->exec_sec_table->size);
    os.close();
}

void SCFileEXEC::makeFileHeader(SCSectionList *sl)
{
    Elf32_Ehdr *header = (Elf32_Ehdr *)malloc(sizeof(Elf32_Ehdr));
    memset(header, 0x0, sizeof(Elf32_Ehdr));
    
    SCSection *text, *last_sec, *shstr;
    text = sl->getSectionByName(TEXT_SECTION_NAME);
    shstr = sl->getSectionByName(SHSTRTAB_SECTION_NAME);
    vector<SCSection*>::iterator it;
    it = sl->getSectionList()->end() -1;
    last_sec = *it;
    
    memcpy(header->e_ident, e_identGD, 0x16);
    header->e_type = ET_EXEC;
    header->e_machine = EM_386;
    header->e_version = 1;
    header->e_entry = text->getSecAddress();
    header->e_phoff = sizeof(Elf32_Ehdr);
    header->e_shoff = last_sec->getSecFileOffset() + last_sec->getSecDatasize();
    header->e_flags = 0x0;
    header->e_ehsize = sizeof(Elf32_Ehdr);
    header->e_phentsize = 0x20;
    header->e_phnum = 7;
    header->e_shentsize = sizeof(Elf32_Shdr);
    header->e_shnum = this->exec_sec_table->getSecTableNumber();
    header->e_shstrndx = shstr->getSecIndex();
    
    this->setFileHeader(header);
}

void SCFileEXEC::setSectionTable(SCSectionList *sl)
{
    SCSectionTable *temp = new SCSectionTable();
    temp->makeSectionTable(sl); 
    
    this->exec_sec_table = temp;
    //os.write((char *)temp->content, temp->size);
}

void SCFileEXEC::setProgramHeader(SCSectionList *sl)
{
    int entsize = 0x20;
    
    UINT8 *buffer;
    UINT32 buffer_size;
    buffer = NULL;
    buffer_size = 0;
    
    int number, addition;
    number = sizeof(Program_HeadersGD) / entsize;
    addition = entsize;
    
    for (int i = 0; i < number; i++) {
        Elf32_Phdr program_header;
        program_header = Program_HeadersGD[i];
        UINT32 type;
        type = program_header.p_type;
        
        switch(type) {
            case PT_PHDR:
                this->updateProgPhdr(&program_header);
                break;
            case PT_INTERP:
                this->updateProgInterp(&program_header, sl);
                break;
            case PT_LOAD:
                this->updateProgLoad(&program_header, sl);
                break;
            case PT_DYNAMIC:
                this->updateProgDynamic(&program_header, sl);
                break;
            case PT_NOTE:
                this->updateProgNote(&program_header, sl);
                break;
            case PT_GNU_STACK:
                /*UpdateProgGNU_STACK(&program_header, sec_list);*/
                break;
            default:
                printf("error in handling the phdr type %d\n", type);
                break;
        }
        
        UINT8 *newbuffer;
        newbuffer = (UINT8 *)malloc(buffer_size + addition);
        memset(newbuffer, 0x0, buffer_size + addition);
        memcpy(newbuffer, buffer, buffer_size);
        memcpy(newbuffer + buffer_size, &program_header, addition);
        
        if (buffer)
            free(buffer);
        buffer = newbuffer;
        buffer_size += addition;
    }
    
    this->phdr_data = buffer;
}

void SCFileEXEC::updateProgPhdr(Elf32_Phdr *phdr)
{
    UINT32 offset, base_addr;
    offset = sizeof(Elf32_Ehdr);
    base_addr = 0x8048000;
    
    phdr->p_offset = offset;
    phdr->p_vaddr = phdr->p_paddr = base_addr + offset;
    phdr->p_memsz = phdr->p_filesz = sizeof(Program_HeadersGD);
}

void SCFileEXEC::updateProgInterp(Elf32_Phdr *phdr, SCSectionList *sl)
{
    SCSection *interp;
    interp = sl->getSectionByName(INTERP_SECTION_NAME);
    
    UINT32 offset, base_addr;
    offset = interp->getSecFileOffset();
    base_addr = 0x8048000;
    
    phdr->p_offset = offset;
    phdr->p_vaddr = phdr->p_paddr = base_addr + offset;
    phdr->p_memsz = phdr->p_filesz = interp->getSecDatasize();

}

void SCFileEXEC::updateProgLoad(Elf32_Phdr *phdr, SCSectionList *sl)
{
    UINT32 offset, base_addr, filesize, memsize;
    
    if (phdr->p_flags & PF_X) {
        offset = 0;
        base_addr = 0x8048000;
        UINT32 dataBegin, dataEnd;
        dataBegin = 0;
        
        vector<SCSection*>::iterator it;
        for (it = sl->getSectionList()->begin(); it != sl->getSectionList()->end(); ++it) {
            if ((*it)->getSecFlags() & SHF_WRITE)
                break;
        }
        dataEnd = (*it)->getSecFileOffset();
        
        filesize = dataEnd - dataBegin;
        memsize = filesize;
    }
    
    if (phdr->p_flags & PF_W) {
        UINT32 dataBegin, dataEnd;
        dataBegin = 0;
        
        vector<SCSection*>::iterator it;
        for (it = sl->getSectionList()->begin(); it != sl->getSectionList()->end(); ++it) {
            if ((*it)->getSecFlags() & SHF_WRITE)
                break;
        }
        offset = (*it)->getSecFileOffset();
        base_addr = (*it)->getSecAddress();
        dataBegin = (*it)->getSecFileOffset();
        
        for (; it != sl->getSectionList()->end(); ++it) {
            if (!((*(it+1))->getSecFlags() & SHF_WRITE)) 
                break;
        }
        dataEnd = (*it)->getSecFileOffset();
        filesize = dataEnd - dataBegin;
        memsize = filesize + (*it)->getSecDatasize();
    }
    
    phdr->p_offset = offset;
    phdr->p_vaddr = phdr->p_paddr = base_addr;
    phdr->p_filesz = filesize;
    phdr->p_memsz = memsize;
}

void SCFileEXEC::updateProgDynamic(Elf32_Phdr *phdr, SCSectionList *sl){
    SCSection *dynamic;
    dynamic = sl->getSectionByName(DYNAMIC_SECTION_NAME);
    
    phdr->p_offset = dynamic->getSecFileOffset();
    phdr->p_vaddr = phdr->p_paddr = dynamic->getSecAddress();
    phdr->p_filesz = phdr->p_memsz = dynamic->getSecDatasize();
}

void SCFileEXEC::updateProgNote(Elf32_Phdr *phdr, SCSectionList *sl){
    SCSection *note;
    note = sl->getSectionByName(NOTE_SECTION_NAME);
    
    phdr->p_offset = note->getSecFileOffset();
    phdr->p_vaddr = phdr->p_paddr = note->getSecAddress();
    phdr->p_filesz = phdr->p_memsz = note->getSecDatasize();
}

void SCSectionTable::makeSectionTable(SCSectionList *sl)
{
    //SCSectionTable *sec_tab;
    //sec_tab = new SCSectionTable();
    
    Elf32_Shdr *cur_shdr;
    UINT8 *buffer;
    UINT32 buffer_size, addition, offset;
    buffer = NULL;
    buffer_size = 0;
    addition = sizeof(Elf32_Shdr);
    int number = 0;
    
    vector<SCSection*>::iterator it;
    for (it = sl->getSectionList()->begin(); it != sl->getSectionList()->end(); ++it) {
        cur_shdr = (Elf32_Shdr *)malloc(addition);
        
        cur_shdr->sh_name = (*it)->getSecNameOffset();
        cur_shdr->sh_type = (*it)->getSecType();
        cur_shdr->sh_flags = (*it)->getSecFlags();
        cur_shdr->sh_addr = (*it)->getSecAddress();
        cur_shdr->sh_offset = (*it)->getSecFileOffset();
        cur_shdr->sh_size = (*it)->getSecDatasize();
        cur_shdr->sh_link = (*it)->getSecLink();
        cur_shdr->sh_info = (*it)->getSecInfo();
        cur_shdr->sh_addralign = (*it)->getSecAlign();
        cur_shdr->sh_entsize = (*it)->getSecEntsize();
        
        UINT8 *newbuffer;
        newbuffer = (UINT8 *)malloc(buffer_size + addition);
        memset(newbuffer, 0x0, buffer_size + addition);
        memcpy(newbuffer, buffer, buffer_size);
        memcpy(newbuffer + buffer_size, cur_shdr, addition);
        
        if (buffer)
            free(buffer);
        buffer = newbuffer;
        buffer_size += addition;
        free(cur_shdr);
        number++;
    }
    
    this->content = buffer;
    this->size = buffer_size;
    this->number = number;
}

SCFileEXEC::~SCFileEXEC()
{
    if (this->exec_sec_table)
        delete this->exec_sec_table;
}

SCSectionTable::~SCSectionTable()
{
    if (this->content)
        free(this->content);
}
