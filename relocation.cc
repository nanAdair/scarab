/*
 * =====================================================================================
 *
 *       Filename:  relocation.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2014 03:21:58 PM
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
#include "relocation.h"

void SCRelocationList::init(SCFileREL &file, SCSectionList *sec_list, SCSectionList *merge_list, SCSymbolListREL *sym_list)
{
    for (int i = 0; i < file.getRelNum(); i++) {
        Elf32_Shdr *rel_sec_dr;
        rel_sec_dr = file.getSectionTable() + file.getRelIndex()[i];
        int rel_entry_number = rel_sec_dr->sh_size / sizeof(Elf32_Rel);
        Elf32_Rel *rel_table = (Elf32_Rel *)(file.getFileData() + rel_sec_dr->sh_offset);
        
        for (int j = 0; j < rel_entry_number; j++) {
            SCRelocation *rel = new SCRelocation(rel_table + j);
            
            SCSection *sec;
            sec = sec_list->getSectionByIndex(rel_sec_dr->sh_info);
            if (sec) 
                rel->setRelSection(sec);
            else {
                sec = sec_list->getSectionByIndex(rel_sec_dr->sh_info);
                rel->setRelSection(sec->getMergetoSection());
                rel->setRelOffset(rel->getRelOffset() + sec->getSecDelta());
            }
            
            rel->setRelSymbol(sym_list->getSymbolByIndex((rel_table + j)->r_info >> 8));
            this->rel_list.push_back(rel);
        }
    }
}

void SCRelocationList::applyRelocations(SCSectionList *sec_list, SCSymbolListDYN *sym_list)
{
    vector<SCRelocation*>::iterator it;
    for (it = this->rel_list.begin(); it != this->rel_list.end(); ++it) {
        switch((*it)->getRelType()) {
            case R_386_NONE:
                break;
            case R_386_32:
                (*it)->applyRelocation_32(sym_list);
                break;
            case R_386_PC32:
                (*it)->applyRelocation_PC32(sec_list, sym_list);
                break;
            case R_386_GOTPC:
                (*it)->applyRelocation_GOTPC();
                break;
            case R_386_GOTOFF:
                (*it)->applyRelocation_GOTOFF(sec_list);
                break;
            case R_386_GOT32:
                (*it)->applyRelocation_GOT32(sec_list, sym_list);
                break;
            case R_386_PLT32:
                (*it)->applyRelocation_PLT32(sec_list, sym_list);
                break;
            default:
                cout << "error can't handle the relocation type\n" << endl;
                return;
        }
    }
}

void SCRelocationList::testRelocationList()
{
    vector<SCRelocation*>::iterator it;
    
    for (it = this->rel_list.begin(); it != this->rel_list.end(); ++it) {
        cout << hex << (*it)->getRelOffset() << "  " << (int)(*it)->getRelType() << "  "
            << (*it)->getRelSection()->getSecName() << "  "
            << (*it)->getRelSymbol()->getSymbolName() << " ";
        cout << (*it)->getRelValue() ;
        
        cout << endl;
    }
}

int SCRelocation::getAddend()
{
    SCSection *sec = this->rel_sec;
    int addend, value;
    int *buffer;
    buffer = (int *)malloc(sizeof(int));
    memcpy(buffer, sec->getSecData() + this->rel_offset, sizeof(int));
    addend = *buffer;
    free(buffer);
    
    return addend;
}

/* rel_value stores the real target
 * and value stores the calculated target*/

void SCRelocation::applyRelocation_32(SCSymbolListDYN *sym_list)
{
    int addend, value;
    addend = this->getAddend();
    
    if (this->rel_sym->getSymbolSdType() & SYM_GOT) {
        cout << "error handling R_386_32 when the symbol is got " << endl;
    }
    else {
        this->rel_value = this->rel_sym->getSymbolValue();
        value = this->rel_value + addend;
    }
    
    this->rel_sec->setSecContent(this->rel_offset, (char *)&value, sizeof(int));
}

void SCRelocation::applyRelocation_PC32(SCSectionList *sl, SCSymbolListDYN *sym_list)
{
    int addend, value;
    addend = this->getAddend();
    
    if (this->rel_sym->getSymbolSdType() & SYM_PLT) {
        SCSection *plt = sl->getSectionByName(PLT_SECTION_NAME);
        
        this->rel_value = this->rel_sym->getSymbolOffsetPLT(sym_list) + plt->getSecAddress();
        value = (int)this->rel_value + addend - (this->rel_sec->getSecAddress() + this->rel_offset);
    }
    else {
        this->rel_value = this->rel_sym->getSymbolValue();
        value = (int)this->rel_value + addend - (this->rel_sec->getSecAddress() + this->rel_offset);
    }

    this->rel_sec->setSecContent(this->rel_offset, (char *)&value, sizeof(int));
}

void SCRelocation::applyRelocation_GOTPC()
{
    int addend, value;
    addend = this->getAddend();
    
    this->rel_value = this->rel_sym->getSymbolValue();
    value = (int)this->rel_value + addend - (this->rel_sec->getSecAddress() + this->rel_offset);
    
    this->rel_sec->setSecContent(this->rel_offset, (char *)&value, sizeof(int));
}

void SCRelocation::applyRelocation_GOTOFF(SCSectionList *sl)
{
    int value;
    SCSection *gotplt = sl->getSectionByName(GOT_PLT_SECTION_NAME);
    
    this->rel_value = this->rel_sym->getSymbolValue();
    value = (int)this->rel_value - gotplt->getSecAddress();
    
    this->rel_sec->setSecContent(this->rel_offset, (char *)&value, sizeof(int));
}

void SCRelocation::applyRelocation_GOT32(SCSectionList *sl, SCSymbolListDYN *sym_list)
{
    int value;
    SCSection *gotplt = sl->getSectionByName(GOT_PLT_SECTION_NAME);
    
    this->rel_value = gotplt->getSecAddress() + this->rel_sym->getSymbolOffsetGOT(sym_list);
    value = this->rel_value - gotplt->getSecAddress();
    
    this->rel_sec->setSecContent(this->rel_offset, (char *)&value, sizeof(int));
}

/* Operation is the same as PC32
 * Note: the symbol of PLT32 may not be of SYM_PLT type*/
void SCRelocation::applyRelocation_PLT32(SCSectionList *sl, SCSymbolListDYN *sym_list)
{
    this->applyRelocation_PC32(sl, sym_list);
}
