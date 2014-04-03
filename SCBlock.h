/*
 * =====================================================================================
 *
 *       Filename:  SCBlock.h
 *
 *    Description:  Definitionof class SCBlock and SCBlockList.
 *
 *        Version:  1.0
 *        Created:  2014/03/20 15时35分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __Scarab__SCBlock__
#define __Scarab__SCBlock__

#include <list>
#include "SCInstr.h"

#define BlockListT (std::list<SCBlock>)
#define BlockIterT (std::list<SCBlock>::iterator)
#define BLOCKLIST (SCBlockList::sharedBlockList())

/*
 *    Basic Block Types
 */
#define BT_INVALID 0 // BBL of this type has been set up incorrectly
#define BT_UNCOND 1  // BBL ending with an unconditional jump
#define BT_NORMAL 2  // BBL with no control transfer at the end
#define BT_BRANCH 3  // BBL ending with a conditional jump instruction
#define BT_RETURN 4  // BBL ending with a return instruction
#define BT_SWITCH 5  // BBL which ends with a jump through a jump table
#define BT_HELL 6    // HELL
#define BT_ENTRY 7   // abstract pseudo entry block for a function
#define BT_EXIT 8    // abstract pseudo exit block for a function
#define BT_CALL 9   // BBL ending with a function call instruction
#define BT_HALT 10  // BBL in which the program terminates
#define BT_SYSCALL 11// basic block that ends in a system call
#define BT_DATABLOCK 12// basic block that ends in a system call


/*
 * =====================================================================================
 *        Class:  SCBlock
 *  Description:  Contain the information of basic block
 * =====================================================================================
 */
class SCBlock
{
    public:
        SCBlock ();                             /* constructor */

        // getters and setters

        void setFlag(UINT64 flag);
        bool hasFlag(UINT64 flag);
        void removeFlag(UINT64 flag);

        void setType(UINT16 type);
        void setWeight(EDGE_WEIGHT_TYPE weight);
        void setFirstInstr(SCInstr *instr);
        void setLastInstr(SCInstr *instr);
        void setFunction(SCFunction *fun);

        UINT64 getFlag();
        UINT16 getType();
        EDGE_WEIGHT_TYPE getWeight();
        SCInstr* getFirstInstr();
        SCInstr* getLastInstr();
        UINT32 getID();
        SCFunction* getFunction();
        EdgeListT getSucc();
        EdgeListT getPred();

        // ==== methods ====
        void moveSuccEdgesToBBL(SCBlock* to);



    private:
        UINT16 b_type;                  // basic block type, e.g. normal, branch n | o
        INT64 b_flags;                  // assorted flags
        EDGE_WEIGHT_TYPE b_weight;      // block weight (profiled execution count)
        SCInstr *b_first;         // first instruction within this block n
        SCInstr *b_last;          // last instruction within this block n
        list<SCEdge*> b_pred;            // list of bbls that can transfer to here p
        list<SCEdge*> b_succ;            // list of bbls to which control can flow p
        SCFunction *b_fun;              // function to which this bbl belongs n | t
        UINT32 b_id;                    // ID number for this basic block y


}; /* -----  end of class SCBlock  ----- */


/*
 * =====================================================================================
 *        Class:  SCBlockList
 *  Description:  Containing all the basic blocks in the program.
 * =====================================================================================
 */
class SCBlockList
{
    public:
        SCBlockList ();                             /* constructor */
        static SCBlock* sharedBlockList();

        void createBBLList(SCInstrList instrList);
        void markBBL(SCInstrList instrList);
        void devideBBLByInstr(SCBlock* bbl, SCInstr* ins);

        SCBlock* getPrevBBL(SCBlock* bbl);
        SCBlock* getNextBBL(SCBlock* bbl);


    private:
        BlockListT p_bbls;
        BlockIterT getIterByBBL(SCBlock* bbl);

}; /* -----  end of class SCBlockList  ----- */

#endif
