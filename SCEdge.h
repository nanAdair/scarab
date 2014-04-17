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

        void setFlag(UINT16 flag);
        bool hasFlag(UINT16 flag);
        void removeFlag(UINT16 flag);

        void setTo(SCBlock* to);
        void setFrom(SCBlock* from);
        void setType(UINT16 type);

        SCBlock* getTo();
        SCBlock* getFrom();
        ETYPE getType();



    private:
        SCBlock *e_to;   // basic block pointed to by this edge y
        SCBlock *e_from;   // bbl where this edge originates y
        EFLAG e_flags;   // flags
        UINT16 e_type;// type y

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

        SCEdge* addBBLEdge(SCBlock* from, SCBlock* to, ETYPE type);
        void removeBBLEdge(SCBlock* from, SCBlock* to, ETYPE type);
        void removeEdge(SCEdge* edge);
        bool edgeExistOrNot(SCEdge* edge);



    private:
        EdgeListT p_edges;


}; /* -----  end of class SCEdgeList  ----- */


#endif
