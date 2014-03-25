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

class SCSymbol;
class SCFileREL;

class SCRelocation
{
    public:
        SCRelocation(Elf32_Rel *rel) :
            rel_offset(rel->r_offset),
            rel_type(rel->r_info & 0xff) {}
        
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

        
    private:
        UINT32 rel_offset;
        UINT8  rel_type;
        SCSymbol *rel_sym;
        SCSection *rel_sec;
};

class SCRelocationList
{
    public:
        void
        init(SCFileREL&, SCSectionList *, SCSectionList *, SCSymbolListREL *);
        
        void 
        testRelocationList();
        
        vector<SCRelocation*>*
        getRelList()
        { return &(this->rel_list); }
    
    private:
        vector<SCRelocation*> rel_list;
};

#endif
