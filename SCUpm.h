/*
 * =====================================================================================
 *
 *       Filename:  SCUpm..h
 *
 *    Description:  universal patch mechanism
 *
 *        Version:  1.0
 *        Created:  04/07/14 20:38:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef SCUPM_H
#define SCUPM_H

#include "relocation.h"
#include "disasm.h"

class SCRelocation;

typedef enum {
    UPM_INSTR_MEMBER_TYPE,
    UPM_SECTION_MEMBER_TYPE,
    UPM_OFFSET_MEMBER_TYPE,
    UPM_SYMBOL_MEMBER_TYPE,
    UPM_OPERAND_MEMBER_TYPE,
    UPM_FUNCTION_MEMBER_TYPE
} UPMTYPE;

/* This is one member of a UPM */
typedef struct {
    UPMTYPE l_type;
    void *l_member;
} Location;

/* This is the source or the destination parts of a UPM */
typedef struct {
    Location *u_member;
    int u_size;
} UPMParts;

class SCPatch 
{
    public:
        virtual bool apply() = 0;
        virtual UPMParts *getSources() = 0;
        virtual UPMParts *getDestinations() = 0;
};

class PatchInstrtoInstr : public SCPatch
{
    public:
        PatchInstrtoInstr() :
            src_instr(NULL),
            src_offset(0),
            dest_instr(NULL),
            dest_offset(0) {}
        
        UPMParts *getSources();
        UPMParts *getDestinations();
        
    protected:
        SCInstr *src_instr;
        UINT32 src_offset;
        SCInstr *dest_instr;
        UINT32 dest_offset;
};

class PatchInstrtoInstr32 : public PatchInstrtoInstr
{
    public:
        PatchInstrtoInstr32() {}
        bool apply();
};

class PatchInstrtoInstrPC32 : public PatchInstrtoInstr
{
    public:
        PatchInstrtoInstrPC32() :
            addend(0) {}
        
        bool apply();
        
    private:
        UINT32 addend;
};

class PatchSectiontoInstr : public SCPatch
{
    public:
        PatchSectiontoInstr():
            src_sec(NULL),
            src_offset(0),
            dest_instr(NULL),
            dest_offset(0) {}
        
        UPMParts *getSources();
        UPMParts *getDestinations();
        
    protected:
        SCSection *src_sec;
        UINT32 src_offset;
        SCInstr *dest_instr;
        UINT32 dest_offset;
};

class PatchSectiontoInstr32 : public PatchSectiontoInstr
{
    public:
        bool apply();
};

class PatchSectiontoInstrPC32 : public PatchSectiontoInstr
{
    public:
        bool apply();
        
    private:
        UINT32 addend;
};

class PatchSectiontoSection : public SCPatch
{
    public:
        PatchSectiontoSection():
            src_sec(NULL),
            src_offset(0),
            dest_sec(NULL),
            dest_offset(0) {}
        
        UPMParts *getSources();
        UPMParts *getDestinations();
        
    protected:
        SCSection *src_sec;
        UINT32 src_offset;
        SCSection *dest_sec;
        UINT32 dest_sec;
};

class PatchSectiontoSection32 : public PatchSectiontoSection 
{
    public:
        bool apply();
};

class PatchSectiontoSectionPC32 : public PatchSectiontoSection 
{
    public:
        bool apply();
    private:
        UINT32 addend;
};

class SCPatchList
{
    public:
        void init(SCRelocationList *, vector<INSTRUCTION*> *);
        void testPatchList();
        
    private:
        vector<SCPatch*> patch_list;
};
    

#endif
