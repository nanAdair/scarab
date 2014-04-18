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

/* 32:      meaning the value is absolute to the destination address
 * PC32:    meaning the value is relative to the destination address*/

#ifndef SCUPM_H
#define SCUPM_H

#include "relocation.h"
#include "disasm.h"
#include "SCInstr.h"
#include "type.h"

class SCRelocation;
class SCSection;
class SCSymbol;

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
        //virtual UPMParts *getSources() = 0;
        //virtual UPMParts *getDestinations() = 0;
};

class PatchInstrtoInstr : public SCPatch
{
    public:
        PatchInstrtoInstr() {}
        ~PatchInstrtoInstr() {}
        
        PatchInstrtoInstr(INSTRUCTION *s_instr, UINT32 s_offset, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add) :
            src_instr(s_instr),
            src_offset(s_offset),
            dest_instr(d_instr),
            dest_offset(d_offset),
            addend(add) {}
        
        
        //UPMParts *getSources();
        //UPMParts *getDestinations();
        
    protected:
        INSTRUCTION *src_instr;
        UINT32 src_offset;
        INSTRUCTION *dest_instr;
        UINT32 dest_offset;
        INT32 addend;
};

class PatchInstrtoInstr32 : public PatchInstrtoInstr
{
    public:
        PatchInstrtoInstr32() {}
        ~PatchInstrtoInstr32() {}
        
        PatchInstrtoInstr32(INSTRUCTION *s_instr, UINT32 s_offset, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add) : 
            PatchInstrtoInstr(s_instr, s_offset, d_instr, d_offset, add) {}
        
        bool apply();
};

class PatchInstrtoInstrPC32 : public PatchInstrtoInstr
{
    public:
        PatchInstrtoInstrPC32() {}
        ~PatchInstrtoInstrPC32() {}

        PatchInstrtoInstrPC32(INSTRUCTION *s_instr, UINT32 s_offset, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add) : 
            PatchInstrtoInstr(s_instr, s_offset, d_instr, d_offset, add) {}
        
        bool apply();
};

class PatchSectiontoInstr : public SCPatch
{
    public:
        PatchSectiontoInstr() {}
        ~PatchSectiontoInstr() {}
        
        PatchSectiontoInstr(SCSection *s_sec, UINT32 s_offset, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add):
            src_sec(s_sec),
            src_offset(s_offset),
            dest_instr(d_instr),
            dest_offset(d_offset),
            addend(add) {}
        
        //UPMParts *getSources();
        //UPMParts *getDestinations();
        
    protected:
        SCSection *src_sec;
        UINT32 src_offset;
        INSTRUCTION *dest_instr;
        UINT32 dest_offset;
        INT32 addend;
};

class PatchSectiontoInstr32 : public PatchSectiontoInstr
{
    public:
        PatchSectiontoInstr32() {}
        ~PatchSectiontoInstr32() {}
        
        PatchSectiontoInstr32(SCSection *s_sec, UINT32 s_offset, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add):
            PatchSectiontoInstr(s_sec, s_offset, d_instr, d_offset, add) {}
        
        bool apply();
};

class PatchSectiontoInstrPC32 : public PatchSectiontoInstr
{
    public:
        PatchSectiontoInstrPC32() {}
        ~PatchSectiontoInstrPC32() {}
        
        PatchSectiontoInstrPC32(SCSection *s_sec, UINT32 s_offset, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add):
            PatchSectiontoInstr(s_sec, s_offset, d_instr, d_offset, add) {}
        
        bool apply();
};

class PatchSectiontoSection : public SCPatch
{
    public:
        PatchSectiontoSection() {}
        ~PatchSectiontoSection() {}
        
        PatchSectiontoSection(SCSection *s_sec, UINT32 s_offset, SCSection *d_sec, UINT32 d_offset, INT32 add):
            src_sec(s_sec),
            src_offset(s_offset),
            dest_sec(d_sec),
            dest_offset(d_offset),
            addend(add) {}
        
        //UPMParts *getSources();
        //UPMParts *getDestinations();
        
    protected:
        SCSection *src_sec;
        UINT32 src_offset;
        SCSection *dest_sec;
        UINT32 dest_offset;
        INT32 addend;
};

class PatchSectiontoSection32 : public PatchSectiontoSection 
{
    public:
        PatchSectiontoSection32() {}
        ~PatchSectiontoSection32() {}
        
        PatchSectiontoSection32(SCSection *s_sec, UINT32 s_offset, SCSection *d_sec, UINT32 d_offset, INT32 add):
            PatchSectiontoSection(s_sec, s_offset, d_sec, d_offset, add) {}
        
        bool apply();
};

class PatchSectiontoSectionPC32 : public PatchSectiontoSection 
{
    public:
        PatchSectiontoSectionPC32() {}
        ~PatchSectiontoSectionPC32() {}
        
        PatchSectiontoSectionPC32(SCSection *s_sec, UINT32 s_offset, SCSection *d_sec, UINT32 d_offset, INT32 add):
            PatchSectiontoSection(s_sec, s_offset, d_sec, d_offset, add) {}
        
        bool apply();
};

class PatchSecSectoInstr : public SCPatch
{
    public:
        PatchSecSectoInstr() {}
        ~PatchSecSectoInstr() {}
        
        PatchSecSectoInstr(SCSection *s_sec, UINT32 s_offset, SCSection *b_sec, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add) :
            src_sec(s_sec),
            src_offset(s_offset),
            base_sec(b_sec),
            dest_instr(d_instr),
            dest_offset(d_offset),
            addend(add) {}
        
    protected:
        SCSection *src_sec;
        UINT32 src_offset;
        SCSection *base_sec;
        INSTRUCTION *dest_instr;
        UINT32 dest_offset;
        INT32 addend;
};

class PatchSecSectoInstr32 : public PatchSecSectoInstr 
{
    public:
        PatchSecSectoInstr32(SCSection *s_sec, UINT32 s_offset, SCSection *b_sec, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add) :
            PatchSecSectoInstr(s_sec, s_offset, b_sec, d_instr, d_offset, add) {}
        
        bool apply();
};

class PatchSecSectoInstrPC32 : public PatchSecSectoInstr 
{
    public:
        PatchSecSectoInstrPC32(SCSection *s_sec, UINT32 s_offset, SCSection *b_sec, INSTRUCTION *d_instr, UINT32 d_offset, INT32 add) :
            PatchSecSectoInstr(s_sec, s_offset, b_sec, d_instr, d_offset, add) {}
        
        bool apply();
};

class PatchSectiontoSymbol32: public SCPatch 
{
    public:
        PatchSectiontoSymbol32() {}
        ~PatchSectiontoSymbol32() {}
        
        PatchSectiontoSymbol32(SCSection *s_sec, UINT32 s_offset, SCSymbol *d_sym) :
            src_sec(s_sec),
            src_offset(s_offset),
            dest_sym(d_sym) {}

        bool apply();
        
    private:
        SCSection *src_sec;
        UINT32 src_offset;
        SCSymbol *dest_sym;
};

class PatchInstrtoSymbol32 : public SCPatch 
{
    public:
        PatchInstrtoSymbol32() {}
        ~PatchInstrtoSymbol32() {}
        
        PatchInstrtoSymbol32(INSTRUCTION *s_instr, SCSymbol *d_sym) :
            src_instr(s_instr),
            dest_sym(d_sym) {}

        bool apply();
        
    private:
        INSTRUCTION *src_instr;
        SCSymbol *dest_sym;
};

class SCPatchList
{
    public:
        void initUPMRel(SCSectionList *, SCRelocationList *);
        void initUPMSym(SCSectionList *, SCSymbolListREL *, InstrListT*);
        void testPatchList();

        int apply();
        
    private:
        vector<SCPatch*> p_list;
        
        INSTRUCTION *backtraceInstr(InstrListT*, UINT32 );
        SCSection *backtraceSec(SCSectionList *, UINT32);
};
    

#endif
