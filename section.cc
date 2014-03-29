/*
 * =====================================================================================
 *
 *       Filename:  section.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2014 03:13:10 PM
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
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <cmath>
#include "section.h"
#include "sectionGD.h"

#include <fstream>
void SCSection::init(UINT8 *file_data, UINT8 *sec_strn_table)
{
    int name_length = strlen((const char *)(sec_strn_table + this->sec_name_offset));
    this->sec_name = (UINT8 *)malloc(name_length + 1);
    strcpy((char *)this->sec_name, (const char *)(sec_strn_table + this->sec_name_offset));
    this->sec_name[name_length] = '\0';

    this->sec_data = (UINT8 *)malloc(this->sec_datasize);
    memcpy(this->sec_data, file_data + this->sec_file_offset, this->sec_datasize);
}

SCSection *SCSection::mergeSection(SCSection *sec)
{
    UINT8 *buffer;
    int addition, target_datasize, source_datasize, target_newdatasize;
    target_datasize = this->sec_datasize;
    source_datasize = sec->sec_datasize;
    
    UINT32 source_align = sec->sec_align;
    addition = 0;
    while ((target_datasize + addition) % source_align != 0)
        addition++;
    target_newdatasize = target_datasize + addition + source_datasize;
    
    buffer = (UINT8 *)malloc(target_newdatasize);
    memset(buffer, 0x0, target_newdatasize);
    memcpy(buffer, this->sec_data, target_datasize);
    memcpy(buffer + target_datasize + addition, sec->sec_data, source_datasize);
    
    free(this->sec_data);
    this->sec_data = buffer;
    this->sec_datasize = target_newdatasize;
    this->sec_align = this->sec_align > source_align ? this->sec_align : source_align;
    
    sec->sec_mergeto = this;
    sec->sec_delta = target_datasize + addition;
    
    return sec;
}

int SCSection::getDynamicAttributeData(int tag) const
{
    int i, number;
    number = this->sec_datasize / this->sec_entsize;
    
    for (i = 0; i < number; i++) {
        Elf32_Dyn *cur_dyn;
        cur_dyn = (Elf32_Dyn *)(this->sec_data + this->sec_entsize * i);
        if (cur_dyn->d_tag == tag) {
            return cur_dyn->d_un.d_val;
        }
    }
}

void SCSection::setSecContent(int offset, char *data, int size)
{
    memcpy(this->sec_data + offset, data, size);
}

void SCSection::setInterpData(const char *ld_file)
{
    int length;
    length = strlen(ld_file);
    this->sec_data = (UINT8 *)malloc(length + 1);
    memset(this->sec_data, 0x0, length + 1);
    this->sec_datasize = length + 1;
    strcpy((char *)this->sec_data, ld_file);
}

void SCSection::setDynstrData(SCSymbolListDYN* sym_list, char **so_files, int number)
{
    int length;
    
    /* Allocat the first 0x0 here */
    this->sec_data = (UINT8 *)malloc(1);
    memset(this->sec_data, 0x0, 1);
    this->sec_datasize = 1;
    
    /* Add the so files names */
    for (int i = 0; i < number; i++) {
        length = strlen(so_files[i]);
        this->expandSecData(so_files[i], length + 1, 1);
    }
    
    /* Add dynamic symbol names 
     * skip the first NULL symbol */
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin() + 1; it != sym_list->getSymbolList()->end(); ++it) {
        length = strlen((char *)(*it)->getSymbolName());
        /* this is the offset, can be setteld here */
        (*it)->setSymbolNameOffset(this->sec_datasize);
        this->expandSecData((char *)(*it)->getSymbolName(), length + 1, 1);
    }
    
    /* Add version names 
     * skip the first NULL symbol*/
    map<UINT8*, int> ver;
    map<UINT8*, int>::iterator vit;
    for (it = sym_list->getSymbolList()->begin() + 1; it != sym_list->getSymbolList()->end(); ++it) {
        if ((*it)->getSymbolVersionName() == NULL)
            continue;
        
        vit = ver.find((*it)->getSymbolVersionName());
        if (vit != ver.end())
            continue;

        length = strlen((char *)(*it)->getSymbolVersionName());
        this->expandSecData((char *)(*it)->getSymbolVersionName(), length + 1, 1);
        ver[(*it)->getSymbolVersionName()] = 1;
    }
}

void SCSection::setDynsymData(SCSymbolListDYN *sym_list)
{
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        Elf32_Sym *temp;
        temp = (Elf32_Sym *)malloc(sizeof(Elf32_Sym));
        temp->st_name = (*it)->getSymbolNameOffset();
        temp->st_value = (*it)->getSymbolValue();
        temp->st_size = (*it)->getSymbolSize();
        temp->st_info = ((*it)->getSymbolBinding() << 4) + ((*it)->getSymbolType() & 0xf);
        temp->st_other = (*it)->getSymbolOther();
        temp->st_shndx = (*it)->getSymbolShndx();
        
        this->expandSecData((char *)temp, sizeof(Elf32_Sym), 1);
        
        free(temp);
    }
}

void SCSection::setHashData(SCSymbolListDYN *sym_list)
{
    int number = 0;
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        number++;
    }
    
    int nbuckets, nchains;
    nchains = number;
    nbuckets = (int)log2(number) + 1;
    int datasize = (1 + 1+ nbuckets + nchains) * 4;

    UINT8 *buffer;
    buffer = (UINT8 *)malloc(datasize);
    memset(buffer, 0x0, datasize);
    
    memcpy(buffer, &nbuckets, sizeof(int));
    memcpy(buffer + 4, &nchains, sizeof(int));
    
    for (it = sym_list->getSymbolList()->end() - 1; it != sym_list->getSymbolList()->begin(); --it) {
        int hashvalue = this->calculateHash((*it)->getSymbolName());
        int order, index, symbolIndex;
        order = hashvalue % nbuckets;
        index = *(int *)((buffer + 8 + order * 4));
        symbolIndex = (*it)->getSymbolIndex();
        if (index == 0)
            memcpy(buffer + 8 + order * 4, &symbolIndex, sizeof(int));
        else {
            order = index;
            index = *(int *)((buffer + 8 + nbuckets * 4 + order * 4));
            while (index) {
                order = index;
                index = *(int *)((buffer + 8 + nbuckets * 4 + order * 4));
            }
            memcpy(buffer + 8 + nbuckets * 4 + order * 4, &symbolIndex, 4);
        }
    }
    
    this->expandSecData((char *)buffer, datasize, 1);
    free(buffer);
}

void SCSection::setGVData(SCSymbolListDYN *sym_list)
{
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        UINT16 ver;
        ver = (*it)->getSymbolVersion();
        
        this->expandSecData((char *)&ver, sizeof(UINT16), 1);
    }
}

void SCSection::setGNRData(SCSymbolListDYN *sym_list, char **so_files, int number, SCSection *dynstr)
{
    for (int i = 0; i < number; i++) {
        vector<SCSymbolDYN*>::iterator it;
        int ver_number = 0;
        
        /* Store the versions <name, number>*/
        map<UINT8*, int> ver;
        map<UINT8*, int>::iterator vit;
        
        /* Have to skip the first NULL symbol */
        for (it = sym_list->getSymbolList()->begin() + 1; it != sym_list->getSymbolList()->end(); ++it) {
            if ((*it)->getSymbolVersionName() == NULL || 
                    strcmp((char *)(*it)->getSymbolFile(), so_files[i]))
                continue;
            
            vit = ver.find((*it)->getSymbolVersionName());
            if (vit != ver.end())
                continue;
            ver[(*it)->getSymbolVersionName()] = (*it)->getSymbolVersion();
            ver_number++;
        }
        
        Elf32_Verneed verneed;
        verneed.vn_version = 1;
        verneed.vn_cnt = ver_number;
        verneed.vn_file = this->findOffset(dynstr, so_files[i]);
        verneed.vn_aux = 0x10;
        verneed.vn_next = (i == number - 1) ? 0 : sizeof(Elf32_Vernaux) * ver_number;
        this->expandSecData((char *)&verneed, sizeof(Elf32_Verneed), 1);
        
        for (vit = ver.begin(); vit != ver.end(); ++vit) {
            Elf32_Vernaux vernaux;
            UINT8 *version_name;
            UINT16 version_number;
            version_name = vit->first;
            version_number = vit->second;
            
            vernaux.vna_hash = this->calculateHash(version_name);
            vernaux.vna_flags = 0;
            vernaux.vna_other = version_number;
            vernaux.vna_name = this->findOffset(dynstr, (char *)version_name);
            
            if ((++vit) == ver.end())
                vernaux.vna_next = 0;
            else
                vernaux.vna_next = 0x10;
            --vit;
            this->expandSecData((char *)&vernaux, sizeof(Elf32_Vernaux), 1);
        }
    }
}

void SCSection::setPLTData(SCSymbolListDYN *sym_list)
{
    /* Add the first three instructions */
    this->addPLTTop();
    
    vector<SCSymbolDYN*>::iterator it;
    int n = 0;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if (!((*it)->getSymbolSdType() & SYM_PLT))
            continue;
        Instr instr[3];
        int offset = 0;
        
        instr[0].opcode = 0x25ff;
        instr[0].oprand = 0x0;
        instr[1].opcode = 0x68;
        instr[1].oprand = n * 0x8;
        instr[2].opcode = 0xe9;
        instr[2].oprand = 0x0;
        
        /* sizeof(Instr) is 8 instead of 6 because of alignment */
        UINT8 *buffer;
        buffer = (UINT8 *)malloc(0x10);
        memset(buffer, 0x0, 0x10);
        memcpy(buffer + offset, &(instr[0].opcode), 2);
        offset += 2;
        memcpy(buffer + offset, &(instr[0].oprand), 4);
        offset += 4;
        
        for (int i = 1; i < 3; i++) {
            memcpy(buffer + offset, &(instr[i].opcode), 1);
            offset += 1;
            memcpy(buffer + offset, &(instr[i].oprand), 4);
            offset += 4;
        }
        this->expandSecData((char *)buffer, 0x10, 1);
        
        free(buffer);
        n++;
    }
}

void SCSection::setGOTPLTData(SCSymbolListDYN *sym_list)
{
    UINT8 *buffer;
    buffer = (UINT8 *)malloc(0xc);
    memset(buffer, 0x0, 0xc);
    
    this->expandSecData((char *)buffer, 0xc, 1);
    free(buffer);
    
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if (!((*it)->getSymbolSdType() & SYM_PLT))
            continue;
        
        buffer = (UINT8 *)malloc(0x4);
        memset(buffer, 0x0, 0x4);
        this->expandSecData((char *)buffer, 0x4, 1);
        free(buffer);
    }
}

void SCSection::setRELPLTData(SCSymbolListDYN *sym_list)
{
    int index = 0;
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if (!((*it)->getSymbolSdType() & SYM_PLT))
            continue;
        Elf32_Rel rel;
        
        rel.r_offset = 0xc + 0x4 * index;
        rel.r_info = ((*it)->getSymbolIndex() << 8) + R_386_JMP_SLOT;
        
        this->expandSecData((char *)&rel, sizeof(Elf32_Rel), 1);
        index++;
    }
}

void SCSection::setGOTData(SCSymbolListDYN *sym_list)
{
    int index = 0;
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if (!((*it)->getSymbolSdType() & SYM_GOT))
            continue;
        
        UINT8 *buffer;
        buffer = (UINT8 *)malloc(0x4);
        memset(buffer, 0x0, 0x4);
        this->expandSecData((char *)buffer, 0x4, 1);
        free(buffer);
    }
}

void SCSection::setRELGOTData(SCSymbolListDYN *sym_list)
{
    int index = 0;
    vector<SCSymbolDYN*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        if (!((*it)->getSymbolSdType() & SYM_GOT))
            continue;
        Elf32_Rel rel;
        
        rel.r_offset = 0x4 * index;
        rel.r_info = ((*it)->getSymbolIndex() << 8) + R_386_GLOB_DAT;
        
        this->expandSecData((char *)&rel, sizeof(Elf32_Rel), 1);
        index++;
    }
}

void SCSection::setDynamicData(int number)
{
    UINT8 *buffer;
    int datasize;
    datasize = DYNAMIC_ENTSIZE * (DYNAMIC_NUMBER + number);
    buffer = (UINT8 *)malloc(datasize);
    memset(buffer, 0x0, datasize);
    
    this->expandSecData((char *)buffer, datasize, 1);
    free(buffer);
}

void SCSection::setShstrData(SCSectionList *sec_list)
{
    free(this->sec_data);
    this->sec_data = NULL;
    this->sec_datasize = 0;
    
    vector<SCSection*>::iterator it;
    for (it = sec_list->getSectionList()->begin(); it != sec_list->getSectionList()->end(); ++it) {
        int length = strlen((char *)(*it)->getSecName());
        (*it)->setSecNameOffset(this->sec_datasize);
        this->expandSecData((char *)(*it)->getSecName(), length + 1, 1);
    }
}

UINT32 SCSection::getSecOrderScore()
{
    int n;
    n = this->sec_misc ? 50 : 0;
    n += this->getSecIndex();
    
    /* NULL section: 0 */
    if (this->sec_type == SHT_NULL)
        return 0;
    
    /* .interp 1 */
    if (!strcmp((char *)this->sec_name, INTERP_SECTION_NAME))
        return 1;
    
    /* .note.ABI-tag 2 */
    if (!strcmp((char *)this->sec_name, NOTE_SECTION_NAME))
        return 2;

    /* A: +1000 */
    if (this->sec_flags == SHF_ALLOC)
        return 1000 + n;
    
    /* AX: +1000*/
    if (this->sec_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 1000 + n;
    
    /* WA: + 2000 */
    if (this->sec_flags == (SHF_ALLOC | SHF_WRITE))
        return 2000 + n;
    
    /* STR: +3000 */
    if (this->sec_flags == SHF_STRINGS)
        return 3000 + n;
    
    /* Symbol Table: +7000 */
    if (this->sec_type == SHT_SYMTAB)
        return 7000 + n;
    
    /* String Table: +8000 */
    if (this->sec_type == SHT_STRTAB)
        return 8000 + n;
    
    return 6000 + n;
}

void SCSection::renewRELSection(UINT32 address)
{
    int number = this->sec_datasize / this->sec_entsize;
    
    for (int i = 0; i < number; i++) {
        Elf32_Rel *cur_rel;
        cur_rel = (Elf32_Rel *)(this->sec_data + this->sec_entsize * i);
        cur_rel->r_offset += address;
    }
}

void SCSection::renewPLTSection(UINT32 address)
{
    int number = this->sec_datasize / 0x10;
    UINT32 plt_sec_address, gotplt_sec_address;
    plt_sec_address = this->sec_address;
    gotplt_sec_address = address;
    
    UINT32 value1, value2;
    value1 = gotplt_sec_address + 4;
    value2 = gotplt_sec_address + 8;
    
    this->setSecContent(2, (char *)&value1, sizeof(UINT32));
    this->setSecContent(8, (char *)&value2, sizeof(UINT32));
    
    for (int i = 1; i < number; i++) {
        int offset;
        offset = i * 0x10;
        
        UINT32 d_address;
        d_address = gotplt_sec_address + 0xc + (i - 1) * 4;
        this->setSecContent(offset + 2, (char *)&d_address, sizeof(UINT32));
        
        int value;
        UINT32 e_address;
        e_address = plt_sec_address + 0x10 * (i + 1);
        value = plt_sec_address - e_address;
        this->setSecContent(offset + 0xc, (char *)&value, sizeof(int));
    }
}

void SCSection::renewGOTPLTSection(UINT32 addr_dynamic, UINT32 addr_plt)
{
    int number = this->sec_datasize / this->sec_entsize;
    
    this->setSecContent(0, (char *)&addr_dynamic, sizeof(UINT32));
    
    for (int i = 3; i < number; i++) {
        int offset;
        offset = i * this->sec_entsize;
        
        UINT32 address;
        address = addr_plt + (i - 3 + 1) * 0x10 + 6;
        this->setSecContent(offset, (char *)&address, sizeof(UINT32));
    }
}

void SCSection::renewDynamicSection(SCSectionList *sl, char *file[], int num)
{
    SCSection *gotplt, *plt, *got, *dynsym, *dynstr, *relgot, *relplt, *hash;
    SCSection *init, *fini, *fini_array, *init_array, *gv, *gnr;
    
    gotplt = sl->getSectionByName(GOT_PLT_SECTION_NAME);
    plt = sl->getSectionByName(PLT_SECTION_NAME);
    got = sl->getSectionByName(GOT_SECTION_NAME);
    dynsym = sl->getSectionByName(DYNSYM_SECTION_NAME);
    relgot = sl->getSectionByName(REL_DYN_SECTION_NAME);
    relplt = sl->getSectionByName(REL_PLT_SECTION_NAME);
    dynstr = sl->getSectionByName(DYNSTR_SECTION_NAME);
    hash = sl->getSectionByName(HASH_SECTION_NAME);
    init = sl->getSectionByName(INIT_SECTION_NAME);
    fini = sl->getSectionByName(FINI_SECTION_NAME);
    fini_array = sl->getSectionByName(FINI_ARRAY_SECTION_NAME);
    init_array = sl->getSectionByName(INIT_ARRAY_SECTION_NAME);
    gv = sl->getSectionByName(GV_SECTION_NAME);
    gnr = sl->getSectionByName(GNR_SECTION_NAME);

    int number = sizeof(DynamicSectionInfo) / sizeof(Elf32_Dyn);
    
    for (int i = 0; i < number; i++) {
        Elf32_Dyn *dyn_item;
        dyn_item = (Elf32_Dyn *)(this->sec_data + i * sizeof(Elf32_Dyn));
        
        int tag;
        tag = DynamicSectionInfo[i].d_tag;
        dyn_item->d_tag = tag;
        
        switch(tag) {
            case DT_PLTGOT:
                dyn_item->d_un.d_ptr = gotplt->sec_address;
                break;
            case DT_PLTRELSZ:
                dyn_item->d_un.d_val = relplt->sec_datasize;
                break;
            case DT_JMPREL:
                dyn_item->d_un.d_ptr = relplt->sec_address;
                break;
            case DT_PLTREL:
                // UNFIEXED: REL IS NOT 0x11
                dyn_item->d_un.d_val = 0x11;
                break;
            case DT_REL:
                dyn_item->d_un.d_ptr = relgot->sec_address;
                break;
            case DT_RELSZ:
                dyn_item->d_un.d_val = relgot->sec_datasize;
                break;
            case DT_RELENT:
                // seems to be a fixed value;
                dyn_item->d_un.d_val = relgot->sec_entsize;
                break;
            case DT_DEBUG:
                dyn_item->d_un.d_ptr = 0x0;
                break;
            case DT_SYMTAB:
                dyn_item->d_un.d_ptr = dynsym->sec_address;
                break;
            case DT_SYMENT:
                dyn_item->d_un.d_val = dynsym->sec_entsize;
                break;
            case DT_STRTAB:
                dyn_item->d_un.d_ptr = dynstr->sec_address;
                break;
            case DT_STRSZ:
                dyn_item->d_un.d_val = dynstr->sec_datasize;
                break;
            case DT_HASH:
                dyn_item->d_un.d_ptr = hash->sec_address;
                break;
            case DT_NEEDED:
                // TODO: UNFIEXED: hard-code here
                dyn_item->d_un.d_val = this->findOffset(dynstr, file[0]);
                /*dyn_item->d_un.d_val = FindOffset(dynstr, "/usr/lib/libc.so.6");*/
                break;
            case DT_INIT:
                dyn_item->d_un.d_ptr = init->sec_address;
                break;
            case DT_FINI:
                dyn_item->d_un.d_ptr = fini->sec_address;
                break;
            case DT_FINI_ARRAY:
                dyn_item->d_un.d_ptr = fini_array->sec_address;
                break;
            case DT_FINI_ARRAYSZ:
                dyn_item->d_un.d_val = fini_array->sec_datasize;
                break;
            case DT_INIT_ARRAY:
                dyn_item->d_un.d_ptr = init_array->sec_address;
                break;
            case DT_INIT_ARRAYSZ:
                dyn_item->d_un.d_val = init_array->sec_datasize;
                break;
            case DT_VERSYM:
                dyn_item->d_un.d_ptr = gv->sec_address;
                break;
            case DT_VERNEED:
                dyn_item->d_un.d_ptr = gnr->sec_address;
                break;
            case DT_VERNEEDNUM:
                // TODO: UNFIEXED: hard-code here
                dyn_item->d_un.d_val = num;
                break;
            case DT_NULL:
                dyn_item->d_un.d_val = 0x0;
                break;
            default:
                //printf("error in finding dynamic section item\n");
                cout << "error in finding dynamic section item" << endl;
                break;
        }
    }
}

void SCSection::addPLTTop()
{
    Instr instr[2];
    int i, offset;
    
    UINT8 *buffer;
    buffer = (UINT8 *)malloc(0x10);
    memset(buffer, 0x0, 0x10);
    
    instr[0].opcode = 0x35ff;
    instr[0].oprand = 0x0;
    instr[1].opcode = 0x25ff;
    instr[1].oprand = 0x0;
    
    offset = 0;
    for (i = 0; i < 2; i++) {
        memcpy(buffer + offset, &(instr[i].opcode), 0x2);
        offset += 2;
        memcpy(buffer + offset, &(instr[i].oprand), 0x4);
        offset += 4;
    }
    
    this->sec_data = buffer;
    this->sec_datasize = 0x10;
}

int SCSection::findOffset(SCSection *dynstr, char *str)
{
    UINT8 *data;
    data = dynstr->getSecData();
    int offset = 0;
    while (strcmp(str, (char *)data) != 0){
        data++;
        offset++;
    }
    
    return offset;
}

UINT32 SCSection::calculateHash(const UINT8 *name)
{
    UINT32 h = 0, g;
    
    while (*name) {
        h = (h << 4) + *name++;
        if (g = h & 0xf0000000)
            h ^= g >> 24;
        h &= ~g;
    }
    return h;
}

void SCSection::expandSecData(char *data, int datasize, int flag)
{
    UINT8 *buffer;
    int newdatasize = this->sec_datasize + datasize;
    buffer = (UINT8 *)malloc(newdatasize);
    memset(buffer, 0x0, newdatasize);
    memcpy(buffer, this->sec_data, this->sec_datasize);
    memcpy(buffer + this->sec_datasize, data, datasize);
    
    free(this->sec_data);
    this->sec_data = buffer;
    if (flag)
        this->sec_datasize = newdatasize;
}

void SCSection::testSecData()
{
    ofstream os;
    os.open("testSec", ofstream::binary);
    
    os.write((const char*)this->sec_data, this->sec_datasize);
    os.close();
}

void SCSectionList::init(SCFile &file)
{
    Elf32_Shdr *cur_sec_dr;
    UINT8 *sec_strn_table, *file_data;
    
    sec_strn_table = file.getSectionStrnTable();
    file_data = file.getFileData();
    SCSection *sec;
    
    for (int i = 0; i < file.getSectionNumber(); i++) {
        cur_sec_dr = file.getSectionTable() + i;
        sec = new SCSection(cur_sec_dr, i);
        sec->init(file_data, sec_strn_table);
        this->sec_list.push_back(sec);
    }
}

SCSection* SCSectionList::getSectionByName(const char *name)
{
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        UINT8 *sec_name = (*it)->getSecName();
        if (!strcmp((const char*)sec_name, name))
            return *it;
    }
    
    return NULL;
}

SCSection *SCSectionList::getSectionByIndex(const int index)
{
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        if ((*it)->getSecIndex() == index)
            return *it;
    }
    
    return NULL;
}

/* The object is the list of sections deleted from parameter sl*/
void SCSectionList::mergeSections(SCSectionList *sl)
{
    int i = 0;
    SCSection *text;
    text = sl->getSectionByName(".text");
    
    vector<SCSection*>::iterator it;
    for (it = sl->sec_list.begin(); it != sl->sec_list.end(); ++it) {
        SCSection *cur_sec, *last_sec;
        if ((*it)->sec_flags & SHF_MERGE) {
            if (!strcmp((const char *)(*it)->sec_name, ".comment")) {
                continue;
            }
            else {
                SCSection *sec = (*(it-1))->mergeSection(*it);
                this->sec_list.push_back(*it);
                sl->sec_list.erase(it);
                --it;
            }
        }
        
        if ((*it)->sec_flags & SHF_EXECINSTR && !this->skipXSection((*it)->sec_name)) {
            SCSection *sec = text->mergeSection(*it);
            this->sec_list.push_back(*it);
            sl->sec_list.erase(it);
            --it;
        }
    }
}


void SCSectionList::addOneXSection(Elf32_Shdr *sec_shdr, char *name, char *data, int datasize)
{
    SCSection *sec, *text;
    sec = this->addOneSection(sec_shdr, name, data, datasize);
    
    text = this->getSectionByName(TEXT_SECTION_NAME);
    sec->setSecInitIndex(text->getSecIndex() + 1);
    sec->setSecMisc(sec->getSecIndex());
}

SCSection *SCSectionList::addOneSection(Elf32_Shdr *sec_shdr, char *name, char *data, int datasize)
{
    vector<SCSection*>::iterator it = this->sec_list.end();
    int index = (*--it)->getSecIndex() + 1;

    SCSection *sec = new SCSection(sec_shdr, index);
    sec->setSecName((const char *)name);
    
    sec->expandSecData(data, datasize, 1);
    this->sec_list.push_back(sec);
    
    return sec;
}

void SCSectionList::createSections()
{
    vector<SCSection*>::iterator it = this->sec_list.end();
    int index = (*--it)->getSecIndex() + 1;
    
    for (int i = 0; i < ADDEDSECTIONNUMBER; i++) {
        SCSection *sec = new SCSection(AddedSectionsInfo + i, index + i);
        sec->setSecName((const char *)(AddedSectionsName[i]));
        
        /* Reset the misc of new sections to 0 */
        sec->setSecMisc(0);
        this->sec_list.push_back(sec);
    }
}

void SCSectionList::addSections(const char *ld_file, SCSymbolListDYN *sym_list, char **so_files, int number)
{
    this->createSections();
    vector<SCSection*>::iterator it;
    
    SCSection *dynstr, *init;
    dynstr = this->getSectionByName(DYNSTR_SECTION_NAME);
    dynstr->setDynstrData(sym_list, so_files, number);
    
    init = this->getSectionByName(INIT_SECTION_NAME);
    
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        if (!strcmp((const char *)(*it)->getSecName(), INTERP_SECTION_NAME)) {
            (*it)->setInterpData(ld_file);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), DYNSYM_SECTION_NAME)) {
            (*it)->setDynsymData(sym_list);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), HASH_SECTION_NAME)) {
            (*it)->setHashData(sym_list);
            (*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), GV_SECTION_NAME)) {
            (*it)->setGVData(sym_list);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), GNR_SECTION_NAME)) {
            (*it)->setGNRData(sym_list, so_files, number, dynstr);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), PLT_SECTION_NAME)) {
            (*it)->setPLTData(sym_list);
            
            /* Modify the PLT misc and index here
             * Used when get the section score*/
            (*it)->setSecMisc(init->getSecMisc());
            (*it)->setSecInitIndex(init->getSecIndex());
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), GOT_PLT_SECTION_NAME)) {
            (*it)->setGOTPLTData(sym_list);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), REL_PLT_SECTION_NAME)) {
            (*it)->setRELPLTData(sym_list);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), GOT_SECTION_NAME)) {
            (*it)->setGOTData(sym_list);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), REL_DYN_SECTION_NAME)) {
            (*it)->setRELGOTData(sym_list);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), DYNAMIC_SECTION_NAME)) {
            (*it)->setDynamicData(number);
            //(*it)->testSecData();
        }
        if (!strcmp((const char *)(*it)->getSecName(), SHSTRTAB_SECTION_NAME)) {
            (*it)->setShstrData(this);
            //(*it)->testSecData();
        }
    }
}

void SCSectionList::allocateSectionsAddress()
{
    UINT32 base_addr, offset;
    base_addr = 0x8048000;
    offset = 0x114;
    UINT32 addend = 0;
    
    this->sortSections();
    
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin() + 1; it != this->sec_list.end(); ++it) {
        UINT32 align = 1;
        align = (*it)->getSecAlign() ? (*it)->getSecAlign() : 1;
        int addition = 0;
        while ((offset + addition) % align != 0)
            addition++;
        
        if (addition) {
            UINT8 *buffer;
            buffer = (UINT8 *)malloc(addition);
            memset(buffer, 0x0, addition);
            (*it)->expandSecData((char *)buffer, addition, 0);
            free(buffer);
            offset += addition;
        }
        
        if ((*it)->getSecFlags() & SHF_WRITE)
            addend = 0x1000;
        if ((*it)->getSecFlags() & SHF_ALLOC)
            (*it)->setSecAddress(base_addr + offset + addend);
        else
            (*it)->setSecAddress(0);
        
        (*it)->setSecFileOffset(offset);
        
        if (strcmp((char *)(*it)->getSecName(), BSS_SECTION_NAME))
            offset += (*it)->getSecDatasize();
    }
}

void SCSectionList::renewSectionsInfo(char *file[], int num)
{
    SCSection *dynamic, *gotplt, *plt, *got, *dynsym, *dynstr, *relgot, *relplt, *hash;
    SCSection *init, *fini, *fini_array, *init_array, *gv, *gnr;
    SCSection *interp, *symtab, *strtab;
    
    dynamic = this->getSectionByName(DYNAMIC_SECTION_NAME);
    gotplt = this->getSectionByName(GOT_PLT_SECTION_NAME);
    plt = this->getSectionByName(PLT_SECTION_NAME);
    got = this->getSectionByName(GOT_SECTION_NAME);
    dynsym = this->getSectionByName(DYNSYM_SECTION_NAME);
    relgot = this->getSectionByName(REL_DYN_SECTION_NAME);
    relplt = this->getSectionByName(REL_PLT_SECTION_NAME);
    dynstr = this->getSectionByName(DYNSTR_SECTION_NAME);
    hash = this->getSectionByName(HASH_SECTION_NAME);
    init = this->getSectionByName(INIT_SECTION_NAME);
    fini = this->getSectionByName(FINI_SECTION_NAME);
    fini_array = this->getSectionByName(FINI_ARRAY_SECTION_NAME);
    init_array = this->getSectionByName(INIT_ARRAY_SECTION_NAME);
    gv = this->getSectionByName(GV_SECTION_NAME);
    gnr = this->getSectionByName(GNR_SECTION_NAME);
    interp = this->getSectionByName(INTERP_SECTION_NAME);
    symtab = this->getSectionByName(SYMTAB_SECTION_NAME);
    strtab = this->getSectionByName(STRTAB_SECTION_NAME);
    
    gv->setSecInfo(interp->getSecIndex());
    dynsym->setSecInfo(interp->getSecIndex());
    relplt->setSecInfo(plt->getSecIndex());
    
    hash->setSecLink(dynsym->getSecIndex());
    gv->setSecLink(dynsym->getSecIndex());
    relgot->setSecLink(dynsym->getSecIndex());
    relplt->setSecLink(dynsym->getSecIndex());
    dynamic->setSecLink(dynstr->getSecIndex());
    gnr->setSecLink(dynstr->getSecIndex());
    dynsym->setSecLink(dynstr->getSecIndex());
    symtab->setSecLink(strtab->getSecIndex());
    
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        if (!strcmp((const char *)(*it)->getSecName(), REL_DYN_SECTION_NAME)) {
            (*it)->renewRELSection(got->getSecAddress());
        }
        if (!strcmp((const char *)(*it)->getSecName(), REL_PLT_SECTION_NAME)) {
            (*it)->renewRELSection(gotplt->getSecAddress());
        }
        if (!strcmp((const char *)(*it)->getSecName(), PLT_SECTION_NAME)) {
            (*it)->renewPLTSection(gotplt->getSecAddress());
        }
        if (!strcmp((const char *)(*it)->getSecName(), GOT_PLT_SECTION_NAME)) {
            (*it)->renewGOTPLTSection(dynamic->getSecAddress(), plt->getSecAddress());
        }
        if (!strcmp((const char *)(*it)->getSecName(), DYNAMIC_SECTION_NAME)) {
            (*it)->renewDynamicSection(this, file, num);
        }
    }
}

void SCSectionList::sortSections()
{
    int number_sections = 0;
    vector<SCSection*>::iterator it;
    /* delete the dump relocation sections and calculate section number*/
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        if ((*it)->getSecType() == SHT_REL && (*it)->getSecMisc() != 0) {
            this->sec_list.erase(it);
            --it;
            continue;
        }
        (*it)->setSecMisc((*it)->getSecOrderScore());
        number_sections++;
    }
    
    SCSection **list;
    list = (SCSection **)malloc(sizeof(SCSection *) * number_sections);
    number_sections = 0;
    
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        list[number_sections++] = *it;
        this->sec_list.erase(it);
        --it;
    }
    
    /* insert sort to sort the sections */
    for (int i = 0; i < number_sections; i++) {
        int low = i;
        for (int j = i + 1; j < number_sections; j++) {
            if (list[j]->getSecMisc() < list[low]->getSecMisc())
                low = j;
        }
        
        if (low != i) {
            SCSection *temp;
            temp = list[i];
            list[i] = list[low];
            list[low] = temp;
        }
    }
    
    for (int i = 0; i < number_sections; i++){
        list[i]->setSecFinalIndex(i);
        this->sec_list.push_back(list[i]);
    }
}

bool SCSectionList::skipXSection(UINT8 *name)
{
    const char *sec_name[] = {
        ".text",
        ".init",
        ".fini"
    };
    
    for (int i = 0; i < 3; i++) {
        if (!strcmp((const char *)name, sec_name[i]))
            return 1;
    }
    
    return 0;
}

void SCSectionList::testSectionList()
{
    int i = 0;
    vector<SCSection*>::iterator it;
    for (it = this->sec_list.begin(); it != this->sec_list.end(); ++it) {
        cout << (*it)->getSecIndex() << " ";
        cout << (*it)->getSecName() << "  " << 
            (*it)->sec_datasize << "  " << hex << (*it)->sec_file_offset;
        cout << " " << (*it)->getSecType() << " ";
        cout << " " << (*it)->sec_address << endl;
    }
}


