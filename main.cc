/*
 * =====================================================================================
 *
 *       SCFilename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 10:09:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include "section.h"
#include "symbol.h"
#include "relocation.h"
#include "file.h"
#include "disasm.h"
#include "upm.h"
#include "SCInstr.h"
#include "SCBlock.h"
#include "SCEdge.h"
#include "SCLog.h"

void binaryAbstraction(SCSectionList *, SCSymbolListREL *, SCRelocationList *, char *[]);
void patchSecContent(SCSectionList *sl, SCSymbolListREL *sym_list, char *argv[]);
void disassembleExecutableSection(SCSectionList *obj_sec_list);
SCPatchList *initUpm(SCSectionList *, SCRelocationList *);
INSTRUCTION *obfModify(InstrListT* instr_list);
void finalizeMemory(SCSectionList *,  InstrListT* , SCPatchList *, INSTRUCTION *);
void obfPatch(InstrListT* , INSTRUCTION *dumpInstr);

int main(int argc, char *argv[])
{
    SCSectionList *obj_sec_list = new SCSectionList();
    SCSymbolListREL *sym_list = SYMLISTREL;
    SCRelocationList *rel_list = new SCRelocationList();
    
    /* Binary Abstraction Stage */
    binaryAbstraction(obj_sec_list, sym_list, rel_list, argv);
    
    /* Disassembly Stage */
    disassembleExecutableSection(obj_sec_list);
    
    InstrListT* insListPtr = INSTRLIST->getInstrListPtr();

    /* Construct CFG */
    INSTRLIST->constructCFG();
    
    /* UPM Init Stage */
    SCPatchList *patch_list;
    patch_list = initUpm(obj_sec_list, rel_list);
    
    /* Obfuscation Stage */
    INSTRUCTION *dumpInstr = NULL;
    dumpInstr = obfModify(insListPtr);
    
    /* Address Patching and Date Written Back */
    finalizeMemory(obj_sec_list, insListPtr, patch_list, dumpInstr);
    
    /* Info Creation */
    patchSecContent(obj_sec_list, sym_list, argv);
    
    /* Generate Exec File */
    SCFileEXEC *exec = new SCFileEXEC();
    exec->prepare(obj_sec_list);
    exec->writeOut(obj_sec_list);

    //SCSection *sec;
    //sec = obj_sec_list.getSectionByName(INTERP_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(NOTE_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(DYNSYM_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(DYNSTR_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(HASH_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(GNR_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(REL_DYN_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(REL_PLT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(INIT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(PLT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(GOT_PLT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(FINI_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(RODATA_SECION_NAME);
    //sec = obj_sec_list.getSectionByName(TEXT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(SYMTAB_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(DYNAMIC_SECTION_NAME);
    //sec->testSecData();
}

SCPatchList *initUpm(SCSectionList *sl, SCRelocationList *rel_list)
{
    SCPatchList *patch_list = new SCPatchList();
    patch_list->initUPMRel(sl, rel_list);
    
    return patch_list;
}

INSTRUCTION *obfModify(InstrListT* inss)
{
    InstrIterT it;
    
    // INSTRUCTION *dumpInstr = (INSTRUCTION *)malloc(sizeof(INSTRUCTION));
    SCInstr* dumpInstr = new SCInstr();
    dumpInstr->size = 1;
    dumpInstr->binary = (INT8 *)malloc(dumpInstr->size);
    
    char data[] = {0xff};
    memcpy((char *)dumpInstr->binary, data, dumpInstr->size);
    
    for (it = inss->begin(); it != inss->end(); ++it) {
        if ((*it)->instr_class == CLASS_JMP && (*it)->secType != SECTION_PLT)
            break;
    }
    
    cout << hex << (*it)->address << endl;
    dumpInstr->secType = (*it)->secType;

    INSTRLIST->addInsAfterIns(*it, dumpInstr);
    
    return dumpInstr;
}

/* some odd code, cause there is no cfg information */
void obfPatch(InstrListT* instr_list, INSTRUCTION *dumpInstr)
{
    InstrIterT it;
    for (it = instr_list->begin(); it != instr_list->end(); ++it) {
        /* offset -= 1 */
        if (((*it)->instr_class == CLASS_JE || (*it)->instr_class == CLASS_JMP) && (*it)->address < dumpInstr->address && (*it)->final_address >= dumpInstr->address) {
            //cout << (*it)->address << " " << (*it)->dest->operand << " " ;
            (*it)->dest->operand += dumpInstr->size;
            
            memcpy((char *)(*it)->binary + 1, &(*it)->dest->operand, (*it)->dest->operand_size);
            //cout << (*it)->dest->operand << endl;
            
        }
        /* offset += 1 */
        else if (((*it)->instr_class == CLASS_JE || (*it)->instr_class == CLASS_JMP) && (*it)->address > dumpInstr->address && (*it)->final_address <= dumpInstr->address) {
            //cout << (*it)->address << " " << (*it)->dest->operand << " " ;
            
            (*it)->dest->operand -= dumpInstr->size;
            memcpy((char *)(*it)->binary + 1, &(*it)->dest->operand, (*it)->dest->operand_size);
            //cout << (*it)->dest->operand << endl;
        }
    }
}

/* TODO: bbl succ list error*/
int caculateJumpDisplacement(SCInstr *instr)
{
    SCInstr* target = instr->getBranchTarget();
    return INSTRLIST->getOffset(instr, target);

    // SCBlock* cur_block = instr->i_block;

    // EdgeIterT it;
    // cout << hex << "Current block is: " << cur_block << endl;
    // for (it = cur_block->getSucc().begin(); it != cur_block->getSucc().end(); it++) {
    //     cout << hex << "source block " <<(*it)->getFrom() << endl;
    // }
}

void updatePCRelativeJumps(InstrListT *instr_list)
{
    InstrIterT it;
    bool change = true;
    while (change) {
        change = false;
        int numChanged = 0;
        for (it = instr_list->begin(); it != instr_list->end(); it++) {
            if ((*it)->instr_class == CLASS_JE || (*it)->instr_class == CLASS_JMP) {
                /* patch address based on the cfg*/
                Operand* dest = (*it)->dest;
                if(dest->operand_size == RELATIVE_ADDRESS_SHORT) {
                    int offset;
                    offset = caculateJumpDisplacement(*it);
                    SCLog(RL_ONE, "CFG based patch: instr(%d), old disp(0x%x), new disp(0x%x)", (*it)->getPos(), dest->operand, offset);
                    dest->operand = offset;
                }
                
            }
        }
    }
}

void finalizeMemory(SCSectionList *sl, InstrListT* instr_list, SCPatchList *patch_list, SCInstr *dumpInstr)
{
    //InstrRelinkBasedOnBBL();

    int change = 0;
    
    do {
        sl->updateSectionSize(instr_list);
        sl->allocateSectionsAddress(0);
        sl->updateInstrAddress(instr_list);

        updatePCRelativeJumps(instr_list);
        
        change = patch_list->apply();
        cout << change << endl;
    } while (change > 0);
    
    if (dumpInstr) {
        obfPatch(instr_list, dumpInstr);
        cout << "obf patch here " << endl;
    }
    sl->updateSectionDataFromInstr(instr_list);
}

void binaryAbstraction(SCSectionList *obj_sec_list, SCSymbolListREL *sym_list, SCRelocationList *rel_list, char *argv[])
{
    char objname[100], soname[100];
    char ldname[100];
    strcpy(objname, argv[1]);
    strcpy(soname, argv[2]);
    strcpy(ldname, argv[3]);
    
    char **so_files;
    so_files = (char **)malloc(1 * sizeof(char *));
    so_files[0] = soname;
    
    SCFileREL temp;
    temp.init(objname);
    
    SCFileDYN tempso;
    tempso.init(soname);
    
    SCSectionList so_sec_list, merge_list;
    obj_sec_list->init(temp);
    so_sec_list.init(tempso);
    merge_list.mergeSections(obj_sec_list);
    
    SCSymbolListDYN so_sym_list, dynsym_list;
    sym_list->init(temp, obj_sec_list, &merge_list);
    
    rel_list->init(temp, obj_sec_list, &merge_list, sym_list);
    
    //当有多个so file时就用一个循环来调用这个函数生成符号表
    so_sym_list.init(tempso, &so_sec_list);
    //当有多个so file时就用一个循环来调用这个函数生成动态符号表
    dynsym_list.make(sym_list, &so_sym_list, rel_list);
    
    obj_sec_list->addSections((const char*)ldname, &dynsym_list, so_files, 1);
    obj_sec_list->allocateSectionsAddress(1);
    
    sym_list->updateSymbolValue(obj_sec_list);
    
    rel_list->applyRelocations(obj_sec_list, &dynsym_list);
    
    //SCSection *sec;
    //sec = obj_sec_list.getSectionByName(INTERP_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(NOTE_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(DYNSYM_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(DYNSTR_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(HASH_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(GNR_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(REL_DYN_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(REL_PLT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(INIT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(PLT_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(FINI_SECTION_NAME);
    //sec = obj_sec_list.getSectionByName(RODATA_SECION_NAME);
    //sec = obj_sec_list.getSectionByName(TEXT_SECTION_NAME);
    //sec->testSecData();
}

void patchSecContent(SCSectionList *sl, SCSymbolListREL *sym_list, char *argv[])
{
    char **so_files;
    so_files = (char **)malloc(1 * sizeof(char *));
    so_files[0] = argv[2];
    
    sl->renewSectionsInfo(so_files, 1);
    
    SCSection *symtab = sl->getSectionByName(SYMTAB_SECTION_NAME);
    sym_list->updateSymbolSection(symtab);
}

//void disassembleExecutableSection(vector<INSTRUCTION*> *instr_list, SCSectionList *obj_sec_list)
void disassembleExecutableSection(SCSectionList *obj_sec_list)
{
    vector<SCSection*> *sect = obj_sec_list->getSectionList();
    UINT8 buffer[MAX_INSTRUCTION_SIZE + 1];
    UINT32 base = obj_sec_list->getSectionByIndex(1)->getSecAddress();
    Disasm disasm;
    INT8 ret = -1;

    for (vector<SCSection*>::iterator itr = sect->begin(); itr != sect->end(); itr++){
	UINT32 flags = (*itr)->getSecFlags();
	if (flags & SHF_EXECINSTR){
	    UINT8* data = (*itr)->getSecData(), *secName = (*itr)->getSecName();
	    UINT32 size = MAX_INSTRUCTION_SIZE, address = (*itr)->getSecAddress();
	    UINT32 dataSize = (*itr)->getSecDatasize(), start = 0;

	    while (1){
		// INSTRUCTION *instr = (INSTRUCTION *)malloc(sizeof(INSTRUCTION));
        SCInstr* instr = new SCInstr();
		if (start + (INT32)MAX_INSTRUCTION_SIZE > dataSize){
		    size = dataSize - start + 1;
		    if ((INT32)MAX_INSTRUCTION_SIZE > dataSize)
			size -= 1;
		}
                memcpy(buffer, data + start, size);
		ret = disasm.disassembler((INT8*)buffer, size, address, base, instr);
		if (ret == NOT_ENOUGH_CODE)
		    break;

		if (strcmp((INT8*)secName, ".init") == 0)
		    instr->secType = SECTION_INIT;
		else if (strcmp((INT8*)secName, ".fini") == 0)
		    instr->secType = SECTION_FINI;
		else if (strcmp((INT8*)secName, ".text") == 0)
		    instr->secType = SECTION_TEXT;
		else if (strcmp((INT8*)secName, ".plt") == 0)
		    instr->secType = SECTION_PLT;
		else
		    instr->secType = SECTION_OTHER;

		INSTRLIST->addInstrBack(instr);

		address += ret;
		start += ret;
	    }
	}
    }

    
    //for (vector<INSTRUCTION*>::iterator itr = instr_list->getInstrList()->begin(); itr != instr_list->getInstrList()->end(); itr++)
    //printf("%s  %-30s%-35s%d\n", int2str(&(*itr)->address, sizeof(INT32), 1, 0),
    //(*itr)->ret_machineCode, (*itr)->assembly, (*itr)->secType);
}
