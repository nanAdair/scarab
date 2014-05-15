/*
 * =====================================================================================
 *
 *       Filename:  SCFunction.cpp
 *
 *    Description:  Implementation of SCFunction and SCFunctionList.
 *
 *        Version:  1.0
 *        Created:  2014/03/21 14时52分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "SCFunction.h"
#include <stdlib.h>
#include <iterator>
#include <vector>
#include <algorithm>

#include "SCInstr.h"
#include "SCBlock.h"
#include "symbol.h"
#include "SCEdge.h"

SCFunction::SCFunction() {
    this->f_flags = 0;
    this->f_first = this->f_last = NULL;
    this->f_id = 0;     //TODO: global increase
    this->f_name = new char[20];
    this->f_entry = new SCBlock();
    this->f_exit = new SCBlock();
    f_entry->setType(BT_ENTRY);
    f_exit->setType(BT_EXIT);
    f_entry->setFunction(this);
    f_exit->setFunction(this);
}

SCFunction::~SCFunction() {
    BLOCKLIST->deleteBBLs(f_first, f_last);
}

void SCFunction::setFirstBlock(SCBlock *bbl) {
    this->f_first = bbl;
}
void SCFunction::setLastBlock(SCBlock *bbl) {
    this->f_last= bbl;
}
void SCFunction::setName(UINT8* name) {
    char *tn = (char*) name;
    this->f_name = tn;
}
void SCFunction::setName(const char* name) {
    strcpy(f_name, name);
}
void SCFunction::setEntryBlock(SCBlock* bbl) {
    this->f_entry = bbl;
}
void SCFunction::setExitBlock(SCBlock* bbl) {
    this->f_exit = bbl;
}

SCBlock* SCFunction::getFirstBlock() {
    return this->f_first;
}
SCBlock* SCFunction::getLastBlock() {
    return this->f_last;
}
char* SCFunction::getName() {
    return this->f_name;
}
SCBlock* SCFunction::getEntryBlock() {
    return this->f_entry;
}
SCBlock* SCFunction::getExitBlock() {
    return this->f_exit;
}

int SCFunction::getPos() {
    return FUNLIST->getFunctionPos(this);
}

void SCFunction::serialize(const char *prefix) {
    SCLog(RL_ZERO, "%s====SCFunction%d(0x%x)====", prefix, FUNLIST->getFunctionPos(this), this);
    SCLog(RL_ZERO, "%sFunction name: %s", prefix, f_name);
    SCLog(RL_ZERO, "%sFirst bbl: %d", prefix, BLOCKLIST->getBBLPos(f_first));
    SCLog(RL_ZERO, "%sLast bbl: %d", prefix, BLOCKLIST->getBBLPos(f_last));

    char np[100];
    strcpy(np, prefix);
    strcat(np, "\t");

    // show all the instrs within this bbl
    f_first->serialize(np);
    SCLog(RL_ZERO, "");
    if (f_first != f_last) {
        SCBlock* bbl = f_first;
        while((bbl=BLOCKLIST->getNextBBL(bbl)) != f_last) {
            bbl->serialize(np);
            SCLog(RL_ZERO, "");
        }
        f_last->serialize(np);
    }

    SCLog(RL_ZERO, "%s====END=SCFunction%d(0x%x)====", prefix, FUNLIST->getFunctionPos(this), this);
}


// ==== SCFunctionList ====
static SCFunctionList* _sharedFunctionList = NULL;

SCFunctionList::SCFunctionList() {
    _sharedFunctionList = this;
}

SCFunctionList* SCFunctionList::sharedFunctionList() {
    if (_sharedFunctionList == NULL) {
        _sharedFunctionList = new SCFunctionList();
    }
    return _sharedFunctionList;
}

void SCFunctionList::createFunctionList() {
    BlockIterT bit;
    BlockListT bbls = BLOCKLIST->getBlockList();
    SCFunction *fun;
    for(bit=bbls.begin(); bit!=bbls.end(); ++bit) {
        if ((*bit)->getFirstInstr()->hasFlag(FUN_START)) {

            fun = new SCFunction();
            fun->setFirstBlock(*bit); 
            fun->setLastBlock(*bit);
            fun->setName(SYMLISTREL->getSymNameByAddr((*bit)->getFirstInstr()->getAddr()));
            SCLog(RL_ONE, "fun name: %s", fun->getName());
            
            (this->p_funs).push_back(fun);
        }
        else if ((*bit)->getLastInstr()->hasFlag(FUN_END)) {
            fun->setLastBlock(*bit);
        }
        (*bit) -> setFunction(fun);
    }
    return;
}

void SCFunctionList::markFunctions() {
    SymListRELT funSyms = SYMLISTREL->getFunSymList();
    SCInstr* ins;
    for (SymIterRELT it=funSyms.begin(); it!=funSyms.end(); ++it) {
        ins = INSTRLIST->addrToInstr((*it)->getSymbolValue());
        if (ins == NULL)
            continue;
        SCLog(RL_ONE, "symbol(%s) at 0x%x, instr pos is %d", (*it)->getSymbolName(), (*it)->getSymbolValue(), ins->getPos());
        ins->setFlag(FUN_START);
        ins->setFlag(BBL_START);

        if (ins = INSTRLIST->getPrevInstr(ins)) {
            ins->setFlag(FUN_END);
            ins->setFlag(BBL_END);
        }
    }
}

void SCFunctionList::deleteFunctions(SCFunction* first, SCFunction* last) {
    if (!first || !last)
        return;
    FunIterT fit = p_funs.begin();
    FunIterT lit = p_funs.end();
    if (fit==p_funs.end() || lit==p_funs.end())
        return;
    if (std::distance(fit,lit)<0)
        return;

    ++lit;
    for(FunIterT it=fit; it!=lit; ++it) {
        delete *it;
    }
    p_funs.erase(fit, lit);
}

void SCFunctionList::resolveEntrylessFunction() {
    for (FunIterT fit=p_funs.begin(); fit!=p_funs.end(); ++fit) {
        if ((*fit)->getEntryBlock()->getSucc().size() == 0) {
            for (BlockIterT bit=BLOCKLIST->getIterByBBL((*fit)->getFirstBlock()); 
                bit!=BLOCKLIST->getIterByBBL((*fit)->getLastBlock()); ++bit)
            {
                SCInstr* first = (*bit)->getFirstInstr();
                SCInstr* second = INSTRLIST->getNextInstr(first);
                // TODO: should restrict the oprand: push ebp; mov esp, ebp
                if (first->isPushClass() && second->isMovClass())
                {
                    EDGELIST->addBBLEdge((*fit)->getEntryBlock(), (*bit), ET_ENTRY);
                }
            }
        }
    }

    for (FunIterT fit=p_funs.begin(); fit!=p_funs.end(); ++fit) {
        if ((*fit)->getEntryBlock()->getSucc().size() == 0) {
            EDGELIST->addBBLEdge((*fit)->getEntryBlock(), (*fit)->getFirstBlock(), ET_ENTRY);
        }
    }
}

int SCFunctionList::getFunctionPos(SCFunction* fun) {
    FunIterT fit = std::find(p_funs.begin(), p_funs.end(), fun);
    return std::distance(p_funs.begin(), fit);
}

void SCFunctionList::serialize() {
    for(FunIterT fit=p_funs.begin(); fit!=p_funs.end(); ++fit) {
        (*fit)->serialize();
        SCLog(RL_ZERO, "");
    }
}
