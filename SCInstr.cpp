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

 SCInstr::SCInstr() {

 }

 SCInstr::~SCInstr() {
    delete dest, src1, src2,src3;
    delete assembly, ret_machineCode, mnemonic;
    delete binary;
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


// ==== methods ====
bool SCInstr::isPCChangingClass() {
    return (type == FLOW_INSTRUCTION);
}

bool SCInstr::isCallClass() {
    return (instr_class==CLASS_CALLF || instr_class==CLASS_CALL);
}

bool SCInstr::isReturnClass() {
    return (instr_class==CLASS_RETN || instr_class==CLASS_RETF);
}

bool SCInstr::isHaltClass() {
    // TODO:
    return false;
}

bool SCInstr::isJumpClass() {
    // TODO:
    return false;
}

bool SCInstr::isAddClass() {
    return (instr_class == CLASS_ADD);
}

bool SCInstr::isAndClass() {
    return (instr_class == CLASS_AND);
}

bool SCInstr::isBranchClass() {
    // TODO:
    return false;
}

bool SCInstr::isFPClass() {
    return (type == FLOAT_INSTRUCTION);
}

bool SCInstr::isLeaClass() {
    return (instr_class == CLASS_LEA);
}

bool SCInstr::isLeaveClass() {
    return (instr_class == CLASS_LEAVE);
}

bool SCInstr::isLoopClass() {
    //TODO
    return false;
}

bool SCInstr::isMovClass() {
    return (instr_class == CLASS_MOV);
}

bool SCInstr::isNOPClass() {
    return (instr_class == CLASS_NOP);
}

bool SCInstr::isOPDIRClass() {
    // TODO:
    return false;
}

bool SCInstr::isOPOFFClass() {
    // TODO:
    return false;
}

bool SCInstr::isPopClass() {
    return (instr_class == CLASS_POP);
}

bool SCInstr::isPushClass() {
    return (instr_class == CLASS_PUSH);
}

bool SCInstr::isSubClass() {
    return (instr_class == CLASS_SUB);
}

bool SCInstr::isSyscallClass() {
    // TODO:
    return false;
}

bool SCInstr::isDataInstruction() {
    // currently no data instr
    return false;
}

bool SCInstr::isConditionalInstr() {
    // TODO: implement it.
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
        // 数据指令所在bbl的做法：
        // 1. 加一条从entry指向这个bbl的边
        // 2. 这个bbl指向HELL的边
        // 3. HELL指向bbl下一个块的边
        // 4. 这个bbl连接下一个bbl的边
    //     if ((*it)->isDataInstruction()) {
    //         INSTR_FUNCTION(*it)->setFlag(FUNCTION_DATA_INSTRUCTION_FLAG);
    //         if ((*it) != (*it)->getBlock()->getFirst()) {
    //             BLOCKLIST->divideBBLByInstr((*it)->getBlock(), *it)
    //         }
    //         // represents data in the text section
    //         (*it)->getBlock()->setType(BT_DATABLOCK);

    //         // the first bbl in a function
    //         if ((*it)->getBlock()==INSTR_FUNCTION(*it)->getFirst()) {
    //             (*it)->getBlock()->addEntryEdge();
    //         }

    //         if ((*it)->getNextInstr()!=NULL) {
    //             (*it)->getBlock()->addEdgeToHELL(ET_HELL);
    //             (*it)->getNextInstr()->getBlock()->addEdgeFromHELL(ET_HELLMAYBE);
    //             EDGELIST->addBBLEdge((*it)->getBlock(), (*it)->getNextInstr()->getBlock(), ET_DATALINK);
    //             Report(RP_TRIVIAL, "Added Hell edge for data function %s\n", (*it)->getBlock()->getFunction()->getName());
    //         }
    //         else {
    //             Report(RP_TRIVIAL, "Data instruction has no successor\n");
    //         }
    //         continue;
    //     }

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

    //     if ((*it)->isReturnClass()) {
    //         (*it)->getBlock()->setType(BT_RETURN);
    //         continue;
    //     }

    //     if ((*it)->isSyscallClass()) {

    //         SCBlock* newbbl = NULL;
    //         SCInstr* nextins = INSTRLIST->getNextInstr(*it);
    //         if ((*it) == ((*it)->getBlock()->getLastInstr())) {
    //             newbbl = (*it)->getBlock();
    //         }
    //         else {
    //             if (nextins != nextins->getBlock()->getFirstInstr()) {
    //             BLOCKLIST->divideBBLByInstr((*it)->getBlock(), nextins);
    //             }
    //             newbbl = (*it)->getBlock();
    //         }
    //         newbbl->setType(BT_SYSCALL);
    //     }
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
