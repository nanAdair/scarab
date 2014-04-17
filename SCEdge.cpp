/*
 * =====================================================================================
 *
 *       Filename:  SCEdge.cpp
 *
 *    Description:  Implementation of class related to BBL edge.
 *
 *        Version:  1.0
 *        Created:  2014/04/04 01时30分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SCEdge.h"

#include "SCBlock.h"

SCEdge::SCEdge() {
    this -> e_to = this -> e_from = NULL;
    this->e_flags = e_type = 0;
}

void SCEdge::setFlag(UINT16 flag) {
    
}

void SCEdge::removeFlag(UINT16 flag) {

}

bool SCEdge::hasFlag(UINT16 flag) {

}

void SCEdge::setTo(SCBlock* to) {
    this->e_to = to;
}
void SCEdge::setFrom(SCBlock* from) {
    this->e_from = from;
}
void SCEdge::setType(UINT16 type) { 
    this->e_type = type;
}


SCBlock* SCEdge::getTo() {
    return this->e_to;
}
SCBlock* SCEdge::getFrom() {
    return this->e_from;
}
ETYPE SCEdge::getType() {
    return this->e_type;
}


// ==== SCEdgeList ====

static SCEdgeList* _sharedEdgeList;

SCEdgeList* SCEdgeList::sharedEdgeList() {
    if (!_sharedEdgeList) {
        _sharedEdgeList = new SCEdgeList();
    }
    return _sharedEdgeList;
}

SCEdgeList::SCEdgeList() {
    _sharedEdgeList = this;
}

SCEdge* SCEdgeList::addBBLEdge(SCBlock* from, SCBlock* to, UINT8 type) {
    SCEdge *edge = new SCEdge();
    edge->e_to = to;
    edge->e_from = from;
    edge->e_type = type;

    (this->p_edges).push_back(edge);
    from->addToEdge(edge);
    to->addFromEdge(edge);

    return edge;
}

void removeBBLEdge(SCBlock* from, SCBlock* to, ETYPE type) {
    SCEdge* edge = from->get;
}
void SCEdgeList::removeEdge(SCEdge* edge) {
    (this->p_edges).erase(edge);
}

bool SCEdgeList::edgeExistOrNot(SCEdge* edge) {
    for(EdgeIterT* it=p_edges.begin(); it!=p_edges.end(); ++it) {
        if (*it == edge)
            return true;
    }
    return false;
}

