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

#include <algorithm>
#include "SCBlock.h"

SCEdge::SCEdge() {
    this -> e_to = this -> e_from = NULL;
    this->e_flags = e_type = 0;
}
SCEdge::~SCEdge() {
    
}

void SCEdge::setFlag(EFLAG flag) {
    
}

void SCEdge::removeFlag(EFLAG flag) {

}

bool SCEdge::hasFlag(EFLAG flag) {

}

void SCEdge::setTo(SCBlock* to) {
    this->e_to = to;
}
void SCEdge::setFrom(SCBlock* from) {
    this->e_from = from;
}
void SCEdge::setType(ETYPE type) { 
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

SCEdge* SCEdgeList::addBBLEdge(SCBlock* from, SCBlock* to, ETYPE type) {
    SCEdge *edge = new SCEdge();
    edge->setTo(to);
    edge->setFrom(from);
    edge->setType(type);

    (this->p_edges).push_back(edge);
    from->addSuccEdge(edge);
    to->addPredEdge(edge);

    return edge;
}

void SCEdgeList::removeBBLEdge(SCBlock* from, SCBlock* to, ETYPE type) {
    SCEdge* edge = getBBLEdge(from, to, type);
    if (edge != NULL) {
        from->removeSuccEdge(edge);
        to->removePredEdge(edge);
        removeEdge(edge);
        delete edge;
    }
}
void SCEdgeList::removeEdge(SCEdge* edge) {
    EdgeIterT it = std::find(p_edges.begin(), p_edges.end(), edge);
    if (it!=p_edges.end()) {
        p_edges.erase(it);
    }
}

bool SCEdgeList::edgeExistOrNot(SCEdge* edge) {

    EdgeIterT it = std::find(p_edges.begin(), p_edges.end(), edge);
    return (it==p_edges.end())?false:true;
}

bool SCEdgeList::edgeExistOrNot(SCBlock* from, SCBlock* to) {
    for(EdgeIterT it=(from->getSucc()).begin(); it!=(from->getSucc()).end(); ++it) {
        if (((*it)->getFrom()==from) && ((*it)->getTo()==to))
            return true;
    }
    return false;
}

bool SCEdgeList::edgeExistOrNot(SCBlock* from, SCBlock*to, ETYPE type) {
    if(getBBLEdge(from, to, type) != NULL)
        return true;
    return false;
}

SCEdge* SCEdgeList::getBBLEdge(SCBlock* from, SCBlock* to, ETYPE type) {
    for(EdgeIterT it=(from->getSucc()).begin(); it!=(from->getSucc()).end(); ++it) {
        if (((*it)->getFrom()==from) && ((*it)->getTo()==to) && 
            ((*it)->getType()== type))
            return *it;
    }
    return NULL;
}

