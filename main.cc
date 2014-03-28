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
#include "file.h"
#include "section.h"
#include "symbol.h"
#include "relocation.h"

int main(int argc, char *argv[])
{
    char objname[100], soname[100];
    char ldname[100];
    strcpy(objname, argv[1]);
    strcpy(soname, argv[2]);
    strcpy(ldname, argv[3]);
    char *aaaa[100];
    aaaa[0] = argv[1];
    aaaa[1] = argv[2];
    
    SCFileREL temp;
    temp.init(objname);
    
    SCFileDYN tempso;
    tempso.init(soname);
    
    SCSectionList obj_sec_list, so_sec_list, merge_list;
    obj_sec_list.init(temp);
    so_sec_list.init(tempso);
    //obj_sec_list.testSectionList();
    merge_list.mergeSections(&obj_sec_list);
    
    SCSymbolListREL sym_list;
    SCSymbolListDYN so_sym_list, dynsym_list;
    sym_list.init(temp, &obj_sec_list, &merge_list);
    
    SCRelocationList rel_list;
    rel_list.init(temp, &obj_sec_list, &merge_list, &sym_list);
    // merge_list can be removed
    //rel_list.testRelocationList();
    //sym_list.testSymbolList();
    //当有多个so file时就用一个循环来调用这个函数生成符号表
    so_sym_list.init(tempso, &so_sec_list);
    //so_sym_list.testSymbolList();
    //当有多个so file时就用一个循环来调用这个函数生成动态符号表
    dynsym_list.make(&sym_list, &so_sym_list, &rel_list);
    //dynsym_list.testSymbolList();
    
    char **so_files;
    so_files = (char **)malloc(1 * sizeof(char *));
    so_files[0] = soname;
    obj_sec_list.addSections((const char*)ldname, &dynsym_list, so_files, 1);
    //obj_sec_list.testSectionList();
    
    /* test add section */
    //Elf32_Shdr sec_metadata = {
    //0, SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR, 0, 0, 0, 0, 0, 0x10, 0
    //};

    //char name[] = ".add";
    //UINT8 *buffer = (UINT8 *)malloc(0x20);
    //memset(buffer, 0x0, 0x20);
    //obj_sec_list.addOneXSection(&sec_metadata, name, (char *)buffer, 0x20);
    /* test add section */
    
    obj_sec_list.allocateSectionsAddress();
    //obj_sec_list.testSectionList();
    
    sym_list.updateSymbolValue(&obj_sec_list);
    //sym_list.testSymbolList();
    
    rel_list.applyRelocations(&obj_sec_list, &dynsym_list);

    obj_sec_list.testSectionList();
    sym_list.testSymbolList();
    rel_list.testRelocationList();
    
    //so_sec_list.testSectionList();
    //merge_list.testSectionList();
    
    /* Test the sec content here */
    //SCSection *sec;
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
    //sec->testSecData();
    
    //sec = obj_sec_list.get_section_by_index(10);
    //printf("%s\n", sec->get_sec_name());
    //cout << sec->get_sec_name() << endl;
    //tempso.testDynsymTable();
    //temp.testSectionTable();
    //temp.testRelIndex();
    //temp.testSymTable();
}
