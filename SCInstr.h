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

#include <list>
#include "SCEdge.h"
#include "SCFunction.h"

#define InstrIterT (std::list<SCInstr*>::iterator)
#define InstrListT (std::list<SCInstr*>)
#define INSTRLIST (SCInstrList::sharedInstrList())

#define INSTR_FUNCTION(ins) ((ins)->getBlock()->getFunction())


/*
 *  Instruction Flags
 */
/* If the instruction is indirect, e.g jmp *0xf00 */
#define INDIRECT                      (1LL << 0)
/*
 *  If the instruction begins a basic block.  Note that some basic block
 *  should have its firstInstr field pointing to this instruction
 */
#define BBL_START                     (1LL << 1)
/*
 *  If the instruction ends a basic block. Note that some basic block
 *  should have its lastInstr field pointing to this instruction
 */
#define BBL_END                       (1LL << 2)
/* If this instruction starts a function */
#define FUN_START                     (1LL << 3)
/* If this is the last instruction in a function */
#define FUN_END                       (1LL << 4)
/* If the MODR/M byte is used as an extension to the opcode */
#define EXTENDED_OPCODE               (1LL << 5)
/* If the operand has a source register */
#define SOURCE1_FLAG                  (1LL << 6)
/* If the operand has a second source register */
#define SOURCE2_FLAG                  (1LL << 7)
/* If the operand has a destination register */
#define DEST_FLAG                     (1LL << 8)
/*
 *  If, during inlining we find an instruction that uses the contents of FP,
 *  we surround it with an instruction to restore the original FP of the
 *  callee, and one to restore our new FP in the caller.  This instruction
 *  that is surrounded gets the INSTR_USES_FP_BUT_COMPENSATED_FLAG flag set.
 */
#define INSTR_USES_FP_BUT_COMPENSATED_FLAG (1LL << 9)
/* If the condition needs to be switched on the instruction */
#define INSTR_SWITCH_CONDITION_FLAG   (1LL << 10)
/* If a part of the instruction needs to be patched */
#define INSTR_RELOCATION_FLAG         (1LL << 11)
/*
 *  If the value is an ok value
 *  to use in place of calling InstrBPSPDiff()
 */
#define INSTR_BPSP_DIFF_STORED_FLAG   (1LL << 12)

/*
 *  Flags for instruction classes and types
 */
#define INSTR_CLASS_PC_CHANGING       (1LL << 13)
#define INSTR_CLASS_JUMP              (1LL << 14)
#define INSTR_CLASS_RETURN            (1LL << 15)
#define INSTR_CLASS_CALL              (1LL << 16)
#define INSTR_CLASS_BRANCH            (1LL << 17)
#define INSTR_CLASS_LOOP              (1LL << 18)
#define INSTR_CLASS_FLOAT             (1LL << 19)
#define INSTR_CLASS_NOP               (1LL << 20)
#define INSTR_CLASS_HALT              (1LL << 21)
#define INSTR_CLASS_LEAVE             (1LL << 22)
#define INSTR_CLASS_LEA               (1LL << 23)
#define INSTR_CLASS_ADD               (1LL << 24)
#define INSTR_CLASS_SUB               (1LL << 25)
#define INSTR_CLASS_OPDIR             (1LL << 26)
#define INSTR_CLASS_OPOFF             (1LL << 27)
#define INSTR_CLASS_MOV               (1LL << 28)
#define INSTR_CLASS_SYSCALL           (1LL << 29)
#define INSTR_HAS_CLASS_FLAGS         (1LL << 30)
#define INSTR_RELOCATABLE_FLAG        (1LL << 31)

/* Set for instructions that if we knew SOURCE1, we could evaluate */
#define INSTR_EVAL_IF_SOURCE1         (1LL << 32)
/* Set for instructions that if we knew SOURCE2, we could evaluate */
#define INSTR_EVAL_IF_SOURCE2         (1LL << 33)
/* Set for instructions that if we knew DEST, we could evaluate */
#define INSTR_EVAL_IF_DEST            (1LL << 34)
/*
 *  If the instruction defines %ebp, but not maliciously.
 *  This is set for "pop %ebp" instructions seen on function exit.
 */
#define INSTR_DEFINES_FP_NICELY       (1LL << 35)
/* Temporary flag */
#define INSTR_DONT_COMPENSATE_FOR_FP_USE_FLAG (1LL << 36)
/* Temp flag */
#define INSTR_TEMP_FLAG               (1LL << 37)
/* Flist flag */
#define INSTR_FLIST_FLAG              (1LL << 39)
/* Set if the instruction is eliminatable */
#define INSTR_ELIMINATABLE_FLAG       (1LL << 39)
/* Set to indicate that a instruction MAY have a JT behind it. */
#define INSTR_MAY_HAVE_JT             (1LL << 40)
#define INSTR_CLONED                  (1LL << 41)
#define INSTR_LITERAL_BYTES_FLAG      (1LL << 42)
#define INSTR_CLASS_POP               (1LL << 43)
#define INSTR_CLASS_PUSH              (1LL << 44)
/* New instr introduced to tolerate data in the text section */
#define INSTR_DATA_BYTE               (1LL << 45)
/* Set to mark a section boundary when re-splitting merged code sections */
#define INSTR_STARTS_SECTION          (1LL << 46)
/* Extension to allow each instruction to potentially specify its alignment */
#define INSTR_NEEDS_ALIGNMENT         (1LL << 47)
/* Indicates instructions added for padding : Can potentially be removed ?? */
#define INSTR_PADDING_BYTE        (1LL << 48)
/* Set for jumps converted to jumps through the spoofed jump tables (binobf) */
#define INSTR_SPOOF_JT_FLAG           (1LL << 49)
/* Set for jumps converted to branch function calls (binobf) */
#define INSTR_JBF_CALL_FLAG           (1LL << 50)
/* Set for calls converted to branch function calls (binobf) */
#define INSTR_CBF_CALL_FLAG           (1LL << 51)
/* Executing the instruction will raise the below signal (binobf) */
#define INSTR_SIGILL_FLAG             (1LL << 52)
#define INSTR_SIGFPE_FLAG             (1LL << 53)
#define INSTR_SIGSEGV_FLAG            (1LL << 54)
/* Set for junk instructions (binobf) */
#define INSTR_JUNK_FLAG               (1LL << 55)



#define INSTR_NOCLONE_FLAG \
    (INSTR_RELOCATABLE_FLAG | FUN_START | FUN_END | INSTR_BPSP_DIFF_STORED_FLAG)




class SCInstr {

    public:
    // ==== getters and setters ====
    void setFlag(UINT64 flag);
    bool hasFlag(UINT64 flag);
    void removeFlag(UINT64 flag);
    
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
    
    private:
        void checkFlags();
        void insertSetClassFlags();
        INT64 i_flags;                  // instruction flags n | t | q | a | c 主要在t中填好的
        Operand *i_src;                 // first source operand n
        Operand *i_src2;                // second source operand n
        Operand *i_dest;                // destination operand n
        ADDRESS i_address;              // original location MAGIC_NUMBER y | n
        ADDRESS i_final_address;        // final location d
        SCBlock *i_block;         // basic block that contains this insn b
        int i_temp;                     // temporary: reloc offset or stack usage, 指令中重定位项的偏移 这个成员的用处在于data instr中定位重定位项 o
        UINT32 i_id;                    // ID number 递增 y
        UINT16 i_prefixes;              // instruction prefix n
        UINT16 i_class;                 // instruction class (e.g. add, pop, imul) n
        UINT32 i_length;                // length in bytes t
        UINT8 i_type;                   // instruction type (e.g. cond, uncond...) n
        UINT8 *i_literal_data;          // literal bytes associated with this insn
                                            // (literal bytes flag must be set) m
        UINT32 i_alignment;             // alignment constraints for instructions
};

class SCInstrList
{
	public:
		SCInstrList();
		~SCInstrList();
        static SCInstrList* sharedInstrList();
        
        // ==== getters and setters ====
        InstrListT getInstrList();

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

#endif
