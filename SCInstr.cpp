/*
 * =====================================================================================
 *
 *       Filename:  SCInstr.cpp
 *
 *    Description:  Implementation of class SCInstr and SCInstrList.
 *
 *        Version:  1.0
 *        Created:  2014/03/24 00时44分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SCInstr.h"
#include <algorithm>

void SCInstr::setFlag(UINT64 flag) {
    (this->i_flags) |= flag;
}

void SCInstr::removeFlag(UINT64 flag) {
    (this->i_flags) &= (~flag);
}

void SCInstr::setBlock(SCBlock* bbl) {
    this->i_block = bbl;
}

bool SCInstr::hasFlag() {
    return (bool)((this->i_flags) & flag);
}

SCBlock* SCInstr::getBlock() {
    return this->i_block;
}


// ==== methods ====
bool SCInstr::isPCChangingClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_PC_CHANGING);
}

bool SCInstr::isCallClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_CALL);
}

bool SCInstr::isReturnClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_RETURN);
}

bool SCInstr::isHaltClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_HALT);
}

bool SCInstr::isJumpClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_JUMP);
}

bool SCInstr::isAddClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_ADD);
}

bool SCInstr::isAndClass() {
    checkFlags();
    return (this->i_class == CLASS_AND) ? true : false;
}

bool SCInstr::isBranchClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_BRANCH);
}

bool SCInstr::isFPClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_FLOAT);
}

bool SCInstr::isLeaClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_LEA);
}

bool SCInstr::isLeaveClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_LEAVE);
}

bool SCInstr::isLoopClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_LOOP);
}

bool SCInstr::isMovClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_MOV);
}

bool SCInstr::isNOPClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_NOP);
}

bool SCInstr::isOPDIRClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_OPDIR);
}

bool SCInstr::isOPOFFClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_OPOFF);
}

bool SCInstr::isPopClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_POP);
}

bool SCInstr::isPushClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_PUSH);
}

bool SCInstr::isSubClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_SUB);
}

bool SCInstr::isSyscallClass() {
    checkFlags();
    return hasFlag(INSTR_CLASS_SYSCALL);
}

bool SCInstr::isDataInstruction() {
    return hasFlag(INSTR_DATA_BYTE);
}

bool SCInstr::isConditionalInstr() {
    // TODO: implement it.
}


bool SCInstr::isOnlyInstrInBBL() {
    if ( this->i_block->getFirst() != this )
        return false;
    if ( this->i_block->getLast() != this )
        return false;
    return true;
}

// ==== internal ====
void SCInstr::checkFlags() {
    if (!hasFlag(INSTR_HAS_CLASS_FLAGS)) {
        insertSetClassFlags();
    }
}

void SCInstr::insertSetClassFlags() {
    // TODO: transplant InstrSetClassFlags in sysdep.c
    // wait for zzb
}


// ==== SCInstrList ====
static SCInstrList* _sharedInstrList = NULL;

SCInstrList::SCInstrList() {
    _sharedInstrList = this;
}

SCInstrList* SCInstrList::sharedInstrList() {
    if (_sharedInstrList == NULL) {
        _sharedInstrList = new SCInstrList();
    }
    return _sharedInstrList;
}

void SCInstr::funResolveExitBlock() {
    InstrIterT instrIter;
    for(instrIter=p_instrs.begins(); instrIter!=p_instrs.end(); ++instrIter) {
        if ((*instrIter)->isReturnClass()) {
            EDGELIST->addBBLEdge((*instrIter)->getBlock(), INSTR_FUNCTION(*instrIter)->getExitBlock(), ET_EXIT);
            continue;
        }

        if ((*instrIter)->isDataInstruction() && 
                (*instrIter)->getBlock() == INSTR_FUNCTION(*instrIter)->getFirst() && 
                (*instrIter)->getBlock() == INSTR_FUNCTION(*instrIter)->getLast()) {
            EDGELIST->addBBLEdge((*instrIter)->getBlock(), INSTR_FUNCTION(*instrIter)->getExitBlock(), ET_EXIT);

                }
    }

    return;
}

void SCInstrList::resolveTargets() {
    for(InstrIterT it=p_instrs.begin(); it!=p_instrs.end(); ++it) {
        if ((*it)->isDataInstruction()) {
            INSTR_FUNCTION(*it)->setFlag(FUNCTION_DATA_INSTRUCTION_FLAG);
            if ((*it) != (*it)->getBlock()->getFirst()) {

            }
        }
    }
}


SCInstr* SCInstrList::getPrevInstr(SCInstr* ins) {
    InstrIterT it = std::find(p_instrs.begin(), p_instrs.end(), ins);
    if (it==p_instrs.end() || it==p_instrs.begin()) {
        return NULL;
    }
    --it;
    return *it;
}

SCInstr* SCInstrList::getNextInstr(SCInstr* ins) {
    InstrIterT it = std::find(p_instrs.begin(), p_instrs.end(), ins);
    if(it==p_instrs.end() || ++it==p_instrs.end()) {
        return NULL;
    }
    return *it;
}
