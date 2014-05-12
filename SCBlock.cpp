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
#include <iterator>
#include <cstring>

#include "SCInstr.h"
#include "SCEdge.h"
#include "SCFunction.h"

int SCBlock::GlobalID = 0;

SCBlock::SCBlock() {
    b_type = BT_INVALID;
    b_flags = 0;
    b_first = b_last = NULL;
    b_id = ++this->GlobalID;
}
SCBlock::~SCBlock() {
    for(EdgeIterT it=b_pred.begin();it!=b_pred.end();++it) {
        delete *it;
    }
    for(EdgeIterT it=b_succ.begin();it!=b_succ.end();++it) {
        delete *it;
    }
    INSTRLIST->deleteInstrs(b_first, b_last);
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
        //printf("Warning: setFirstInstr(): instr == NULL!\n");
        return;
    }
    this->b_first = instr;
}

void SCBlock::setLastInstr(SCInstr* instr) {
    if (instr == NULL) {
        //printf("Warning: setLastInstr(): instr == NULL!\n");
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

SCFunction* SCBlock::getFunction() {
    return this->b_fun;
}

EdgeListT SCBlock::getSucc() {
    return b_succ;
}

EdgeListT SCBlock::getPred() {
    return b_pred;
}

void SCBlock::moveSuccEdgesToBBL(SCBlock* to) {
    to->getSucc().clear();
    for(EdgeIterT it=b_succ.begin(); it!=b_succ.end(); ++it) {
        (*it)->setFrom(to);
        to->getSucc().push_back(*it);
    }
    this->b_succ.clear();
}

void SCBlock::addSuccEdge(SCEdge* e) {
    b_succ.push_back(e);
}

void SCBlock::addPredEdge(SCEdge* e) {
    b_pred.push_back(e);
}

bool SCBlock::succBBLExistOrNot(SCBlock* bbl) {
    for(EdgeIterT it=b_succ.begin(); it!=b_succ.end(); ++it) {
        if ((*it)->getTo() == bbl)
            return true;
    }
    return false;
}

bool SCBlock::predBBLExistOrNot(SCBlock* bbl) {
    for(EdgeIterT it=b_pred.begin(); it!=b_pred.end(); ++it) {
        if ((*it)->getFrom() == bbl)
            return true;
    }
    return false;
}

void SCBlock::removePredEdge(SCEdge* edge) {
    EdgeIterT it = std::find(b_pred.begin(), b_pred.end(), edge);
    if (it!=b_pred.end()) {
        b_pred.erase(it);
    }
}

void SCBlock::removeSuccEdge(SCEdge* edge) {
    EdgeIterT it = std::find(b_succ.begin(), b_succ.end(), edge);
    if (it!=b_succ.end()) {
        b_succ.erase(it);
    }
}

int SCBlock::getPos() {
    return BLOCKLIST->getBBLPos(this);
}

void SCBlock::serialize(const char* prefix) {
    SCLog(RL_ZERO, "%s====SCBlock%d(0x%x)====", prefix, BLOCKLIST->getBBLPos(this), this);
    SCLog(RL_ZERO, "%sFirst instr: %d", prefix, INSTRLIST->getInstrPos(b_first));
    SCLog(RL_ZERO, "%sLast instr: %d", prefix, INSTRLIST->getInstrPos(b_last));

    // show neighbors, both pred and succ
    char neighbor[50] = {0};
    sprintf(neighbor, "Pred(%d): ", b_pred.size());
    for(EdgeIterT eit=b_pred.begin(); eit!=b_pred.end(); ++eit) {
        sprintf(neighbor+strlen(neighbor), "%d ", (*eit)->getFrom()->getPos());
    }
    SCLog(RL_ZERO, "%s%s", prefix, neighbor);

    neighbor[0] = 0;
    sprintf(neighbor, "Succ(%d): ", b_succ.size());
    for(EdgeIterT eit=b_succ.begin(); eit!=b_succ.end(); ++eit) {
        sprintf(neighbor+strlen(neighbor), "%d ", (*eit)->getTo()->getPos());
    }
    SCLog(RL_ZERO, "%s%s", prefix, neighbor);

    char np[100];
    strcpy(np, prefix);
    strcat(np, "\t");

    // show all the instrs within this bbl
    b_first->serialize(np);
    SCLog(RL_ZERO, "");
    if (b_first != b_last) {
        SCInstr* ins = b_first;
        while((ins=INSTRLIST->getNextInstr(ins)) != b_last) {
            ins->serialize(np);
            SCLog(RL_ZERO, "");
        }
        b_last->serialize(np);
    }

    SCLog(RL_ZERO, "%s====END=SCBlock%d(0x%x)====", prefix, BLOCKLIST->getBBLPos(this), this);
}

// ==== SCBlockList ====
static SCBlockList* _sharedBlockList = NULL;

SCBlockList::SCBlockList() {
    _sharedBlockList = this;
   
    // set up HELL block
    if (HELL) {
        FUNLIST->deleteFunctions(HELL->getFunction(), HELL->getFunction());
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



void SCBlockList::createBBLList() {
    InstrIterT iit;
    InstrListT instrs = INSTRLIST->getInstrList(); 
    SCBlock *bbl;
    for(iit=instrs.begin(); iit!=instrs.end(); ++iit) {
        // if ((*iit)->address == 0x804827a) {
        //     SCLog(RL_ONE, "BINGO! out");
        //     (*iit)->serialize();
        // }

        if((*iit)->hasFlag(BBL_START)) {
            // if ((*iit)->address == 0x804827a)
            //     SCLog(RL_ONE, "BINGO!");

            bbl = new SCBlock();
            bbl->setFirstInstr(*iit);
            bbl->setLastInstr(*iit);
            (this->p_bbls).push_back(bbl);
        }
        else if((*iit)->hasFlag(BBL_END)) {
            bbl->setLastInstr(*iit);
        }
        (*iit)->setBlock(bbl); 

    }
}

void SCBlockList::markBBL() {
    SCInstr* startins = (INSTRLIST->getInstrList()).front();
    startins->setFlag(BBL_START);
    
    InstrIterT iit, niit;
    InstrListT instrs = INSTRLIST->getInstrList();
    for(iit=instrs.begin(); iit!=instrs.end(); ++iit) {
        if ((*iit)->isPCChangingClass() || (*iit)->isDataInstruction()) {
            (*iit) -> setFlag(BBL_END);
            niit = iit;
            ++niit;
            if (niit != instrs.end()) {
                (*niit) -> setFlag(BBL_START);
            }
        }

        niit = iit;
        ++niit;
        if (niit == instrs.end()) {
            // Last instr
            (*iit) -> setFlag(BBL_END);
            (*iit) -> setFlag(FUN_END);
            break;
        }
    }
    return;
}

void SCBlockList::divideBBLByInstr(SCBlock* bbl, SCInstr* ins) {
    
    if (ins->hasFlag(BBL_START)) {
        // Report(RT_MAIN, "Attempt to devide BBL with an instruction that start a BBL\n");
        return;
    }
    
    SCBlock* nbbl = new SCBlock();
    nbbl->setType(bbl->getType());
    
    BlockIterT bblIt = std::find(p_bbls.begin(), p_bbls.end(), bbl);
    if (bblIt == p_bbls.end()) {
        // Report(RP_MAIN, "FATAL: bbl not in the list!");
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
    SCEdge* edge = EDGELIST->addBBLEdge(bbl, nbbl, ET_NORMAL);

    if (bbl == bbl->getFunction()->getLastBlock()) {
        bbl->getFunction()->setLastBlock(nbbl);
    }

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

BlockIterT SCBlockList::getIterByBBL(SCBlock* bbl) {
    return std::find(p_bbls.begin(), p_bbls.end(), bbl);
}

void SCBlockList::addBBLBeforeBBL(SCBlock* bbl, SCBlock* pivot) {
    // TODO
}

void SCBlockList::addBBLAfterBBL(SCBlock* bbl, SCBlock* pivot) {
    // TODO
}

void SCBlockList::addBBLBack(SCBlock* bbl) {
    // TODO
}

void SCBlockList::deleteBBLs(SCBlock* first, SCBlock* last) {
    if (!first || !last)
        return;
    BlockIterT fit = p_bbls.begin();
    BlockIterT lit = p_bbls.end();
    if (fit==p_bbls.end() || lit==p_bbls.end())
        return;
    if (std::distance(fit,lit)<0)
        return;

    ++lit;
    for(BlockIterT it=fit; it!=lit; ++it) {
        delete *it;
    }
    p_bbls.erase(fit, lit);
}

int SCBlockList::getBBLPos(SCBlock* bbl) {
    BlockIterT bit = std::find(p_bbls.begin(), p_bbls.end(), bbl);
    return std::distance(p_bbls.begin(), bit);
}

// void SCBlockList::removeBBLsFromList(SCBlock* first, SCBlock* last) {
//     if (!first || !last)
//         return;
//     BlockIterT fit = p_bbls.begin();
//     BlockIterT lit = p_bbls.end();
//     if (fit==p_bbls.end() || lit==p_bbls.end() || fit>lit)
//         return;
//     ++lit;
//     p_bbls.erase(fit, lit);
// }

void SCBlockList::serialize(const char *prefix) // prefix default to ""
{
    int i=0;
    for (BlockIterT bit=p_bbls.begin(); bit!=p_bbls.end(); ++bit)
    {
        // SCLog(RL_ONE, "BIT %d:", ++i);
        (*bit)->serialize(prefix);
        SCLog(RL_ZERO, "");
    }
}
