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
#include "type.h"
#include "file.h"
#include "symbol.h"
#include "instr.h"

// Sections to be added
#define INTERP_SECTION_NAME     ".interp"
#define HASH_SECTION_NAME       ".hash"
#define DYNSYM_SECTION_NAME     ".dynsym"
#define DYNSTR_SECTION_NAME     ".dynstr"
#define GV_SECTION_NAME         ".gnu.version"
#define GNR_SECTION_NAME        ".gnu.version_r"
#define REL_DYN_SECTION_NAME    ".rel.dyn"
#define REL_PLT_SECTION_NAME    ".rel.plt"
#define PLT_SECTION_NAME        ".plt"
#define DYNAMIC_SECTION_NAME    ".dynamic"
#define GOT_SECTION_NAME        ".got"
#define GOT_PLT_SECTION_NAME    ".got.plt"

#define TEXT_SECTION_NAME       ".text"
#define INIT_SECTION_NAME       ".init"
#define FINI_SECTION_NAME       ".fini"
#define INIT_ARRAY_SECTION_NAME ".init_array"
#define FINI_ARRAY_SECTION_NAME ".fini_array"

#define BSS_SECTION_NAME        ".bss"
#define RODATA_SECION_NAME      ".rodata"
#define EH_FRAME_SECTION_NAME   ".eh_frame"
#define JCR_SECTION_NAME        ".jcr"
#define DATA_SECTION_NAME       ".data"
#define COMMENT_SECTION_NAME    ".comment"
#define SYMTAB_SECTION_NAME     ".symtab"
#define STRTAB_SECTION_NAME     ".strtab"

#define SHSTRTAB_SECTION_NAME   ".shstrtab"
#define NOTE_SECTION_NAME       ".note.ABI-tag"

#define DYNAMIC_NUMBER 28
#define DYNAMIC_ENTSIZE 8

class SCFile;
class SCFileOBJ;
class SCFileDYN;
class SCSymbolListDYN;
class SCSectionList;

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

        UINT32
        getSecType() const
        { return this->sec_type; }
        
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
        
        UINT32
        getSecFlags() const
        { return this->sec_flags; }
        
        UINT32
        getSecAlign() const
        { return this->sec_align; }
        
        SCSection *
        getMergetoSection() const
        { return this->sec_mergeto; }
        
        UINT32
        getSecDelta() const
        { return this->sec_delta; }
        
        UINT32
        getSecDatasize() const
        { return this->sec_datasize; }
        
        /* return one .gnu.version item based on the offset*/
        UINT16
        getVersionNumber(int offset) const
        { return this->sec_data[this->sec_entsize * offset]; }
        
        UINT32
        getSecMisc() const
        { return this->sec_misc; }

        void
        setSecName(const char *name) 
        { 
            this->sec_name = (UINT8 *)malloc(strlen((const char *)name) + 1);
            strcpy((char *)this->sec_name, (const char*)name);
            this->sec_name[strlen((const char *)name)] = '\0';
        }
        
        void
        setSecMisc(int misc)
        { this->sec_misc = misc; }

        void
        setSecAlign(int align)
        { this->sec_align = align; }

        void
        setSecAddress(int address)
        { this->sec_address = address; }
        
        void
        setSecDatasize(int datasize)
        { this->sec_datasize = datasize; }
        
        void
        setSecNameOffset(int offset)
        { this->sec_name_offset = offset; }
        
        void 
        setSecFileOffset(int offset)
        { this->sec_file_offset = offset; }

        void
        setSecInitIndex(int index)
        { this->sec_init_index = index; }
        
        void
        setSecFinalIndex(int index)
        { this->sec_final_index = index; }
        
        void
        setSecContent(int offset, char *, int);

        void 
        testSecData();
        
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
        
        /* Fill the remained attributes */
        void
        init(UINT8 *, UINT8 *);
        
        /* parameter:
         * char *data: the data to expand
         * int size: the size of data 
         * int flag: decide whether reassign the datasize, when roundup we do not
         * update this field*/
        void
        expandSecData(char *, int, int);
        
        int
        findOffset(SCSection *, char *);

        UINT32
        calculateHash(const UINT8* name);
        
        void
        addPLTTop();

        /* Merge two sections, add the content of the parameter to the caller */
        SCSection *
        mergeSection(SCSection *);
        
        void
        setInterpData(const char *ld_file);
        
        void
        setDynstrData(SCSymbolListDYN *, char **so_files, int);
        
        void
        setDynsymData(SCSymbolListDYN *);
        
        void
        setHashData(SCSymbolListDYN *);
        
        void
        setGVData(SCSymbolListDYN *);

        void
        setGNRData(SCSymbolListDYN *, char **so_files, int, SCSection *);
        
        void
        setPLTData(SCSymbolListDYN *);
        
        void
        setGOTPLTData(SCSymbolListDYN *);
        
        void
        setRELPLTData(SCSymbolListDYN *);

        void
        setGOTData(SCSymbolListDYN *);
        
        void
        setRELGOTData(SCSymbolListDYN *);

        void
        setDynamicData(int);
        
        void
        setShstrData(SCSectionList *);
        
        UINT32
        getSecOrderScore();
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
        
        vector<SCSection*> *
        getSectionList()
        { return &(this->sec_list); }
        
        /* Generate a vector of merged sections from a section list*/
        void
        mergeSections(SCSectionList *);
        
        void
        addSections(const char *ld_file, SCSymbolListDYN *dynsym_list, char *so_files[], int);

        void
        addOneXSection(Elf32_Shdr *, char *name, char *data, int datasize);
        
        void
        allocateSectionsAddress();

        void 
        testSectionList();
        
    private:
        vector<SCSection*> sec_list;
        
        /* Skip the specified section */
        bool
        skipXSection(UINT8 *);

        void
        createSections();
        
        void
        sortSections();

        SCSection*
        addOneSection(Elf32_Shdr *, char *name, char *data, int datasize);
};

#endif
