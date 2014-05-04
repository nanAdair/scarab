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
#include <iterator>

#include "SCFunction.h"
#include "SCBlock.h"
#include "SCEdge.h"
#include "operand.h"

 SCInstr::SCInstr() :
     dest(NULL),
     src1(NULL),
     src2(NULL),
     src3(NULL),
     assembly(NULL),
     ret_machineCode(NULL),
     mnemonic(NULL),
     binary(NULL) {}

 SCInstr::~SCInstr() {
    //delete dest, src1, src2,src3;
    //delete assembly, ret_machineCode, mnemonic;
    //delete binary;
    //if (dest)
        //delete dest;
    //if (src1)
        //delete src1;
    //if (src2)
        //delete src2;
    //if (src3)
        //delete src3;
    //if (assembly)
        //delete assembly;
    //if (ret_machineCode)
        //delete ret_machineCode;
    //if (mnemonic)
        //delete mnemonic;
    //if (binary)
        //delete binary;
 }

 SCInstr::SCInstr(SCINSTR_INTERNAL_STRUCT tmp) {

    i_flags = 0;
    i_block = NULL;
    
    this->lockAndRepeat = tmp.lockAndRepeat;
    this->segmentOverride = tmp.segmentOverride;
    this->OperandSizeOverride = tmp.OperandSizeOverride;
    this->AddressSizeOverride = tmp.AddressSizeOverride;

    this->dest = tmp.dest;
    this->src1 = tmp.src1;
    this->src2 = tmp.src2;
    this->src3 = tmp.src3;

    this->mod = tmp.mod;
    this->rm = tmp.rm;
    this->regop = tmp.regop;

    this->address = tmp.address;
    this->final_address = tmp.final_address;

    this->type = tmp.type;
    this->instr_class = tmp.instr_class;
    this->pwd_affected = tmp.pwd_affected;
    this->pwd_used = tmp.pwd_used;
    this->opcode = tmp.opcode;
    this->ModRM = tmp.ModRM;
    this->SIB = tmp.SIB;
    this->assembly = tmp.assembly;
    this->ret_machineCode = tmp.ret_machineCode;
    this->mnemonic = tmp.mnemonic;

    this->new_cs = tmp.new_cs;
    this->new_eip = tmp.new_eip;
    this->size = tmp.size;
    this->handlerIndex = tmp.handlerIndex;
    this->binary = tmp.binary;
    this->next = tmp.next;
 }

void SCInstr::setFlag(IFLAG flag) {
    (this->i_flags) |= flag;
}

void SCInstr::removeFlag(IFLAG flag) {
    (this->i_flags) &= (~flag);
}

void SCInstr::setBlock(SCBlock* bbl) {
    this->i_block = bbl;
}

bool SCInstr::hasFlag(IFLAG flag) {
    return (bool)((this->i_flags) & flag);
}

SCBlock* SCInstr::getBlock() {
    return this->i_block;
}

UINT32 SCInstr::getAddr() {
    return this->address;
}

Operand* SCInstr::getDest() {
    return this->dest;
}

// ==== methods ====
bool SCInstr::isPCChangingClass() {
    return (type == FLOW_INSTRUCTION);
}

bool SCInstr::isCallClass() {
    return ((type==FLOW_INSTRUCTION) && (instr_class==CLASS_CALLF || instr_class==CLASS_CALL));
}

bool SCInstr::isReturnClass() {
    return ((type==FLOW_INSTRUCTION) && (instr_class==CLASS_RETN || instr_class==CLASS_RETF));
}

bool SCInstr::isJmpClass() {
    return ((type==FLOW_INSTRUCTION) && (instr_class==CLASS_JMP || instr_class==CLASS_JMPF || instr_class==CLASS_JMP_SHORT));
}

bool SCInstr::isConditionalJmpClass() {
    if (type == FLOW_INSTRUCTION) {
        if (instr_class<=CLASS_JG || instr_class==CLASS_JEXCZ)
            return true;
    }
    return false;
}

bool SCInstr::isLoopClass() {
    if (type == FLOW_INSTRUCTION) {
        if (instr_class==CLASS_LOOPDNE || instr_class==CLASS_LOOPDE || instr_class==CLASS_LOOPD)
            return true;
    }
    return false;
}

bool SCInstr::isMovClass() {
    return (type==NORMAL_INSTRUCTION && instr_class==CLASS_MOV);
}

bool SCInstr::isNOPClass() {
    return (type==IRREPLACEABLE_INSTRUCTION && instr_class==CLASS_NOP);
}

bool SCInstr::isPopClass() {
    return (type==STACK_OPERATE_INSTRUCTION && instr_class==CLASS_POP);
}

bool SCInstr::isPushClass() {
    return (type==STACK_OPERATE_INSTRUCTION && instr_class==CLASS_PUSH);
}

bool SCInstr::isSubClass() {
    return (type==NORMAL_INSTRUCTION && instr_class==CLASS_SUB);
}

bool SCInstr::isDataInstruction() {
    // currently no data instr
    return false;
}


bool SCInstr::isOnlyInstrInBBL() {
    if ( this->i_block->getFirstInstr() != this )
        return false;
    if ( this->i_block->getLastInstr() != this )
        return false;
    return true;
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

InstrListT SCInstrList::getInstrList() {
    return this->p_instrs;
}
InstrListT* SCInstrList::getInstrListPtr() {
    // WARNING:
    // ONLY use the ptr to edit the content
    // adding or deleting instr should ONLY use methods!!
    return &p_instrs;
}

void SCInstrList::setInstrList(InstrListT &ins) {
    (this->p_instrs).assign(ins.begin(), ins.end());
}

void SCInstrList::funResolveExitBlock() {
    InstrIterT instrIter;
    for(instrIter=p_instrs.begin(); instrIter!=p_instrs.end(); ++instrIter) {
        if ((*instrIter)->isReturnClass()) {
            EDGELIST->addBBLEdge((*instrIter)->getBlock(), INSTR_FUNCTION(*instrIter)->getExitBlock(), ET_EXIT);
            continue;
        }

        if ((*instrIter)->isDataInstruction() && 
                (*instrIter)->getBlock() == INSTR_FUNCTION(*instrIter)->getFirstBlock() && 
                (*instrIter)->getBlock() == INSTR_FUNCTION(*instrIter)->getLastBlock()) {
            EDGELIST->addBBLEdge((*instrIter)->getBlock(), INSTR_FUNCTION(*instrIter)->getExitBlock(), ET_EXIT);

                }
    }

    return;
}

void SCInstrList::resolveTargets() {
    for(InstrIterT it=p_instrs.begin(); it!=p_instrs.end(); ++it) {

        // 1: Normal instr
        if (!((*it)->isPCChangingClass())) {
            if ((*it)->hasFlag(BBL_END) && 
                !(EDGELIST->edgeExistOrNot((*it)->getBlock(), BLOCKLIST->getNextBBL((*it)->getBlock())))) {
                if (BLOCKLIST->getNextBBL((*it)->getBlock()) == NULL) {
                    // last bbl in the program
                    EDGELIST->addBBLEdge((*it)->getBlock(), HELL, ET_HELL);
                }
                else {
                    EDGELIST->addBBLEdge((*it)->getBlock(), BLOCKLIST->getNextBBL((*it)->getBlock()), ET_NORMAL);
                }
            }
            (*it)->getBlock()->setType(BT_NORMAL);
            continue;
        }

        // 2: Conditional branch instr
        if ((*it)->isConditionalJmpClass()) {
            SCBlock* bbl = (*it)->getBlock();
            SCBlock* nbbl = BLOCKLIST->getNextBBL(bbl);
            if (nbbl) {
                EDGELIST->addBBLEdge(bbl, nbbl, ET_FALSE);
            }
            UINT32 addr = (*it)->getDest()->getOperand();
            SCInstr *toIns = INSTRLIST->addrToInstr(addr);
            if (toIns) {
                EDGELIST->addBBLEdge(bbl, toIns->getBlock(), ET_TRUE);
            }
            // TODO: what if target ins is NULL
            continue;
        }

        // 3: Unconditional jump instr
        if ((*it)->isJmpClass()) {
            UINT32 addr = (*it)->getDest()->getOperand();
            SCInstr* toIns = INSTRLIST->addrToInstr(addr);
            if (toIns) {
                EDGELIST->addBBLEdge((*it)->getBlock(), toIns->getBlock(), ET_UNCOND);
            }
            // TODO: what if target ins is NULL
            continue;
        }

        // 4: Call instr
        if ((*it)->isCallClass()) {
            SCBlock* bbl = (*it)->getBlock();
            SCBlock* nbbl = BLOCKLIST->getNextBBL(bbl);
            UINT32 addr = (*it)->getDest()->getOperand();
            SCInstr* tins = INSTRLIST->addrToInstr(addr);
            if (tins) {
                EDGELIST->addBBLEdge(bbl, tins->getBlock(), ET_FUNCALL);
                if (nbbl) {
                    EDGELIST->addBBLEdge(tins->getBlock(), nbbl, ET_RETURN);
                }
            }
            if (nbbl) {
                EDGELIST->addBBLEdge(bbl, nbbl, ET_FUNLINK);
            }

            continue;
        }

        // 5: Return instr: edge has been added in 4
        if ((*it)->isReturnClass()) {
            (*it)->getBlock()->setType(BT_RETURN);
            continue;
        }

    }
}

SCInstr* SCInstrList::addrToInstr(UINT32 addr) {
    AddrInstrIterT it = p_hash.find(addr);
    return (it==p_hash.end())?(NULL):(it->second);
}

void SCInstrList::mapAddrToIns(SCInstr* ins) {
    p_hash.insert(AddrInstrPairT(ins->getAddr(), ins));
}

void SCInstrList::addInstrBack(SCInstr* ins) {
    if (!ins)
        return;
    p_instrs.push_back(ins);
    mapAddrToIns(ins);
}

void SCInstrList::addInsBeforeIns(SCInstr* ins, SCInstr* pivot) {
    if (!ins || !pivot)
        return;
    InstrIterT pit = std::find(p_instrs.begin(), p_instrs.end(), pivot);
    if (pit == p_instrs.end())
        return;

    p_instrs.insert(pit, ins);
    mapAddrToIns(ins);
}

void SCInstrList::addInsAfterIns(SCInstr* ins, SCInstr* pivot) {
    if (!ins || !pivot)
        return;
    InstrIterT pit = std::find(p_instrs.begin(), p_instrs.end(), pivot);
    if (pit == p_instrs.end())
        return;

    ++pit;
    p_instrs.insert(pit, ins);
    mapAddrToIns(ins);
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

void SCInstrList::deleteInstrs(SCInstr* first, SCInstr* last) {
    if (!first || !last)
        return;
    InstrIterT fit = std::find(p_instrs.begin(),p_instrs.end(),first);
    InstrIterT lit = std::find(p_instrs.begin(),p_instrs.end(),last);
    if (fit==p_instrs.end() || lit==p_instrs.end())
        return;
    if (std::distance(fit,lit)<0)
        return;

    ++lit;
    for(InstrIterT it=fit; it!=lit; ++it) {
        p_hash.erase((*it)->getAddr());
        delete *it;
    }
    p_instrs.erase(fit, lit);
}

void SCInstrList::constructCFG() {
    BLOCKLIST->markBBL();
    FUNLIST->markFunctions();
    BLOCKLIST->createBBLList();
    FUNLIST->createFunctionList();
    this->funResolveExitBlock();
    this->resolveTargets();
    FUNLIST->resolveEntrylessFunction();
}
