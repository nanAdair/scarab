/*
 * =====================================================================================
 *
 *       SCFilename:  symbol.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2014 04:19:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <vector>
#include <stdlib.h>
#include <elf.h>
#include "file.h"
#include "type.h"
#include "section.h"
#include "version.h"

class SCSection;
class SCVersionDef;
class SCVersionList;
class SCRelocation;
class SCRelocationList;

#define SYM_LOCAL 1
#define SYM_GOT (1 << 1)
#define SYM_PLT (1 << 2)
#define SYM_OUT (1 << 3)

class SCSymbol
{
    public:
        friend class SCSymbolListREL;
        friend class SCSymbolListDYN;
        
        SCSymbol(Elf32_Sym *sym, UINT32 index) :
            sym_name_offset(sym->st_name),
            sym_value(sym->st_value),
            sym_size(sym->st_size),
            sym_type(sym->st_info & 0xf),
            sym_binding(sym->st_info >> 0x4),
            sym_other(sym->st_other),
            sym_shndx(sym->st_shndx),
            sym_index(index),
            sym_name(NULL),
            sym_sec(NULL),
            sym_sd_type(SYM_LOCAL) {}
        
        void
        init(UINT8 *, SCSectionList *, SCSectionList *);
        
        UINT8 *
        getSymbolName()
        { return this->sym_name; }
        
        int 
        getSymbolSdType()
        { return this->sym_sd_type; }
        
        UINT16
        getSymbolShndx()
        { return this->sym_shndx; }
        
        UINT8 
        getSymbolType()
        { return this->sym_type; }
        
        UINT32
        getSymbolIndex()
        { return this->sym_index; }
        
        int
        getSymbolSDType()
        { return this->sym_sd_type; }

        void
        addSymbolSdType(int sd)
        //{ this->sym_sd_type = (int)this->sym_sd_type | sd; }
        { this->sym_sd_type |= sd; }
        
        void
        delSymbolSdType(int sd)
        //{ this->sym_sd_type = this->sym_sd_type & (int)~sd; }
        { this->sym_sd_type &= ~sd; }
        
        void
        setSymbolType(UINT8 type)
        { this->sym_type = type; }
        
        void 
        setSymbolIndex(int index)
        { this->sym_index = index; }
        
    protected:
        SCSymbol(const SCSymbol &sym):
            sym_name_offset(sym.sym_name_offset),
            sym_value(sym.sym_value),
            sym_size(sym.sym_size),
            sym_type(sym.sym_type),
            sym_binding(sym.sym_binding),
            sym_other(sym.sym_other),
            sym_shndx(sym.sym_shndx),
            sym_index(sym.sym_index),
            sym_sd_type(sym.sym_sd_type),
            sym_sec(sym.sym_sec)
    {
        int name_length = strlen((const char*)sym.sym_name);
        this->sym_name = (UINT8 *)malloc(name_length + 1);
        strcpy((char *)this->sym_name, (const char*)sym.sym_name);
        this->sym_name[name_length] = '\0';
    }

        SCSymbol& operator=(const SCSymbol&);
        
        UINT32 sym_name_offset;
        UINT32 sym_value;
        UINT32 sym_size;
        UINT8  sym_type;
        UINT32 sym_binding;
        UINT8  sym_other;
        UINT16 sym_shndx;
        UINT32 sym_index;
        UINT8 *sym_name;
        SCSection *sym_sec;
        int sym_sd_type;
};

class SCSymbolDYN : public SCSymbol
{
    public:
        friend class SCSymbolListDYN;
        SCSymbolDYN(SCSymbol *sym):
            SCSymbol(*sym),
            sym_version(0),
            sym_version_name(NULL),
            sym_file(NULL) {}
        
        SCSymbolDYN(Elf32_Sym *sym, UINT32 index) :
            SCSymbol(sym, index),
            sym_version(0),
            sym_version_name(NULL),
            sym_file(NULL) {}
        
        void
        init(UINT8 *, SCSectionList *, UINT8 *, SCVersionList *);
        
        UINT16
        getSymbolVersion()
        { return this->sym_version; }
        
        UINT8 *
        getSymbolVersionName()
        { return this->sym_version_name; }
        
        UINT8 * 
        getSymbolFile()
        { return this->sym_file;}
        
        void
        setSymbolVersion(UINT16 num)
        { this->sym_version = num; }

        void
        setSymbolVersionName(UINT8 *vn)
        { this->sym_version_name = vn; }
        
        void 
        setSymbolFile(UINT8 *file)
        { this->sym_file = file;}
    

    private:
        UINT16 sym_version;
        UINT8 *sym_version_name;
        UINT8 *sym_file;
};

class SCSymbolListREL
{
    public:
        friend class SCSymbolListDYN;
        
        void
        init(SCFileREL&, SCSectionList *, SCSectionList *);
        
        SCSymbol*
        getSymbolByName(const char*);
        
        SCSymbol*
        getSymbolByIndex(int);
        
        void
        testSymbolList();

    private:
        vector<SCSymbol*> sym_list;
};

class SCSymbolListDYN
{
    public:
        void
        init(SCFileDYN&, SCSectionList *);

        void
        make(SCSymbolListREL *, SCSymbolListDYN *, SCRelocationList *);
        
        SCSymbolDYN*
        getSymbolByName(const char*);
        
        SCSymbolDYN*
        getSymbolByIndex(int);
        
        void
        testSymbolList();
        
    private:
        void markDynSymbol(SCSymbolListREL *, SCSymbolListDYN *);
        void addGOTPLTForRelocations(SCSymbolListREL *, SCRelocationList *);
        
        vector<SCSymbolDYN*> dynsym_list;
};

#endif
