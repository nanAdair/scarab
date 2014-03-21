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
#include <stdlib.h>
#include "SCBlock.h"
#include "SCInstr.h"

SCFunction::SCFunction() {
    this->f_flags = FUNCTION_INVALID;
    this->f_first = this->f_last = NULL;
    this->f_id = 0;     //TODO: global increase
    this->f_name = "";
    this->f_entry = this->f_exit = NULL;
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
