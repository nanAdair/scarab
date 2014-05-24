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

#include "type.h"

class SCBlock;


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

        void setFlag(EFLAG flag);
        bool hasFlag(EFLAG flag);
        void removeFlag(EFLAG flag);

        void setTo(SCBlock* to);
        void setFrom(SCBlock* from);
        void setType(ETYPE type);

        SCBlock* getTo();
        SCBlock* getFrom();
        ETYPE getType();

        void serialize(const char* prefix = "");


    private:
        SCBlock *e_to;   // basic block pointed to by this edge y
        SCBlock *e_from;   // bbl where this edge originates y
        EFLAG e_flags;   // flags
        ETYPE e_type;// type y

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

        SCEdge* addEdge(SCBlock* from, SCBlock* to, ETYPE type);
        void removeBBLEdge(SCBlock* from, SCBlock* to, ETYPE type);
        void removeBBLEdge(SCEdge* edge);
        void removeEdge(SCEdge* edge);  // only remove from the list
        bool edgeExistOrNot(SCEdge* edge);
        bool edgeExistOrNot(SCBlock* from, SCBlock* to);
        bool edgeExistOrNot(SCBlock* from, SCBlock* to, ETYPE type);
        SCEdge* getBBLEdge(SCBlock* from, SCBlock* to, ETYPE type);

    private:
        EdgeListT p_edges;


}; /* -----  end of class SCEdgeList  ----- */


#endif
