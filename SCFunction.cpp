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

#include "SCInstr.h"
#include "SCBlock.h"

SCFunction::SCFunction() {
    this->f_flags = 0;
    this->f_first = this->f_last = NULL;
    this->f_id = 0;     //TODO: global increase
    this->f_name = "";
    this->f_entry = this->f_exit = NULL;
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
void SCFunction::setName(string& name) {
    this->f_name = name;
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
string SCFunction::getName() {
    return this->f_name;
}
SCBlock* SCFunction::getEntryBlock() {
    return this->f_entry;
}
SCBlock* SCFunction::getExitBlock() {
    return this->f_exit;
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

void SCFunctionList::createFunctionList(BlockListT blockList) {
    BlockIterT bblIter;
    BlockListT bbls = BLOCKLIST->getBlockList();
    SCFunction *fun;
    for(bblIter=bbls.begin(); bblIter!=bbls.end(); ++bblIter) {
        if ((*bblIter)->getFirstInstr()->hasFlag(FUN_START)) {

            fun = new SCFunction();
            fun->setFirstBlock(*bblIter); 
            fun->setLastBlock(*bblIter);

            // TODO: find the function name 
            
            (this->p_funs).push_back(fun);
        }
        else if ((*bblIter)->getLastInstr()->hasFlag(FUN_END)) {
            fun->setLastBlock(*bblIter);
        }
        (*bblIter) -> setFunction(fun);
    }
    return;
}

void SCFunctionList::markFunctions() {
    // TODO: transplant it
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
