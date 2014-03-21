/*
 * =====================================================================================
 *
 *       SCFilename:  file.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2014 02:45:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef FILE_H
#define FILE_H

#include <elf.h>
#include <vector>
#include "type.h"

class SCFile 
{
    public:
        enum BINARY_TYPE {
            BINARY_CORE_TYPE,
            BINARY_SHARED_TYPE,
            BINARY_RELOCATABLE_TYPE,
            BINARY_EXECUTABLE_TYPE
        };

        SCFile() {}
        
        virtual void
        init(char *file_name) = 0;
        
        /* Fill the attributes of SCFile class */
        void
        initFilePart(char *);
        
        Elf32_Ehdr*
        getFileHeader() const
        { return this->file_header; }
        
        Elf32_Shdr*
        getSectionTable() const
        { return this->section_table; }
        
        UINT8*
        getSectionStrnTable() const
        { return this->section_strn_table; }
        
        UINT8*
        getFileData() const
        { return this->file_data; }
        
        UINT32
        getFileSize() const
        { return this->file_size; }
        
        BINARY_TYPE 
        getFileType () const
        { return this->file_type; }
        
        UINT32 
        getSectionNumber () const
        { return this->section_number; }
        
        UINT8 *
        getFileName() const
        { return this->file_name; }
        
        void
        testSectionTable() const;
    
    protected:
        Elf32_Ehdr *file_header;
        Elf32_Shdr *section_table;
        UINT8 *section_strn_table;
        UINT8 *file_data;
        UINT32 file_size;
        BINARY_TYPE file_type;
        UINT32 section_number;
        UINT8 *file_name;
        
    private:
        SCFile(const SCFile&);
        SCFile& operator=(const SCFile&);
        
        void
        fillFilePartContent();
};

class SCFileREL : public SCFile
{
    public:
        SCFileREL(): rel_num(0) {}
        
        void 
        init(char *file_name);
        
        Elf32_Shdr*
        getSymTableDr() const
        { return this->sym_table_dr; }
        
        UINT8*
        getSymStrnTable() const
        { return this->sym_strn_table; }
        
        Elf32_Sym* 
        getSymTable() const 
        { return this->sym_table; }
        
        vector<UINT32>
        getRelIndex() const
        { return this->rel_index; }
        
        UINT32
        getRelNum() const
        { return this->rel_num; }
        
        void 
        testRelIndex() const;
        
        void
        testSymTable() const;

    private:
        Elf32_Shdr* sym_table_dr;
        UINT8* sym_strn_table;
        Elf32_Sym* sym_table;
        vector<UINT32> rel_index;
        UINT32 rel_num;
};

class SCFileDYN : public SCFile
{
    public:
        void
        init(char *file_name);
        
        Elf32_Shdr*
        getDynsymTableDr() const
        { return this->dynsym_table_dr; }
        
        UINT8*
        getDynsymStrnTable() const
        { return this->dynsym_strn_table; }
        
        Elf32_Sym*
        getDynsymTable() const
        { return this->dynsym_table; }
        
        void
        testDynsymTable() const;

    private:
        Elf32_Shdr* dynsym_table_dr;
        UINT8* dynsym_strn_table;
        Elf32_Sym* dynsym_table;
};

//class SCFile_EXEC : public SCFile
//{
//};

#endif
