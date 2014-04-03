/*
 * =====================================================================================
 *
 *       Filename:  SCEdge.h
 *
 *    Description:  Definition of class SCEdge and SCEdgeList.
 *
 *        Version:  1.0
 *        Created:  2014/03/20 15时37分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __Scarab__SCEdge__
#define __Scarab__SCEdge__

#include <list>
#include "SCBlock.h"

#define EdgeListT (std::list<SCEdge*>)
#define EdgeIterT (std::list<SCEdge*>::iterator)
#define EDGELIST (SCEdgeList::sharedEdgeList())

 /*
 *  The values for these symbols have been chosen to make some code in
 *  the function BBLRemoveEdge() [file: flowgraph.c] more efficient,
 *  by allowing us to test whether an edge can be skipped simply by
 *  testing whether the type of an edge is >= ET_SWITCH.  The assumption
 *  is that (edge->e_type) >= ET_SWITCH implies that (edge->e_type) is
 *  one of:
 *      { ET_SWITCH, ET_HELL, ET_HELLMAYBE, ET_ENTRY, ET_CHAIN, ET_SYSCALL }.
 *  --SKD 8/2002
 */
#define ET_INVALID           0
#define ET_FUNCALL           1
#define ET_UNCOND            2
#define ET_NORMAL            3
#define ET_RETURN            4
#define ET_FUNLINK           5
#define ET_DATALINK          6
#define ET_HALTLINK          7
#define ET_TRUE              8  
#define ET_FALSE             9 
#define ET_EXIT              10
#define ET_FUNDIRECT         11
// **?? COMPENSATE ??**什么作用
#define ET_COMPENSATE        12
#define ET_SWITCH            13
#define ET_HELL              14
#define ET_HELLMAYBE         15
#define ET_ENTRY             16
#define ET_CHAIN             17
#define ET_SYSCALL           18
#define ET_SYSCALL_LINK      19


/*
 * =====================================================================================
 *        Class:  SCEdge
 *  Description:  Edge between BBLs.
 * =====================================================================================
 */
class SCEdge
{
    public:
        SCEdge ();                             /* constructor      */
        SCEdge ( const SCEdge &other );   /* copy constructor */
        ~SCEdge ();                            /* destructor       */

        void setFlag(UINT16 flag);
        bool hasFlag(UINT16 flag);
        void removeFlag(UINT16 flag);

        void setTo(SCBlock* to);
        void setFrom(SCBlock* from);
        void setType(UINT16 type);
        void setWeight(EDGE_WEIGHT_TYPE weight);

        SCBlock* getTo();
        SCBlock* getFrom();
        UINT16 getType();
        EDGE_WEIGHT_TYPE getWeight();



    private:
        SCBlock *e_to;   // basic block pointed to by this edge y
        SCBlock *e_from;   // bbl where this edge originates y
        UINT16 e_flags;   // flags
        ETYPE e_type;// type y
        UINT32 e_id;// ID number for this edge
        EDGE_WEIGHT_TYPE e_edgeWeight; // weight of the edge

}; /* -----  end of class SCEdge  ----- */



/*
 * =====================================================================================
 *        Class:  SCEdgeList
 *  Description:  Definition of class SCEdgeList.
 * =====================================================================================
 */
class SCEdgeList
{
    public:
        SCEdgeList ();                             /* constructor */
        static SCEdgeList* sharedEdgeList();

        SCEdge* addBBLEdge(SCBlock* from, SCBlock* to, UINT8 type);
        void removeEdge(SCEdge* edge);
        bool edgeExistOrNot(SCEdge* edge);



    private:
        EdgeListT p_edges;


}; /* -----  end of class SCEdgeList  ----- */


#endif
