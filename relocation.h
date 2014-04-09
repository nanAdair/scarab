/*
 * =====================================================================================
 *
 *       Filename:  relocation.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2014 04:40:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef RELOCATION_H
#define RELOCATION_H

#include <vector>
#include <elf.h>
#include "type.h"
#include "section.h"
#include "symbol.h"
#include "file.h"

class SCSectionList;
class SCSection;
class SCSymbol;
class SCFileREL;

class SCRelocation
{
    public:
        friend class SCRelocationList;
        SCRelocation(Elf32_Rel *rel) :
            rel_offset(rel->r_offset),
            rel_type(rel->r_info & 0xff),
            rel_value(0),
            rel_addend(0) {}
        
        UINT32
        getRelOffset()
        { return this->rel_offset; }
        
        UINT8 
        getRelType()
        { return this->rel_type; }
        
        SCSection *
        getRelSection()
        { return this->rel_sec; }
        
        SCSymbol *
        getRelSymbol()
        { return this->rel_sym; }
        
        UINT32
        getRelValue()
        { return this->rel_value; }
        
        INT32 
        getRelAddend()
        { return this->rel_addend; }

        void
        setRelOffset(UINT32 offset)
        { this->rel_offset = offset; }
        
        void
        setRelType(UINT8 type)
        { this->rel_type = type; }
        
        void
        setRelSection(SCSection *sec)
        { this->rel_sec = sec; }
        
        void 
        setRelSymbol(SCSymbol *sym)
        { this->rel_sym = sym; }
        
        void
        setRelValue(UINT32 value)
        { this->rel_value = value; }
        
        void
        setRelAddend(INT32 addend)
        { this->rel_addend = addend; }
        
    private:
        UINT32 rel_offset;
        UINT8  rel_type;
        SCSymbol *rel_sym;
        SCSection *rel_sec;
        UINT32 rel_value;
        INT32 rel_addend;
        
        int
        getAddend();
        
        void
        applyRelocation_32(SCSymbolListDYN *);
        
        void
        applyRelocation_PC32(SCSectionList *, SCSymbolListDYN *);
        
        void
        applyRelocation_GOTPC();
        
        void
        applyRelocation_GOTOFF(SCSectionList *);
        
        void
        applyRelocation_GOT32(SCSectionList *, SCSymbolListDYN *);
        
        void
        applyRelocation_PLT32(SCSectionList *, SCSymbolListDYN *);
        
};

class SCRelocationList
{
    public:
        void
        init(SCFileREL&, SCSectionList *, SCSectionList *, SCSymbolListREL *);
        
        void 
        testRelocationList();
        
        void
        applyRelocations(SCSectionList *, SCSymbolListDYN *);
        
        vector<SCRelocation*>*
        getRelList()
        { return &(this->rel_list); }
    
    private:
        vector<SCRelocation*> rel_list;
};

#endif
