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

void binaryAbstraction(SCSectionList *, SCSymbolListREL *, SCRelocationList *, char *[]);
void patchSecContent(SCSectionList *sl, SCSymbolListREL *sym_list, char *argv[]);
void disassembleExecutableSection(vector<INSTRUCTION*> *instr_list, SCSectionList *obj_sec_list);

int main(int argc, char *argv[])
{
    SCSectionList *obj_sec_list = new SCSectionList();
    SCSymbolListREL *sym_list = new SCSymbolListREL();
    SCRelocationList *rel_list = new SCRelocationList();
    
    binaryAbstraction(obj_sec_list, sym_list, rel_list, argv);
    
    vector<INSTRUCTION*> instr_list;
    disassembleExecutableSection(&instr_list, obj_sec_list);
    patchSecContent(obj_sec_list, sym_list, argv);
    
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
    obj_sec_list->allocateSectionsAddress();
    
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

void disassembleExecutableSection(vector<INSTRUCTION*> *instr_list, SCSectionList *obj_sec_list)
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
		INSTRUCTION *instr = (INSTRUCTION *)malloc(sizeof(INSTRUCTION));
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

		instr_list->push_back(instr);

		address += ret;
		start += ret;
	    }
	}
    }

    
    for (vector<INSTRUCTION*>::iterator itr = instr_list->begin(); itr != instr_list->end(); itr++)
    printf("%s  %-30s%-35s%d\n", int2str(&(*itr)->address, sizeof(INT32), 1, 0),
    (*itr)->ret_machineCode, (*itr)->assembly, (*itr)->secType);
}
