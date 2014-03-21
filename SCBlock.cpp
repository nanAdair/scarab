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

SCBlock::SCBlock() {
    b_type = BT_INVALID;
    b_flags = 0;
    b_weight = 0;
    b_first = b_last = NULL;
    b_id = 0;   // TODO: global increase;
}

void SCBlock::setFlag(UINT64 flag) {
    this->b_flags |= flag;
}

bool SCBlock::hasFlag(UINT64 flag) {
    return (bool)((this->b_flags) & flag);
}

void SCBlock::removeFlag(UINT64 flag) {
    (this->b_flags) &= (~flag);
}

void SCBlock::setType(UINT16 type) {
    this->b_type = type;
}

void SCBlock::setWeight(EDGE_WEIGHT_TYPE weight) {
    this->b_weight = weight;
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

UINT16 SCBlock::getType() {
    return this->b_type;
}

EDGE_WEIGHT_TYPE SCBlock::getWeight() {
    return this->b_weight;
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


// ==== SCBlockList ====
SCBlockList::SCBlockList() {
    // nothing to do
}

void SCBlockList::createBBLList(SCInstrList instrList) {
    SCInstrIter instrIter;
    SCBlock *bbl;
    for(instrIter=instrList.begin(); instrIter!=instrList.end(); ++instrIter) {
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
