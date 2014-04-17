/*
 * =====================================================================================
 *
 *       Filename:  SCInstr.h
 *
 *    Description:  Definition of class SCInstr and SCInstrList.
 *
 *        Version:  1.0
 *        Created:  2014/03/20 15时42分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __Scarab__SCInstr__
#define __Scarab__SCInstr__

#include "type.h"

class SCFunction;
class SCBlock;
class Operand;

class SCInstr;
typedef SCInstr INSTRUCTION;


class SCInstr 
{
    public:

        // ==== getters and setters ====
        void setFlag(IFLAG flag);
        bool hasFlag(IFLAG flag);
        void removeFlag(IFLAG flag);
        
        void setBlock(SCBlock* bbl);

        SCBlock* getBlock();


        // ==== methods ====
        bool isPCChangingClass();
        bool isReturnClass();
        bool isCallClass();
        bool isHaltClass();
        bool isJumpClass();
        bool isAddClass();
        bool isAndClass();
        bool isBranchClass();
        bool isFPClass();
        bool isLeaClass();
        bool isLeaveClass();
        bool isLoopCLass();
        bool isMovClass();
        bool isNOPClass();
        bool isOPDIRClass();
        bool isOPOFFClass();
        bool isPopClass();
        bool isPushClass();
        bool isSubClass();
        bool isSyscallClass();
        
        bool isDataInstruction();
        bool isConditionalInstr();

        bool isOnlyInstrInBBL();

        SCInstr();
        // SCInstr(int,int,int,int,Operand*,Operand*,
        //     Operand*,Operand*,int,int,int,int,int,
        //     int,int,INSTRUCTION_TYPE,NORMAL_INSTRUCTION_CLASS,
        //     int,)
        SCInstr(struct SCINSTR_INTERNAL_STRUCT tmp);

        /* prefixes */
        INT8 lockAndRepeat;
        INT8 segmentOverride;
        INT8 OperandSizeOverride;
        INT8 AddressSizeOverride;
        /* operands */
        Operand *dest;
        Operand *src1;
        Operand *src2;
        Operand *src3;
        /* used for build cfg */
        UINT16 i_flags;
        SCBlock* i_block;
        /* use for addressing */
        INT8 mod;
        INT8 rm;
        INT8 regop;
        /* flags */
        INT32 secType;
        INT8 s;        // sign or not
        /* address */
        INT32 address;
        INT32 final_address;
        /* instruction type */
        INT8 type;
        /* instruction class */
        int instr_class;
        /* pwd that might be affected */
        INT32 pwd_affected;
        /* pwd that used */
        INT32 pwd_used;
        /* opcode */
        INT32 opcode;
        /* have ModR/M or not */
        bool ModRM;
        /* SIB */
        INT8 SIB;
        /* assembly */
        char *assembly;
        /* return machine code */
        char *ret_machineCode;
        /* mnemonic */
        const char *mnemonic;
        /* new CS and ESP(if existed) */
        INT16 new_cs;
        INT32 new_eip;
        /* size */
        INT32 size;
        /* operand size */
        int handlerIndex;
        /* binary */
        INT8 *binary;
        /* next instruction */
        INSTRUCTION *next;
        //struct _INSTRUCTION *next;
};


class SCInstrList
{
	public:
		SCInstrList();
		~SCInstrList();
        static SCInstrList* sharedInstrList();
        
        // ==== getters and setters ====
        InstrListT getInstrList();
        void setInstrList(InstrListT &ins);

        // ==== methods ==== 
        void funResolveExitBlock();
        void resolveTargets();
        SCInstr* addressToInstruction();
        void addInstrAfterInstr(SCInstr* instr);
        void addInstrBeforeInstr(SCInstr* instr);

        SCInstr* getPrevInstr(SCInstr* ins);
        SCInstr* getNextInstr(SCInstr* ins);


	private: 
		InstrListT p_instrs;
};

// ==== INTERNAL ====

struct SCINSTR_INTERNAL_STRUCT {
    /* prefixes */
    INT8 lockAndRepeat;
    INT8 segmentOverride;
    INT8 OperandSizeOverride;
    INT8 AddressSizeOverride;
    /* operands */
    Operand *dest;
    Operand *src1;
    Operand *src2;
    Operand *src3;
    /* use for addressing */
    INT8 mod;
    INT8 rm;
    INT8 regop;
    /* flags */
    INT32 secType;
    INT8 s;        // sign or not
    /* address */
    INT32 address;
    INT32 final_address;
    /* instruction type */
    INT8 type;
    /* instruction class */
    int instr_class;
    /* pwd that might be affected */
    INT32 pwd_affected;
    /* pwd that used */
    INT32 pwd_used;
    /* opcode */
    INT32 opcode;
    /* have ModR/M or not */
    bool ModRM;
    /* SIB */
    INT8 SIB;
    /* assembly */
    char *assembly;
    /* return machine code */
    char *ret_machineCode;
    /* mnemonic */
    const char *mnemonic;
    /* new CS and ESP(if existed) */
    INT16 new_cs;
    INT32 new_eip;
    /* size */
    INT32 size;
    /* operand size */
    int handlerIndex;
    /* binary */
    INT8 *binary;
    /* next instruction */
    INSTRUCTION *next;
    //struct _INSTRUCTION *next;
};

#endif
