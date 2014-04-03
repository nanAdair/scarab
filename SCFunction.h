/*
 * =====================================================================================
 *
 *       Filename:  SCFunction.h
 *
 *    Description:  Definition of class SCFunction and SCFunctionList.
 *
 *        Version:  1.0
 *        Created:  2014/03/20 15时37分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __Scarab__SCFunction__
#define __Scarab__SCFunction__

#include <list>

#define FunListT (std::list<SCFunction*>)
#define FunIterT (std::list<SCFunction*>::iterator)
#define FUNLIST (SCFunctionList::sharedFunctionList())

/*
 *  Function Flags
 */
#define FUNCTION_INVALID                    0
/*  Set when a function has been deemed analyzable (see dominators.h) */
#define FUNCTION_CAN_BE_INLINED_FLAG        (1 << 0)
/*  Set for functions that have been cloned */
#define FUNCTION_TEMP_FLAG                  (1 << 1)
/*  Set for well-behaved functions (that leave stack same as found it) */
#define FUNCTION_WELL_BEHAVED_FLAG          (1 << 2)
/*  Set for functions that alias the stack pointer */
#define FUNCTION_ALIASES_STACK_POINTER_FLAG (1 << 3)
/*  Set for functions where we can determine the difference between
 *  ESP and EBP at every point */
#define FUNCTION_BALANCED_STACK_FLAG        (1 << 4)
/*  Set for functions with a LEAVE/RET combo */
#define FUNCTION_LEAVE_RET_COMBO            (1 << 5)
/*  Set for functions which have the standard gcc prologue of
 *  "push %ebp, mov %esp->%ebp" */
#define FUNCTION_GCC_PROLOGUE_FLAG          (1 << 6)
/*  Set for functions in which constant propagation should be performed */
#define FUNCTION_CP_FLAG                    (1 << 7)
/*  Set for functions in which runtime stack and register snapshots
 *  have been allocated */
#define FUNCTION_SNAPSHOT_FLAG              (1 << 8)
/*  Set for functions who re-define the frame pointer
 *  outside of epilogue/prologue */
#define FUNCTION_REDEFINES_FP_FLAG          (1 << 9)
/*
 *  Set for functions who-re-define the frame pointer
 *  outside of epilogue/prologue, where the re-definition
 *  was not introduced as a result of inlining. The redefinitions that
 *  inlining uses are not malicious, as they are repaired almost instantly.
 */
#define FUNCTION_MALICIOUSLY_REDEFINES_FP_FLAG  (1 << 10)
/*  The function has an exit combo (not necessarily a leave/ret) */
#define FUNCTION_EXIT_COMBO_FLAG            (1 << 11)
/* This function has  a data instruction */
#define FUNCTION_DATA_INSTRUCTION_FLAG      (1 << 12)

/* Apply layout on this function */
#define FUNCTION_LAYOUT_FLAG                (1 << 13)

/*  Function to be excluded from the signal-based obfuscation. Functions
 *  called while installing signal handlers as well as handlers themself
 *  are marked with this flag. (binobf) */
#define FUNCTION_DO_NOT_OBFUSCATE_SIGNAL    (1 << 14)

#define FUNCTION_NOCLONE_FLAGS\
    (FUNCTION_SNAPSHOT_FLAG | \
	FUNCTION_BALANCED_STACK_FLAG | \
	FUNCTION_CP_FLAG | \
	FUNCTION_TEMP_FLAG)




class SCFunction
{
    public:
        SCFunction ();
        
        void setFlag(UINT32 flag);
        bool hasFlag(UINT32 flag);
        void removeFlag(UINT32 flag);

        void setFirstBlock(SCBlock* bbl);
        void setLastBlock(SCBlock* bbl);
        void setName(string& name);
        void setEntryBlock(SCBlock* bbl);
        void setExitBlock(SCBlock* bbl);

        SCBlock* getFirstBlock();
        SCBlock* getLastBlock();
        string getName();
        SCBlock* getEntryBlock();
        SCBlock* getExitBlock();
        
    


    private:
        UINT32 f_flags;                // flags
        SCBlock *f_first;         // first basic block in this function 和f_entry不一样 n
        SCBlock *f_last;          // last basic block in this function n
        UINT32 f_id;                   // unique identifier for the function y
        string f_name;                  // function name n
        SCBlock *f_entry;                // entry block y
        SCBlock *f_exit;                 // exit block y
};


class SCFunctionList {
    public:
        SCFunctionList();
        static SCFunctionList* sharedFunctionList();
        void createFunctionList(BlockListT bbls);
        void markFunctions(SymbolListT syms);

    private:
        FunListT p_funs;
};

#endif
