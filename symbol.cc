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
#include "relocation.h"

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

void SCSymbol::setSymbolValue(int addend)
{ 
    this->sym_value = this->sym_value + this->sym_sec->getSecAddress() + addend; 
}

int SCSymbol::getSymbolOffsetPLT(SCSymbolListDYN *sym_list)
{
    int index, i;
    i = 0;
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if ((*it)->getSymbolSdType() & SYM_PLT)
            i++;
        if (!strcmp((char *)this->sym_name, (char *)(*it)->getSymbolName())) {
            index = i;
            break;
        }
    }

    return 0x10 * index;
}

void SCSymbol::handleCOMMON(SCSectionList *sl)
{
    SCSection *bss = sl->getSectionByName(".bss");
    int addition, datasize, newdatasize, sym_size;
    UINT32 align;
    addition = 0;
    datasize = bss->getSecDatasize();
    sym_size = this->sym_size;
    
    align = bss->getSecAlign();
    align = sym_size > align ? sym_size : align;
    while ((datasize + addition) % align != 0)
        addition++;
    newdatasize = datasize + addition + sym_size;
    
    bss->setSecDatasize(newdatasize);
    bss->setSecAlign(align);
    this->sym_value = datasize + addition;
    this->sym_sec = bss;
}


/* i: GOT number
 * index: symbol index in got start from 1
 * return value: -4 * (i - index + 1)*/
int SCSymbol::getSymbolOffsetGOT(SCSymbolListDYN *sym_list)
{
    int i, index;
    i = 0;
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if ((*it)->getSymbolSdType() & SYM_GOT)
            i++;
        if (!strcmp((char *)this->sym_name, (char *)(*it)->getSymbolName())) 
            index = i;
    }

    return (-4) * (i - index + 1);
}

// ========== SCSymbolListREL ==========

static SCSymbolListREL* _sharedSCSymListREL = NULL;

SCSymbolListREL* SCSymbolListREL::sharedSymListREL() {
    if (_sharedSCSymListREL == NULL) {
        _sharedSCSymListREL = new SCSymbolListREL();
    }
    return _sharedSCSymListREL;
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
        if (sym->getSymbolShndx() == SHN_COMMON)
            sym->handleCOMMON(sl);
        this->sym_list.push_back(sym);
    }
}

SCSymbol *SCSymbolListREL::getSymbolByName(const char *name)
{
    vector<SCSymbol*>::iterator it;
    for (it = this->sym_list.begin(); it != this->sym_list.end(); ++it) {
        if (!strcmp((const char *)(*it)->getSymbolName(), name))
            return *it;
    }
}

SCSymbol *SCSymbolListREL::getSymbolByIndex(int index)
{
    vector<SCSymbol*>::iterator it;
    for (it = this->sym_list.begin(); it != this->sym_list.end(); ++it) {
        if ((*it)->getSymbolIndex() == index)
            return *it;
    }
}

/* update the symbol value and symbol shndx infomation */
void SCSymbolListREL::updateSymbolValue(SCSectionList *sl)
{
    vector<SCSymbol*>::iterator it;
    for (it = this->sym_list.begin(); it != this->sym_list.end(); ++it) {
        if ((*it)->getSymbolShndx() != SHN_ABS && (*it)->getSymbolShndx() != SHN_UNDEF){
            (*it)->setSymbolValue(0);
            (*it)->setSymbolShndx((*it)->getSymbolSec()->getSecIndex());
        }
        /* handle the special symbols here */
        else {
            if (!strcmp((char *)(*it)->getSymbolName(), INIT_ARRAY_START)) {
                SCSection *init_array = sl->getSectionByName(INIT_ARRAY_SECTION_NAME);
                (*it)->setSymbolSec(init_array);
                (*it)->setSymbolValue(0);
                (*it)->setSymbolShndx((*it)->getSymbolSec()->getSecIndex());
            }
            else if (!strcmp((char *)(*it)->getSymbolName(), INIT_ARRAY_END)) {
                SCSection *init_array = sl->getSectionByName(INIT_ARRAY_SECTION_NAME);
                (*it)->setSymbolSec(init_array);
                (*it)->setSymbolValue(init_array->getSecDatasize());
                (*it)->setSymbolShndx((*it)->getSymbolSec()->getSecIndex());
            }
            else if (!strcmp((char *)(*it)->getSymbolName(), GOT_SYMBOL_NAME)) {
                SCSection *gotplt = sl->getSectionByName(GOT_PLT_SECTION_NAME);
                (*it)->setSymbolSec(gotplt);
                (*it)->setSymbolValue(0);
                (*it)->setSymbolShndx((*it)->getSymbolSec()->getSecIndex());
            }
        }
    }
}

void SCSymbolListREL::updateSymbolSection(SCSection *symtab)
{
    int number = symtab->getSecDatasize() / symtab->getSecEntsize();
    
    vector<SCSymbol*>::iterator it;
    it = this->sym_list.begin();
    
    for (int i = 0; i < number; i++) {
        Elf32_Sym *cur_sym;
        cur_sym = (Elf32_Sym *)(symtab->getSecData() + i * symtab->getSecEntsize());
        
        cur_sym->st_name = (*it)->getSymbolNameOffset();
        cur_sym->st_value = (*it)->getSymbolValue();
        cur_sym->st_size = (*it)->getSymbolSize();
        cur_sym->st_info = ((*it)->getSymbolBinding() << 4) + (*it)->getSymbolType();
        cur_sym->st_other = (*it)->getSymbolOther();
        cur_sym->st_shndx = (*it)->getSymbolShndx();
        
        ++it;
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

SymListRELT SCSymbolListREL::getFunSymList() {
    SymListRELT funSyms;
    for(SymIterRELT it=sym_list.begin(); it!=sym_list.end(); ++it) {
        if ((*it)->getSymbolType() == STT_FUNC) {
            funSyms.push_back(*it);
        }
    }
    return funSyms;
}

const char* SCSymbolListREL::getSymNameByAddr(UINT32 addr) {
    for(SymIterRELT it=sym_list.begin(); it!=sym_list.end(); ++it) {
        if ((*it)->getSymbolValue() == addr)
            return (char*)((*it)->getSymbolName());
    }
    return "";
}

// ========== SCSymbolDYN ==========

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

SCSymbolDYN *SCSymbolListDYN::getSymbolByName(const char *name)
{
    vector<SCSymbolDYN*>::iterator it;
    for (it = this->dynsym_list.begin(); it != this->dynsym_list.end(); ++it) {
        if (!strcmp((const char *)(*it)->getSymbolName(), name))
            return *it;
    }
    return NULL;
}

SCSymbolDYN *SCSymbolListDYN::getSymbolByIndex(int index)
{
    vector<SCSymbolDYN*>::iterator it;
    for (it = this->dynsym_list.begin(); it != this->dynsym_list.end(); ++it) {
        if ((*it)->getSymbolIndex() == index)
            return *it;
    }
    return NULL;
}
void SCSymbolListDYN::testSymbolList()
{
    vector<SCSymbolDYN*>::iterator it;
    for (it = this->dynsym_list.begin(); it != this->dynsym_list.end(); ++it) {
        cout << (*it)->getSymbolIndex() << "  " << (*it)->sym_name << "  "
            << hex << (*it)->sym_value << "  " << (*it)->sym_version << " ";
        cout << (*it)->getSymbolBinding() << " ";
        cout << (*it)->getSymbolOther() << " ";
        cout << endl;
        //cout << (*it)->sym_version_name << " ";
        //cout << (*it)->sym_file << endl;
    }
}

/* mark first
 * then add the item to the vector*/
void SCSymbolListDYN::make(SCSymbolListREL *obj_sym_list, SCSymbolListDYN *so_sym_list, SCRelocationList *rel_list)
{
    this->markDynSymbol(obj_sym_list, so_sym_list);
    this->addGOTPLTForRelocations(obj_sym_list, rel_list);
    
    vector<SCSymbol*>::iterator it;
    vector<SCSymbolDYN*>::iterator dit;
    int index = 0;

    for (it = obj_sym_list->sym_list.begin(); it != obj_sym_list->sym_list.end(); ++it) {
        SCSymbolDYN *sym;
        if ((*it)->getSymbolSdType() == SYM_LOCAL)
            continue;
        
        sym = new SCSymbolDYN(*it);
        if ((*it)->getSymbolShndx() == SHN_UNDEF) {
            SCSymbolDYN *dynsym = so_sym_list->getSymbolByName((const char*)(*it)->getSymbolName());
            if (dynsym) {
                sym->setSymbolVersion(dynsym->getSymbolVersion());
                sym->setSymbolVersionName(dynsym->getSymbolVersionName());
                sym->setSymbolFile(dynsym->getSymbolFile());
            }
        }
        else
            sym->setSymbolVersion(1);
        sym->setSymbolIndex(index++);
        this->dynsym_list.push_back(sym);
    }
}
    
void SCSymbolListDYN::markDynSymbol(SCSymbolListREL *obj_sym_list, SCSymbolListDYN *so_sym_list)
{
    vector<SCSymbol*>::iterator it;
    vector<SCSymbolDYN*>::iterator dit;
    
    for (dit = so_sym_list->dynsym_list.begin(); dit != so_sym_list->dynsym_list.end(); ++dit) {
        for (it = obj_sym_list->sym_list.begin(); it != obj_sym_list->sym_list.end(); ++it) {
            if (!strcmp((const char *)(*it)->getSymbolName(), (const char *)(*dit)->getSymbolName()) && 
                    (*it)->getSymbolSdType() == SYM_LOCAL) {
                
                if ((*it)->getSymbolIndex() == 0) {
                    (*it)->addSymbolSdType(SYM_OUT);
                    (*it)->delSymbolSdType(SYM_LOCAL);
                    break;
                }
                
                if ((*it)->getSymbolShndx() != SHN_UNDEF) {
                    (*it)->addSymbolSdType(SYM_OUT);
                    (*it)->delSymbolSdType(SYM_LOCAL);
                }
                else if ((*dit)->getSymbolType() == STT_FUNC || (*dit)->getSymbolType() == STT_GNU_IFUNC) {
                    (*it)->addSymbolSdType(SYM_PLT);
                    (*it)->delSymbolSdType(SYM_LOCAL);
                    (*it)->setSymbolType((*dit)->getSymbolType());
                }
                else {
                    (*it)->addSymbolSdType(SYM_GOT);
                    (*it)->delSymbolSdType(SYM_LOCAL);
                }
                break;
            }
        }
    }
}

void SCSymbolListDYN::addGOTPLTForRelocations(SCSymbolListREL *symList, SCRelocationList *relList)
{
    vector<SCRelocation*> *rel_list = relList->getRelList();
    vector<SCRelocation*>::iterator it;
    
    for (it = rel_list->begin(); it != rel_list->end(); ++it) {
        SCSymbol *sym;
        if ((*it)->getRelType() == R_386_GOT32) {
            sym = (*it)->getRelSymbol();
            if (sym->getSymbolShndx() != SHN_UNDEF)
                continue;
            if (!(sym->getSymbolSdType() & SYM_GOT))
                sym->addSymbolSdType(SYM_GOT);
        }
        if ((*it)->getRelType() == R_386_PLT32) {
            sym = (*it)->getRelSymbol();
            if (sym->getSymbolShndx() != SHN_UNDEF)
                continue;
            if (!(sym->getSymbolSdType() & SYM_PLT))
                sym->addSymbolSdType(SYM_PLT);
        }
    }
}
