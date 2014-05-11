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
#include <map>

class SCFunction;
class SCBlock;
class Operand;

class SCInstr;
typedef SCInstr INSTRUCTION;

#define AddrInstrHashT std::map< UINT32,SCInstr* >
#define AddrInstrIterT std::map< UINT32,SCInstr* >::iterator
#define AddrInstrPairT std::pair<UINT32,SCInstr*>

class SCInstr 
{
    public:

        SCInstr();
        SCInstr(struct SCINSTR_INTERNAL_STRUCT tmp);
        ~SCInstr();
        static int GlobalID;

        // ==== getters and setters ====
        void setFlag(IFLAG flag);
        bool hasFlag(IFLAG flag);
        void removeFlag(IFLAG flag);
        
        void setBlock(SCBlock* bbl);

        SCBlock* getBlock();
        UINT32 getAddr();
        Operand* getDest();


        // ==== methods ====
        bool isPCChangingClass();
        bool isReturnClass();
        bool isCallClass();
        bool isJmpClass();
        bool isConditionalJmpClass();
        bool isLoopClass();
        bool isMovClass();
        bool isNOPClass();
        bool isPopClass();
        bool isPushClass();
        bool isSubClass();
        
        bool isDataInstruction();

        bool isOnlyInstrInBBL();

        int getPos();
        void serialize(const char* prefix = "");

        int i_id;

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
        // WARNING:
        // ONLY use the ptr to edit the content
        // adding or deleting instr should ONLY use methods!!
        InstrListT* getInstrListPtr();  
        void setInstrList(InstrListT &ins);

        // ==== methods ==== 
        void constructCFG();
        void funResolveExitBlock();
        void resolveTargets();
        SCInstr* addrToInstr(UINT32 addr);
        void addInstrBack(SCInstr* ins);
        void addInsBeforeIns(SCInstr* ins, SCInstr* pivot);
        void addInsAfterIns(SCInstr* ins, SCInstr* pivot);

        SCInstr* getPrevInstr(SCInstr* ins);
        SCInstr* getNextInstr(SCInstr* ins);
        int getInstrPos(SCInstr* ins);

        void deleteInstrs(SCInstr* first, SCInstr* last);

        void serialize();


	private: 
		InstrListT p_instrs;
        AddrInstrHashT p_hash;

        void mapAddrToIns(SCInstr* ins);
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
