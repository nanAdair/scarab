/*
 * =====================================================================================
 *
 *       SCFilename:  section.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2014 03:41:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SECTION_H
#define SECTION_H

#include <vector>
#include <string>
#include "type.h"
#include "file.h"

class SCFile;
class SCFileOBJ;
class SCFileDYN;

class SCSection
{
    public:
        friend class SCSectionList;
        SCSection() : sec_delta(0), sec_misc(0), sec_name(NULL),sec_data(NULL) {}
        
        /* Construct a section from the section descriptor */
        SCSection(Elf32_Shdr *cur_sec_dr, UINT16 index) : 
            sec_name_offset(cur_sec_dr->sh_name), 
            sec_type(cur_sec_dr->sh_type),
            sec_flags(cur_sec_dr->sh_flags),
            sec_address(cur_sec_dr->sh_addr),
            sec_file_offset(cur_sec_dr->sh_offset),
            sec_datasize(cur_sec_dr->sh_size),
            sec_link(cur_sec_dr->sh_link),
            sec_info(cur_sec_dr->sh_info),
            sec_align(cur_sec_dr->sh_addralign),
            sec_entsize(cur_sec_dr->sh_entsize),
            sec_init_index(index),
            sec_final_index(0),
            sec_misc(index),
            sec_delta(0), sec_name(NULL), sec_data(NULL) {}

        /* Fill the remained attributes */
        void
        init(UINT8 *, UINT8 *);
        
        /* Merge two sections, add the content of the parameter to the caller */
        SCSection *
        mergeSection(SCSection *);
        
        UINT8*
        getSecData() const
        { return this->sec_data; }
        
        UINT32 
        getSecAddress() const
        { return this->sec_address; }

        UINT8*
        getSecName() const
        { return this->sec_name; }
        
        UINT32
        getSecIndex() const
        { return this->sec_final_index == 0 ? this->sec_init_index : this->sec_final_index; }
        
        SCSection *
        getMergetoSection() const
        { return this->sec_mergeto; }
        
        UINT32
        getSecDelta() const
        { return this->sec_delta; }
        
        /* return one .gnu.version item based on the offset*/
        UINT16
        getVersionNumber(int offset) const
        { return this->sec_data[this->sec_entsize * offset]; }
        
        int
        getDynamicAttributeData(int) const;

    private:
        UINT32 sec_name_offset;
        UINT32 sec_type;
        UINT32 sec_flags;
        UINT32 sec_address;
        UINT32 sec_file_offset;
        UINT32 sec_datasize;
        UINT32 sec_link;
        UINT32 sec_info;
        UINT32 sec_align;
        UINT32 sec_entsize;
        UINT16 sec_init_index;
        UINT16 sec_final_index;
        UINT32 sec_delta;
        UINT32 sec_misc;
        SCSection *sec_mergeto;
        UINT8 *sec_name;
        UINT8 *sec_data;
        
        SCSection(const SCSection&);
        SCSection& operator=(const SCSection&);
};

class SCSectionList
{
    public:
        /* Construct a vector of section*s */
        void
        init(SCFile&);
        
        SCSection*
        getSectionByName(const char*);
        
        SCSection*
        getSectionByIndex(const int index);
        
        /* Generate a vector of merged sections from a section list*/
        void
        mergeSections(SCSectionList *);
        
        void 
        testSectionList();
        
    private:
        vector<SCSection*> sec_list;
        
        /* Skip the specified section */
        bool
        skipXSection(UINT8 *);
};

#endif
