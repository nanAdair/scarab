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

void SCRelocationList::testRelocationList()
{
    vector<SCRelocation*>::iterator it;
    
    for (it = this->rel_list.begin(); it != this->rel_list.end(); ++it) {
        cout << hex << (*it)->getRelOffset() << "  " << (int)(*it)->getRelType() << "  "
            << (*it)->getRelSection()->getSecName() << "  "
            << (*it)->getRelSymbol()->getSymbolIndex() << endl;
    }
}
