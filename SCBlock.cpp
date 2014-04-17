/*
 * =====================================================================================
 *
 *       Filename:  SCBlock.cpp
 *
 *    Description:  Implementation of class SCBlock and SCBlockList.
 *
 *        Version:  1.0
 *        Created:  2014/03/20 16时00分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SCBlock.h"
#include <algorithm>

#include "SCInstr.h"
#include "SCEdge.h"
#include "SCFunction.h"


SCBlock::SCBlock() {
    b_type = BT_INVALID;
    b_flags = 0;
    b_weight = 0;
    b_first = b_last = NULL;
    b_id = 0;   // TODO: global increase;
}

void SCBlock::setFlag(BFLAG flag) {
    this->b_flags |= flag;
}

bool SCBlock::hasFlag(BFLAG flag) {
    return (bool)((this->b_flags) & flag);
}

void SCBlock::removeFlag(BFLAG flag) {
    (this->b_flags) &= (~flag);
}

void SCBlock::setType(BTYPE type) {
    this->b_type = type;
}

void SCBlock::setFirstInstr(SCInstr* instr) {
    if (instr == NULL) {
        printf("Warning: setFirstInstr(): instr == NULL!\n");
        return;
    }
    this->b_first = instr;
}

void SCBlock::setLastInstr(SCInstr* instr) {
    if (instr == NULL) {
        printf("Warning: setLastInstr(): instr == NULL!\n");
        return;
    }
    this->b_last = instr;
}

void SCBlock::setFunction(SCFunction* fun) {
    this->b_fun = fun;
}

BFLAG SCBlock::getFlag() {
    return this->b_flags;
}

BTYPE SCBlock::getType() {
    return this->b_type;
}

SCInstr* SCBlock::getFirstInstr() {
    return this->b_first;
}

SCInstr* SCBlock::getLastInstr() {
    return this->b_last;
}

UINT32 SCBlock::getID() {
    return this->b_id;
}

SCFunction* getFunction() {
    return this->b_fun;
}

void SCBlock::moveSuccEdgesToBBL(SCBlock* to) {
    to->getSucc().clear();
    for(EdgeIterT it=b_succ.begin(); it!=b_succ.end(); ++it) {
        (*it)->setFrom(to);
        to->getSucc().push_back(*it);
    }
    this->b_succ.clear();
}

void SCBlock::addEntryEdge() {
    SCBlock* firstBBL = getFunction()->getEntryBlock();
    if (getEdgeFromBBL(firstBBL)!=NULL) {
        INSTRLIST->addBBLEdge(firstBBL, this, ET_ENTRY);
    }
}

SCEdge* SCBlock::getEdgeFromBBL(SCBlock* from) {
    for(EdgeIterT it=from->getSucc().begin(); it!=(from->getSucc()).end(); ++it) {
        if ((*it)->getTo() == this)
            return (*it);
    }
    return NULL;
}

SCEdge* SCBlock::getEdgeToBBL(SCBlock* to) {
    for(EdgeIterT it=(to->getPred()).begin(); it!=(to->getPred()).end(); ++it) {
        if ((*it)->getFrom() == this)
            return (*it);
    }
    return NULL;
}

void SCBlock::addEdgeToHELL(UINT8 type) {
    // TODO: check if HELL==NULL
    addEdgeToBBL(HELL, type);
}

void SCBlock::addEdgeFromHELL(UINT8 type) {
    // TODO: check if HELL==NULL
    addEdgeFromBBL(HELL, type);
}

void SCBlock::addEdgeToBBL(SCBlock* to, UINT8 type) {
    EDGELIST->addBBLEdge(this, to, type);
}
void SCBlock::addEdgeFromBBL(SCBlock* from, UINT8 type) {
    EDGELIST->addBBLEdge(from, this, type);
}


void SCBlock::removeAllEdges() {
    for(it=b_pred.begin(); it!=b_pred.end(); ++it) {

    }
}

bool SCBlock::succBBLExistOrNot(SCBlock* bbl) {
    for(EdgeIterT it=getSucc().begin(); it!=getSucc().end(); ++it) {
        if ((*it)->getTo() == bbl)
            return true;
    }
    return false;
}

bool SCBlock::predBBLExistOrNot(SCBlock* bbl) {
    for(EdgeIterT it=getPred().begin(); it!=getPred().end(); ++it) {
        if ((*it)->getFrom() == bbl)
            return true;
    }
    return false;
}


// ==== SCBlockList ====
static SCBlockList* _sharedBlockList = NULL;

SCBlockList::SCBlockList() {
    _sharedBlockList = this;
   
    // set up HELL block
    if (HELL) {
        HELL->removeAllEdges();
        delete HELL;
    }
    HELL = new SCBlock();
    SCFunction* hellfun = new SCFunction();
    HELL->setFunction(hellfun);
    hellfun->setFirstBlock(HELL);
    hellfun->setLastBlock(HELL);
    HELL->setType(BT_HELL);
}

SCBlockList* SCBlockList::sharedBlockList() {
    if (_sharedBlockList == NULL) {
        _sharedBlockList = new SCBlockList();
    }
    return _sharedBlockList;
}

BlockListT SCBlockList::getBlockList() {
    return this->p_bbls;
}



void SCBlockList::createBBLList(SCInstrList instrList) {
    InstrIterT instrIter;
    InstrListT instrs = instrList.getInstrList(); 
    SCBlock *bbl;
    for(instrIter=instrs.begin(); instrIter!=instrs.end(); ++instrIter) {
        if(instrIter->hasFlag(BBL_START)) {
            bbl = new SCBlock();
            bbl->setFirstInstr(instrIter);
            bbl->setLastInstr(instrIter);
            (this->p_bbls).push_back(bbl);
        }
        else if(instrIter->hasFlag(BBL_END)) {
            bbl->setLastInstr(instrIter);
        }
        instrIter->setBlock(bbl); 

    }
}

void SCBlockList::markBBL(SCInstrList instrList) {
    SCInstr* startins = (instrList.getInstrList()).front();
    startins->setFlag(BBL_START);
    
    InstrIterT instrIter, nextInstrIter;
    InstrListT instrs = instrList.getInstrList();
    for(instrIter=instrs.begin(); instrIter!=instrs.end(); ++instrIter) {
        if ((*instrIter)->isPCChangingClass() || (*instrIter)->isDataInstruction()) {
            (*instrIter) -> setFlag(BBL_END);
            nextInstrIter = std::next(instrIter, 1);
            if (nextInstrIter != instrs.end()) {
                (*nextInstrIter) -> setFlag(BBL_START);
            }
        }
        nextInstrIter = std::next(instrIter, 1);
        if (nextInstrIter != instrs.end()) {
            (*instrIter) -> setFlag(BBL_END);
            (*instrIter) -> setFlag(FUN_END);
            break;
        }
    }
    return;
}

void SCBlockList::divideBBLByInstr(SCBlock* bbl, SCInstr* ins) {
    
    if (ins->hasFlag(BBL_START)) {
        Report(RT_MAIN, "Attempt to devide BBL with an instruction that start a BBL\n");
        return;
    }
    
    SCBlock* nbbl = new SCBlock();
    nbbl->setType(bbl->getType());
    
    BlockIterT bblIt = std::find(p_bbls.begin(), p_bbls.end(), bbl);
    if (bblIt == p_bbls.end()) {
        Report(RP_MAIN, "FATAL: bbl not in the list!");
    }
    p_bbls.insert(++bblIt, nbbl);

    bbl->moveSuccEdgesToBBL(nbbl);
    nbbl->setFlag(bbl->getFlag());
    
    // Flag the instructions appropriately.
    ins->setFlag(BBL_START);
    SCInstr *prevIns = INSTRLIST->getNextInstr(ins);
    if (prevIns) {
        prevIns -> setFlag(BBL_END);
    }

    // Tell the instructions about the change.
    InstrIterT insIter = std::find(INSTRLIST->getInstrList().begin(), INSTRLIST->getInstrList().end(), ins);
    while(insIter != INSTRLIST->getInstrList().end()) {
        (*insIter)->setBlock(nbbl);
        if ((*insIter)->hasFlag(BBL_END)) {
            break;
        }
        ++insIter;
    }

    // Update the info of the original bbl.
    bbl->setType(BT_NORMAL);
    bbl->setLastInstr(prevIns);

    // Add an edge between the two bbls.
    SCEdge* edge = EDGELIST->addBBLList(bbl, nbbl, ET_NORMAL);
    edge->setWeight(bbl->getWeight());

    if (bbl == bbl->getFunction()->getLastBlock()) {
        bbl->getFunction()->setLastBlock(nbbl);
    }

    nbbl->setWeight(bbl->getWeight());

    // TODO: flist update 

}


SCBlock* SCBlockList::getPrevBBL(SCBlock* bbl) {
    BlockIterT it = std::find(p_bbls.begin(), p_bbls.end(), bbl);
    if (it == p_bbls.end() || it == p_bbls.begin()) {
        return NULL;
    }
    --it;
    return *it;
}


SCBlock* SCBlockList::getNextBBL(SCBlock* bbl) {
    BlockIterT it = std::find(p_bbls.begin(), p_bbls.end(), bbl);
    if (it == p_bbls.end() || ++it == p_bbls.end()) {
        return NULL;
    }
    return *it;
}
