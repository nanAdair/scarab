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
#include <cstring>
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

void SCEdge::serialize(const char* prefix) {
    SCLog(RL_ZERO, "%s====SCEdge====", prefix);

    char ts[30] = {0};
    if (e_type == ET_NORMAL)
        strcpy(ts, "ET_NORMAL");
    else if (e_type == ET_TRUE)
        strcpy(ts, "ET_TRUE");
    else if (e_type == ET_FALSE)
        strcpy(ts, "ET_FALSE");
    else if (e_type == ET_UNCOND)
        strcpy(ts, "ET_UNCOND");
    else if (e_type == ET_RETURN)
        strcpy(ts, "ET_RETURN");
    else if (e_type == ET_FUNLINK)
        strcpy(ts, "ET_FUNLINK");
    else if (e_type == ET_EXIT)
        strcpy(ts, "ET_EXIT");
    else if (e_type == ET_FUNCALL)
        strcpy(ts, "ET_FUNCALL");
    else if (e_type == ET_OBF)
        strcpy(ts, "ET_OBF");

    SCLog(RL_ZERO, "%sfrom: %d, to: %d, type: %d(%s)", prefix, e_from->getPos(), e_to->getPos(), e_type, ts);
    SCLog(RL_ZERO, "%s====END=SCEdge====", prefix);
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

SCEdge* SCEdgeList::addEdge(SCBlock* from, SCBlock* to, ETYPE type) {
    if (edgeExistOrNot(from, to, type))
    {
        return getBBLEdge(from, to, type);
    }

    SCEdge *edge = new SCEdge();
    edge->setTo(to);
    edge->setFrom(from);
    edge->setType(type);

    (this->p_edges).push_back(edge);

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
void SCEdgeList::removeBBLEdge(SCEdge* edge) {
    EdgeIterT eit = std::find(p_edges.begin(), p_edges.end(), edge);
    if (eit != p_edges.end()) {
        edge->getFrom()->removeSuccEdge(edge);
        edge->getTo()->removePredEdge(edge);
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
    EdgeListT succ = from->getSucc();
    for(EdgeIterT it=succ.begin(); it!=succ.end(); ++it) {
        if (((*it)->getFrom()==from) && ((*it)->getTo()==to))
            return true;
    }
    return false;
}

bool SCEdgeList::edgeExistOrNot(SCBlock* from, SCBlock*to, ETYPE type) {
    // SCLog(RL_ONE, "edge exist or not, from(%x), to(%x)", from, to);
    if(getBBLEdge(from, to, type) != NULL)
        return true;
    return false;
}

SCEdge* SCEdgeList::getBBLEdge(SCBlock* from, SCBlock* to, ETYPE type) {
    // SCLog(RL_ONE, "getBBLEdge from(%x), to(%x), from->succ->size(%d)", from, to, from->getSucc().size());
    EdgeListT succ = from->getSucc();
    for(EdgeIterT it=succ.begin(); it!=succ.end(); ++it) 
    {
        if (((*it)->getFrom()==from) && ((*it)->getTo()==to) && 
            ((*it)->getType()== type))
            return *it;
    }
    return NULL;
}

