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
#include "section.h"
#include "symbol.h"
#include "relocation.h"
#include "file.h"

void binaryAbstraction(SCSectionList *, SCSymbolListREL *, SCRelocationList *, char *[]);
void patchSecContent(SCSectionList *sl, SCSymbolListREL *sym_list, char *argv[]);

int main(int argc, char *argv[])
{
    SCSectionList *obj_sec_list = new SCSectionList();
    SCSymbolListREL *sym_list = new SCSymbolListREL();
    SCRelocationList *rel_list = new SCRelocationList();
    
    binaryAbstraction(obj_sec_list, sym_list, rel_list, argv);
    //obj_sec_list.testSectionList();
    
    patchSecContent(obj_sec_list, sym_list, argv);
    
    SCFileEXEC *exec = new SCFileEXEC();
    exec->prepare(obj_sec_list);
    exec->writeOut(obj_sec_list);
    //cout << "sss" << endl;
    //sym_list.testSymbolList();
    
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
