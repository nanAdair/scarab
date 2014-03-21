/*
 * =====================================================================================
 *
 *       SCFilename:  symbol.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 09:27:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "symbol.h"

void SCSymbol::init(UINT8 *sym_strn_table, SCSectionList *sl, SCSectionList *msl)
{
    int name_length = strlen((const char *)(sym_strn_table + this->sym_name_offset));
    this->sym_name = (UINT8 *)malloc(name_length + 1);
    strcpy((char *)this->sym_name, (const char *)(sym_strn_table + this->sym_name_offset));
    this->sym_name[name_length] = '\0';
    
    SCSection *temp;
    int index = this->sym_shndx;
    if (index != SHN_ABS && index != SHN_COMMON && index != SHN_UNDEF) {
        temp = sl->getSectionByIndex(this->sym_shndx);
        if (temp) {
            this->sym_sec = temp;
        }
        else {
            temp = msl->getSectionByIndex(this->sym_shndx);
            this->sym_sec = temp->getMergetoSection();
            this->sym_value += temp->getSecDelta();
        }
    }
}

void SCSymbolListREL::init(SCFileREL &file, SCSectionList *sl, SCSectionList *msl)
{
    Elf32_Sym *cur_sym;
    Elf32_Shdr *sym_table_dr;
    UINT8 *sym_strn_table;
    
    sym_table_dr = file.getSymTableDr();
    sym_strn_table = file.getSymStrnTable();
    
    for (int i = 0; i < sym_table_dr->sh_size / sym_table_dr->sh_entsize; i++) {
        cur_sym = file.getSymTable() + i;
        SCSymbol *sym = new SCSymbol(cur_sym, i);
        sym->init(sym_strn_table, sl, msl);
        this->sym_list.push_back(sym);
    }
}

void SCSymbolListREL::testSymbolList()
{
    vector<SCSymbol*>::iterator it;
    for (it = this->sym_list.begin(); it != this->sym_list.end(); ++it) {
        cout << (*it)->getSymbolIndex() << "  " << (*it)->sym_name << "  "
            << hex << (*it)->sym_value << "  " << endl;
    }
}

void SCSymbolDYN::init(UINT8 *dynsym_strn_table, SCSectionList *sl, UINT8 *file_name, SCVersionList *vl)
{
    int name_length = strlen((const char *)(dynsym_strn_table + this->sym_name_offset));
    this->sym_name = (UINT8 *)malloc(name_length + 1);
    strcpy((char *)this->sym_name, (const char *)(dynsym_strn_table + this->sym_name_offset));
    this->sym_name[name_length] = '\0';
    this->sym_file = file_name;
    
    SCSection *gnu_version = sl->getSectionByName(".gnu.version");
    this->sym_version = gnu_version->getVersionNumber(this->sym_index);
    this->sym_version_name = vl->getVersionName(this->sym_version);
}

void SCSymbolListDYN::init(SCFileDYN &file, SCSectionList *sl)
{
    Elf32_Sym *cur_sym;
    Elf32_Shdr *dynsym_table_dr;
    UINT8 *dynsym_strn_table;
    UINT8 *file_name;
    
    dynsym_table_dr = file.getDynsymTableDr();
    dynsym_strn_table = file.getDynsymStrnTable();
    file_name = file.getFileName();
    
    SCVersionList vl;
    vl.init(sl);
    
    for (int i = 0; i < dynsym_table_dr->sh_size / dynsym_table_dr->sh_entsize; i++) {
        cur_sym = file.getDynsymTable() + i;
        SCSymbolDYN *sym = new SCSymbolDYN(cur_sym, i);
        sym->init(dynsym_strn_table, sl, file_name, &vl);
        this->dynsym_list.push_back(sym);
    }
}

void SCSymbolListDYN::testSymbolList()
{
    vector<SCSymbolDYN*>::iterator it;
    for (it = this->dynsym_list.begin() + 2; it != this->dynsym_list.end(); ++it) {
        cout << (*it)->getSymbolIndex() << "  " << (*it)->sym_name << "  "
            << hex << (*it)->sym_value << "  " << (*it)->sym_version << " " << endl;
        //cout << (*it)->sym_version_name << " ";
        //cout << (*it)->sym_file << endl;
    }
}

void SCSymbolListDYN::make(SCSymbolListREL *obj_sym_list, SCSymbolListDYN *so_sym_list)
{
    vector<SCSymbol*>::iterator it;
    vector<SCSymbolDYN*>::iterator dit;
    int index = 0;
    
    for (dit = so_sym_list->dynsym_list.begin(); dit != so_sym_list->dynsym_list.end(); ++dit) {
        for (it = obj_sym_list->sym_list.begin(); it != obj_sym_list->sym_list.end(); ++it) {
            SCSymbolDYN *sym;
            if (!strcmp((const char *)(*it)->getSymbolName(), (const char *)(*dit)->getSymbolName()) && 
                    (*it)->getSymbolSdType() == SYM_LOCAL) {
                sym = new SCSymbolDYN(*it);
                
                if ((*it)->getSymbolIndex() == 0) {
                    (*it)->setSymbolSdType(SYM_OUT);
                    
                    sym->setSymbolSdType(SYM_OUT);
                    sym->setSymbolIndex(index++);
                    this->dynsym_list.push_back(sym);
                    break;
                }
                
                if ((*it)->getSymbolShndx() != SHN_UNDEF) {
                    (*it)->setSymbolSdType(SYM_OUT);
                    
                    sym->setSymbolSdType(SYM_OUT);
                    sym->setSymbolVersion(1);
                }
                else if ((*dit)->getSymbolType() == STT_FUNC || (*dit)->getSymbolType() == STT_GNU_IFUNC) {
                    (*it)->setSymbolSdType(SYM_PLT);
                    
                    sym->setSymbolSdType(SYM_PLT);
                    sym->setSymbolVersion((*dit)->getSymbolVersion());
                    sym->setSymbolVersionName((*dit)->getSymbolVersionName());
                    sym->setSymbolFile((*dit)->getSymbolFile());
                }
                else {
                    (*it)->setSymbolSdType(SYM_GOT);
                    
                    sym->setSymbolSdType(SYM_GOT);
                    sym->setSymbolVersion((*dit)->getSymbolVersion());
                    sym->setSymbolVersionName((*dit)->getSymbolVersionName());
                    sym->setSymbolFile((*dit)->getSymbolFile());
                }
                
                sym->setSymbolIndex(index++);
                this->dynsym_list.push_back(sym);
                break;
            }
        }
    }
}
