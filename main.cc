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

#include <iostream>
#include <string.h>
#include "file.h"
#include "section.h"
#include "symbol.h"

int main(int argc, char *argv[])
{
    char objname[100], soname[100];
    strcpy(objname, argv[1]);
    strcpy(soname, argv[2]);
    
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
    //sym_list.testSymbolList();
    so_sym_list.init(tempso, &so_sec_list);
    //sym_list.testSymbolList();
    //so_sym_list.testSymbolList();
    dynsym_list.make(&sym_list, &so_sym_list);
    dynsym_list.testSymbolList();
    
    //so_sec_list.testSectionList();
    //merge_list.testSectionList();
    //obj_sec_list.testSectionList();
    //SCSection *sec;
    //sec = obj_sec_list.get_section_by_name(".text");
    //sec = obj_sec_list.get_section_by_index(10);
    //printf("%s\n", sec->get_sec_name());
    //cout << sec->get_sec_name() << endl;
    //tempso.testDynsymTable();
    //temp.testSectionTable();
    //temp.testRelIndex();
    //temp.testSymTable();
}
