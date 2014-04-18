/*
 * =====================================================================================
 *
 *       Filename:  SCUpm.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/14 10:45:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "upm.h"

bool PatchInstrtoInstr32::apply()
{
    //cout << "1" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_instr->binary + this->dest_offset);
    
    /* S + A */
    new_value = this->src_instr->address + this->addend;
    cout << "1 " << old_value << " " << new_value << endl;
    if (old_value != new_value) {
        memcpy(this->dest_instr->binary + this->dest_offset, &new_value, sizeof(int));
        return true;
    }
    
    return false;
}

bool PatchInstrtoInstrPC32::apply()
{
    //cout << "2" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_instr->binary + this->dest_offset);
    
    /* S + A - P*/
    new_value = this->src_instr->address + this->addend - (this->dest_instr->address + this->dest_offset);
    //cout << this->src_instr->address << " ";
    //cout << this->dest_instr->address << " " << this->dest_offset << " ";
    //cout << "2 " << old_value << " "<< this->addend << " " << new_value << endl;
    cout << "2 " << old_value << " " << new_value << endl;
    if (old_value != new_value) {
        memcpy(this->dest_instr->binary + this->dest_offset, &new_value, sizeof(int));
        return true;
    }
    
    return false;
}

bool PatchSectiontoInstr32::apply()
{
    //cout << "3" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_instr->binary + dest_offset);
    
    /* S + A */
    new_value = this->src_sec->getSecAddress() + this->src_offset + this->addend;
    cout << "3 " << old_value << " " << new_value << endl;
    if (old_value != new_value) {
        memcpy(this->dest_instr->binary + this->dest_offset, &new_value, sizeof(int));
        return true;
    }
    
    return false;
}

bool PatchSectiontoInstrPC32::apply()
{
    //cout << "4" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_instr->binary + dest_offset);
    
    /* S + A - P*/
    new_value = (this->src_sec->getSecAddress() + this->src_offset) + this->addend - (this->dest_instr->address + this->dest_offset);
    cout << "4 " << old_value << " " << new_value << endl;
    if (old_value != new_value) {
        memcpy(this->dest_instr->binary + this->dest_offset, &new_value, sizeof(int));
        return true;
    }
    
    return false;
}

bool PatchSectiontoSection32::apply()
{
    //cout << "5" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_sec->getSecData() + this->dest_offset);
    
    new_value = (this->src_sec->getSecAddress() + this->src_offset) + this->addend;
    cout << "5 " << old_value << " " << new_value << endl;
    if (old_value != new_value) {
        this->dest_sec->setSecContent(this->dest_offset, (char *)&new_value, sizeof(int));
        return true;
    }
    
    return false;
}

bool PatchSectiontoSectionPC32::apply()
{
    //cout << "6" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_sec->getSecData() + this->dest_offset);
    
    new_value = (this->src_sec->getSecAddress() + this->src_offset) + this->addend - (this->dest_sec->getSecAddress() + this->dest_offset);
    cout << "6 " << old_value << " " << new_value << endl;
    if (old_value != new_value) {
        this->dest_sec->setSecContent(this->dest_offset, (char *)&new_value, sizeof(int));
        return true;
    }
    
    return false;
}

bool PatchSecSectoInstr32::apply()
{
    //cout << "7" << endl;
    int old_value, new_value;
    old_value = *(int *)(this->dest_instr->binary + this->dest_offset);

    new_value = (this->src_sec->getSecAddress() + this->src_offset - this->base_sec->getSecAddress()) + this->addend;
    cout << "7 " << old_value << " " << new_value << " ";
    cout << this->src_sec->getSecAddress() << " " << this->src_offset << endl;
    if (old_value != new_value) {
        memcpy(this->dest_instr->binary + this->dest_offset, &new_value, sizeof(int));
        //memcpy(this->dest_instr->binary + this->dest_offset, &new_value, sizeof(int));
        return true;
    }
    
    return false;
}

void SCPatchList::initUPMRel(SCSectionList *sl, SCRelocationList *rel_list, vector<INSTRUCTION*> *instr_list)
{
    vector<SCRelocation*>::iterator it;
    int i = 0;
    for (it = rel_list->getRelList()->begin(); it != rel_list->getRelList()->end(); ++it) {
        INSTRUCTION *src_instr, *dest_instr;
        SCSection *src_sec, *dest_sec;
        UINT32 src_offset, dest_offset,  rel_address, src_address;
        int rel_addend;
        UINT8 rel_type;
        void *patch;
        
        dest_sec = (*it)->getRelSection();
        dest_offset = (*it)->getRelOffset();
        rel_address = dest_sec->getSecAddress() + dest_offset;
        rel_addend = (*it)->getRelAddend();
        dest_instr = this->backtraceInstr(instr_list, rel_address);
        src_address = (*it)->getRelValue();
        
        rel_type = (*it)->getRelType();
        
        if (dest_instr) {
            /* remeber to modify dest_offset here */
            dest_offset = rel_address - dest_instr->address;
            
            src_instr = this->backtraceInstr(instr_list, src_address);
            
            if (src_instr) {
                if (rel_type == R_386_PC32 || rel_type == R_386_PLT32) {
                    patch = new PatchInstrtoInstrPC32(src_instr, 0, dest_instr, dest_offset, rel_addend);
                }
                else if (rel_type == R_386_32) {
                    patch = new PatchInstrtoInstr32(src_instr, 0, dest_instr, dest_offset, rel_addend);
                }
                else {
                    cerr << "we can't handle the relocation type now 1" << endl;
                    exit(0);
                }
            }
            else {
                src_sec = this->backtraceSec(sl, src_address);
                src_offset = src_address - src_sec->getSecAddress();
                
                if (rel_type == R_386_32) {
                    patch = new PatchSectiontoInstr32(src_sec, src_offset, dest_instr, dest_offset, rel_addend);
                }
                else if (rel_type == R_386_GOTPC) {
                    patch = new PatchSectiontoInstrPC32(src_sec, src_offset, dest_instr, dest_offset, rel_addend);
                }
                else if (rel_type == R_386_GOTOFF) {
                    SCSection *gotplt = sl->getSectionByName(GOT_PLT_SECTION_NAME);
                    patch = new PatchSecSectoInstr32(src_sec, src_offset, gotplt, dest_instr, dest_offset, rel_addend);
                }
                else if (rel_type == R_386_GOT32) {
                    SCSection *gotplt = sl->getSectionByName(GOT_PLT_SECTION_NAME);
                    patch = new PatchSecSectoInstr32(src_sec, src_offset, gotplt, dest_instr, dest_offset, rel_addend);
                }
                else {
                    cerr << "we can't handle the relocation type now 2" << endl;
                    exit(0);
                }
            }
        }
        /* as for destination is not in the code section, 
         * source must be a section+offset 
         * TODO: verify above */
        
        else {
            src_sec = this->backtraceSec(sl, src_address);
            src_offset = src_address - src_sec->getSecAddress();
            
            if (rel_type == R_386_NONE)
                continue;
            else if (rel_type == R_386_32) {
                patch = new PatchSectiontoSection32(src_sec, src_offset, dest_sec, dest_offset, rel_addend);
            }
            else if (rel_type == R_386_PC32) {
                patch = new PatchSectiontoSectionPC32(src_sec, src_offset, dest_sec, dest_offset, rel_addend);
            }
            else {
                cerr << "we can't handle the relocation type now 3" << endl;
                exit(0);
            }
        }
        this->p_list.push_back((SCPatch *)patch);

        //char blank = ' ';
        //cout << hex ;
        //if (dest_instr)
            //cout << dest_instr->address << " ";
        //else
            //printf("%8c", blank);
        
        //cout << (*it)->getRelSection()->getSecAddress() << " ";
        //cout << (*it)->getRelAddend() << " ";
        //cout << (*it)->getRelOffset() << " ";
        //cout << (*it)->getRelValue() << endl;
        i++;
    }

    //cout << endl;
    //cout << "the size is: " << this->p_list.size() << endl;
    //cout << "sum is: " << i << endl;
}

void SCPatchList::initUPMSym(SCSectionList *sl, SCSymbolListREL *sym_list, vector<INSTRUCTION*> *instr_list)
{
    vector<SCSymbol*>::iterator it;
    for (it = sym_list->getSymbolList()->begin(); it != sym_list->getSymbolList()->end(); ++it) {
        
    }
}

int SCPatchList::apply()
{
    vector<SCPatch*>::iterator it;
    int change = 0;
    int i = 0;
    for (it = this->p_list.begin(); it != this->p_list.end(); ++it) {
        if ((*it)->apply()) {
            change++;
            cout << "difference " << i << endl;
        }
        i++;
    }
    
    return change;
}

INSTRUCTION *SCPatchList::backtraceInstr(vector<INSTRUCTION*> *instr_list, UINT32 address)
{
    vector<INSTRUCTION*>::iterator it;
    
    it = instr_list->end() - 1;
    if ((*it)->address < address)
        return NULL;
    
    for (it = instr_list->begin(); it != instr_list->end(); ++it) {
        UINT32 instr_address = (*it)->address;
        /* there have be < instead of <= */
        if (instr_address <= address && (instr_address + (*it)->size) > address)
            break;
    }
    
    //if (it != instr_list->end())
    return (*it);
    //return NULL;
}

SCSection *SCPatchList::backtraceSec(SCSectionList *sl, UINT32 address)
{
    vector<SCSection*>::iterator it;
    
    for (it = sl->getSectionList()->begin(); it != sl->getSectionList()->end(); ++it) {
        UINT32 sec_address = (*it)->getSecAddress();
        /* !!Pay attention here!!
         * init_array_end is an exception which the address is beyond the real range*/
        /* TODO: fix the init_array_end special occasion */
        if (sec_address <= address && (sec_address + (*it)->getSecDatasize()) > address || 
                !strcmp((char *)(*it)->getSecName(), ".init_array") && sec_address <= address && (sec_address + (*it)->getSecDatasize()) >= address )
            break;
    }
    
    return (*it);
}
