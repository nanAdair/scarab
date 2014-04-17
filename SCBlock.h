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

#include "type.h"


class SCInstr;
class SCInstrList;
class SCEdge;
class SCFunction;


class SCBlock;

static SCBlock* HELL;


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

        void setFlag(BFLAG flag);
        bool hasFlag(BFLAG flag);
        void removeFlag(BFLAG flag);

        void setType(BTYPE type);
        void setFirstInstr(SCInstr *instr);
        void setLastInstr(SCInstr *instr);
        void setFunction(SCFunction *fun);

        BFLAG getFlag();
        BTYPE getType();
        SCInstr* getFirstInstr();
        SCInstr* getLastInstr();
        UINT32 getID();
        SCFunction* getFunction();
        EdgeListT getSucc();
        EdgeListT getPred();

        // ==== methods ====
        void moveSuccEdgesToBBL(SCBlock* to);
        void addEntryEdge();
        SCEdge* getEdgeFromBBL(SCBlock* from);
        SCEdge* getEdgeToBBL(SCBlock* to);
        void addEdgeToHELL(UINT8 type);
        void addEdgeFromHELL(UINT8 type);
        void addEdgeToBBL(SCBlock* to, UINT8 type);
        void addEdgeFromBBL(SCBlock* from, UINT8 type);
        void removeAllEdges();
        void removeSuccEdges();
        void removePredEdges();
        bool succBBLExistOrNot(SCBlock* bbl);
        bool predBBLExistOrNot(SCBlock* bbl);


    private:
        UINT16 b_type;                  // basic block type, e.g. normal, branch n | o
        INT64 b_flags;                  // assorted flags
        SCInstr *b_first;         // first instruction within this block n
        SCInstr *b_last;          // last instruction within this block n
        EdgeListT b_pred;            // list of bbls that can transfer to here p
        EdgeListT b_succ;            // list of bbls to which control can flow p
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
        void divideBBLByInstr(SCBlock* bbl, SCInstr* ins);

        SCBlock* getPrevBBL(SCBlock* bbl);
        SCBlock* getNextBBL(SCBlock* bbl);


    private:
        BlockListT p_bbls;
        BlockIterT getIterByBBL(SCBlock* bbl);

}; /* -----  end of class SCBlockList  ----- */

#endif
