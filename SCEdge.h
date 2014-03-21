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


        SCEdge& operator = ( const SCEdge &other ); /* assignment operator */


    private:
        SCBlock *e_to;   // basic block pointed to by this edge y
        SCBlock *e_from;   // bbl where this edge originates y
        UINT16 e_flags;   // flags
        ETYPE e_type;// type y
        UINT32 e_id;// ID number for this edge
        EDGE_WEIGHT_TYPE e_edgeWeight; // weight of the edge

}; /* -----  end of class SCEdge  ----- */

#endif