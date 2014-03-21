/*
 * =====================================================================================
 *
 *       Filename:  section.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 03:13:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "section.h"

void SCSection::init(UINT8 *file_data, UINT8 *sec_strn_table)
{
    int name_length = strlen((const char *)(sec_strn_table + this->sec_name_offset));
    this->sec_name = (UINT8 *)malloc(name_length + 1);
    strcpy((char *)this->sec_name, (const char *)(sec_strn_table + this->sec_name_offset));
    this->sec_name[name_length] = '\0';

    this->sec_data = (UINT8 *)malloc(this->sec_datasize);
    memcpy(this->sec_data, file_data + this->sec_file_offset, this->sec_datasize);
}

SCSection *SCSection::mergeSection(SCSection *sec)
{
    UINT8 *buffer;
    int addition, target_datasize, source_datasize, target_newdatasize;
    target_datasize = this->sec_datasize;
    source_datasize = sec->sec_datasize;
    
    UINT32 source_align = sec->sec_align;
    addition = 0;
    while ((target_datasize + addition) % source_align != 0)
        addition++;
    target_newdatasize = target_datasize + addition + source_datasize;
    
    buffer = (UINT8 *)malloc(target_newdatasize);
    memset(buffer, 0x0, target_newdatasize);
    memcpy(buffer, this->sec_data, target_datasize);
    memcpy(buffer + target_datasize + addition, sec->sec_data, source_datasize);
    
    free(this->sec_data);
    this->sec_data = buffer;
    this->sec_datasize = target_newdatasize;
    this->sec_align = this->sec_align > source_align ? this->sec_align : source_align;
    
    sec->sec_mergeto = this;
    sec->sec_delta = target_datasize + addition;
    
    return sec;
}

int SCSection::getDynamicAttributeData(int tag) const
{
    int i, number;
    number = this->sec_datasize / this->sec_entsize;
    
    for (i = 0; i < number; i++) {
        Elf32_Dyn *cur_dyn;
        cur_dyn = (Elf32_Dyn *)(this->sec_data + this->sec_entsize * i);
        if (cur_dyn->d_tag == tag) {
            return cur_dyn->d_un.d_val;
        }
    }
}

void SCSectionList::init(SCFile &file)
{
    Elf32_Shdr *cur_sec_dr;
    UINT8 *sec_strn_table, *file_data;
    
    sec_strn_table = file.getSectionStrnTable();
    file_data = file.getFileData();
    SCSection *sec;
    
    for (int i = 0; i < file.getSectionNumber(); i++) {
        cur_sec_dr = file.getSectionTable() + i;
        sec = new SCSection(cur_sec_dr, i);
        sec->init(file_data, sec_strn_table);
        this->sec_list.push_back(sec);
    }
}

SCSection* SCSectionList::getSectionByName(const char *name)
{
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        UINT8 *sec_name = (*it)->getSecName();
        if (!strcmp((const char*)sec_name, name))
            return *it;
    }
    
    return NULL;
}

SCSection *SCSectionList::getSectionByIndex(const int index)
{
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        if ((*it)->getSecIndex() == index)
            return *it;
    }
    
    return NULL;
}

void SCSectionList::mergeSections(SCSectionList *sl)
{
    int i = 0;
    SCSection *text;
    text = sl->getSectionByName(".text");
    
    vector<SCSection*>::iterator it;
    for (it = sl->sec_list.begin(); it != sl->sec_list.end(); ++it) {
        SCSection *cur_sec, *last_sec;
        if ((*it)->sec_flags & SHF_MERGE) {
            if (!strcmp((const char *)(*it)->sec_name, ".comment")) {
                continue;
            }
            else {
                SCSection *sec = (*(it-1))->mergeSection(*it);
                this->sec_list.push_back(*it);
                sl->sec_list.erase(it);
            }
        }
        
        if ((*it)->sec_flags & SHF_EXECINSTR && !this->skipXSection((*it)->sec_name)) {
            SCSection *sec = text->mergeSection(*it);
            this->sec_list.push_back(*it);
            sl->sec_list.erase(it);
        }
    }
}

bool SCSectionList::skipXSection(UINT8 *name)
{
    const char *sec_name[] = {
        ".text",
        ".init",
        ".fini"
    };
    
    for (int i = 0; i < 3; i++) {
        if (!strcmp((const char *)name, sec_name[i]))
            return 1;
    }
    
    return 0;
}

void SCSectionList::testSectionList()
{
    int i = 0;
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        cout << (*it)->sec_init_index << "  " << (*it)->getSecName() << "  " << 
            (*it)->sec_datasize << "  " << hex << (*it)->sec_file_offset << endl;
    }
}


