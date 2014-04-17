#ifndef _DIS_TABLE_H_
#define _DIS_TABLE_H_

#include "dis-table.h"
#include "operand.h"
#include "type.h"
#include <cstddef>

/* operand that might be used */
// memory
Operand memory_byte_s1_s1 = Operand(-1, -1, SIZE_BYTE, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_word_s1_s1 = Operand(-1, -1, SIZE_WORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_dword_s1_s1 = Operand(-1, -1, SIZE_DWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_qword_s1_s1 = Operand(-1, -1, SIZE_QWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_byte_edi_es = Operand(ES, EDI, SIZE_BYTE, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_dword_edi_es = Operand(ES, EDI, SIZE_DWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_byte_esi_ds = Operand(DS, ESI, SIZE_BYTE, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_dword_esi_ds = Operand(DS, ESI, SIZE_DWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_fword_s1_s1 = Operand(-1, -1, SIZE_FWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_byte_ebx_al_s1 = Operand(-1, EBX_PLUS_AL, SIZE_BYTE, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_fixed_qword_s1_s1 = Operand(-1, -1, SIZE_FIXED_QWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_fixed_fword_s1_s1 = Operand(-1, -1, SIZE_FIXED_FWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_fixed_dword_s1_s1 = Operand(-1, -1, SIZE_FIXED_DWORD, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_28_s1_s1 = Operand(-1, -1, SIZE_SPEC_28, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_108_s1_s1 = Operand(-1, -1, SIZE_SPEC_108, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_tbyte_s1_s1 = Operand(-1, -1, SIZE_TBYTE, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memory_512_s1_s1 = Operand(-1, -1, SIZE_SPEC_512, OPERAND_MEMORY, -1, -1, -1, -1, -1, SIZE_DWORD, 0);

// memory offset
Operand memoryoffset_byte_s1_s1 = Operand(-1, -1, SIZE_BYTE, OPERAND_MEMORY_OFFSET, -1, -1, -1, -1, -1, SIZE_DWORD, 0);
Operand memoryoffset_dword_s1_s1 = Operand(-1, -1, SIZE_DWORD, OPERAND_MEMORY_OFFSET, -1, -1, -1, -1, -1, SIZE_DWORD, 0);

// register
Operand register_byte_s1_s1 = Operand(-1, -1, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_word_s1_s1 = Operand(-1, -1, SIZE_WORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_s1_s1 = Operand(-1, -1, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_al_s1 = Operand(-1, AL, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_al_s1_default = Operand(-1, AL, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_dword_eax_s1 = Operand(-1, EAX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_ecx_s1 = Operand(-1, ECX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_ebx_s1 = Operand(-1, EBX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_edx_s1 = Operand(-1, EDX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_esp_s1 = Operand(-1, ESP, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_ebp_s1 = Operand(-1, EBP, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_esi_s1 = Operand(-1, ESI, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_edi_s1 = Operand(-1, EDI, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_all_s1_default = Operand(-1, ALL_32BITS_REGISTER, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_word_ax_s1 = Operand(-1, AX, SIZE_WORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_word_dx_s1 = Operand(-1, DX, SIZE_WORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_eax_s1_default = Operand(-1, EAX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_dword_edx_s1_default = Operand(-1, EDX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_word_ax_s1_default = Operand(-1, AX, SIZE_WORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_qword_edx_s1_default = Operand(-1, EDX, SIZE_QWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_dword_all_flags_s1_default = Operand(-1, ALL_EFLAGS, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_byte_ah_s1_default = Operand(-1, AH, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_byte_cl_s1 = Operand(-1, CL, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_dl_s1 = Operand(-1, DL, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_bl_s1 = Operand(-1, BL, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_ah_s1 = Operand(-1, AH, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_ch_s1 = Operand(-1, CH, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_dh_s1 = Operand(-1, DH, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_byte_bh_s1 = Operand(-1, BH, SIZE_BYTE, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand register_dword_ebp_s1_default = Operand(-1, EBP, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_dword_ecx_s1_default = Operand(-1, ECX, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_fixed_dword_s1_s1_default = Operand(-1, -1, SIZE_FIXED_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_dword_esp_s1_default = Operand(-1, ESP, SIZE_DWORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand register_word_all_flags_s1_default = Operand(-1, ALL_EFLAGS, SIZE_WORD, OPERAND_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);

// immediate
Operand immediate_byte_s1_s1 = Operand(-1, -1, SIZE_BYTE, OPERAND_IMMEDIATE, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand immediate_word_s1_s1 = Operand(-1, -1, SIZE_WORD, OPERAND_IMMEDIATE, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand immediate_dword_s1_s1 = Operand(-1, -1, SIZE_DWORD, OPERAND_IMMEDIATE, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand immediate_byte_3_s1_default = Operand(-1, 3, SIZE_BYTE, OPERAND_IMMEDIATE, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand immediate_byte_1_s1 = Operand(-1, 1, SIZE_BYTE, OPERAND_IMMEDIATE, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);

// segment
Operand segment_s1_es_s1 = Operand(-1, ES, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_cs_s1 = Operand(-1, CS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_ss_s1 = Operand(-1, SS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_ds_s1 = Operand(-1, DS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_fs_s1 = Operand(-1, FS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_gs_s1 = Operand(-1, GS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_s1_s1 = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand segment_s1_es_s1_default = Operand(-1, ES, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand segment_s1_ds_s1_default = Operand(-1, DS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand segment_s1_ss_s1_default = Operand(-1, SS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand segment_s1_fs_s1_default = Operand(-1, FS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand segment_s1_gs_s1_default = Operand(-1, GS, SIZE_UNDEFINED, OPERAND_SEGMENT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);

// flow
Operand flow_reladdrshort_s1_s1 = Operand(-1, -1, RELATIVE_ADDRESS_SHORT, OPERAND_FLOW, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand flow_reladdrfar_s1_s1 = Operand(-1, -1, RELATIVE_ADDRESS_FAR, OPERAND_FLOW, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand flow_addrfarabs_s1_s1 = Operand(-1, -1, ADDRESS_FAR_ABSOLUTE, OPERAND_FLOW, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);

// cr | dr
Operand cr_s1_cr0_s1_default = Operand(-1, CR0, SIZE_UNDEFINED, OPERAND_CR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand cr_s1_s1_s1 = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_CR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand dr_s1_s1_s1 = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_DR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);

// msr | msw
Operand msr_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_MSR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand msw_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_MSW, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);

// float
Operand float_s1_st0_s1_default = Operand(-1, ST0, SIZE_UNDEFINED, OPERAND_FLOAT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand float_s1_st1_s1_default = Operand(-1, ST1, SIZE_UNDEFINED, OPERAND_FLOAT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand float_s1_st0_s1 = Operand(-1, ST0, SIZE_UNDEFINED, OPERAND_FLOAT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand float_s1_s1_s1 = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_FLOAT, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);

// xmm
Operand xmmre_xmm_s1_s1 = Operand(-1, -1, SIZE_XMM, OPERAND_XMM_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand xmmre_fixed_dword_s1_s1 = Operand(-1, -1, SIZE_FIXED_DWORD, OPERAND_XMM_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand xmmre_fixed_qword_s1_s1 = Operand(-1, -1, SIZE_FIXED_QWORD, OPERAND_XMM_REGISTER, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand xmmmem_dqword_s1_s1 = Operand(-1, -1, SIZE_DQWORD, OPERAND_XMM_MEMORY, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand xmmmem_fixed_dword_s1_s1 = Operand(-1, -1, SIZE_FIXED_DWORD, OPERAND_XMM_MEMORY, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand xmmmem_fixed_qword_s1_s1 = Operand(-1, -1, SIZE_FIXED_QWORD, OPERAND_XMM_MEMORY, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);

// other
Operand pmc_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_PMC, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand ldtr_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_LDTR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand tr_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_TR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand gdtr_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_GDTR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);
Operand idtr_s1_s1_s1_default = Operand(-1, -1, SIZE_UNDEFINED, OPERAND_IDTR, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 1);

// not exist
Operand notexist_s1_80_s1 = Operand(-1, AUXILIARY_80, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_81_s1 = Operand(-1, AUXILIARY_81, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_82_s1 = Operand(-1, AUXILIARY_82, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_83_s1 = Operand(-1, AUXILIARY_83, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_8f_s1 = Operand(-1, AUXILIARY_8f, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_c0_s1 = Operand(-1, AUXILIARY_c0, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_c1_s1 = Operand(-1, AUXILIARY_c1, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_c6_s1 = Operand(-1, AUXILIARY_c6, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_c7_s1 = Operand(-1, AUXILIARY_c7, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_d0_s1 = Operand(-1, AUXILIARY_d0, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_d1_s1 = Operand(-1, AUXILIARY_d1, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_d2_s1 = Operand(-1, AUXILIARY_d2, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_d3_s1 = Operand(-1, AUXILIARY_d3, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_d8_s1 = Operand(-1, AUXILIARY_d8, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_d9_s1 = Operand(-1, AUXILIARY_d9, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_da_s1 = Operand(-1, AUXILIARY_da, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_db_s1 = Operand(-1, AUXILIARY_db, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_dc_s1 = Operand(-1, AUXILIARY_dc, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_dd_s1 = Operand(-1, AUXILIARY_dd, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_de_s1 = Operand(-1, AUXILIARY_de, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_df_s1 = Operand(-1, AUXILIARY_df, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_f6_s1 = Operand(-1, AUXILIARY_f6, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_f7_s1 = Operand(-1, AUXILIARY_f7, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_fe_s1 = Operand(-1, AUXILIARY_fe, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_ff_s1 = Operand(-1, AUXILIARY_ff, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_0f00_s1 = Operand(-1, AUXILIARY_0f00, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_0f01_s1 = Operand(-1, AUXILIARY_0f01, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_0f18_s1 = Operand(-1, AUXILIARY_0f18, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_0fae_s1 = Operand(-1, AUXILIARY_0fae, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);
Operand notexist_s1_0fba_s1 = Operand(-1, AUXILIARY_0fba, SIZE_UNDEFINED, OPERAND_NOT_EXIST, -1, -1, -1, -1, -1, SIZE_UNDEFINED, 0);

/* instruction */
SCInstr getOneByteOpcode[] = {
    /* 0x00: ADD r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x01: ADD r/m16/32, r16/32/64 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x02: ADD r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x03: ADD r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x04: ADD AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 0, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x05: ADD rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 0, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x06: PUSH ES */
    SCInstr({-1, -1, -1, -1, &segment_s1_es_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x07: POP ES */
    SCInstr({-1, -1, -1, -1, &segment_s1_es_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x08: OR r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x09: OR r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0a: OR r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0b: OR r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0c: OR AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0d: OR rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0e: PUSH CS */
    SCInstr({-1, -1, -1, -1, &segment_s1_cs_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f: Two Byte opcode */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x10: ADC r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x11: ADC r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x12: ADC r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x13: ADC r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x14: ADC AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 0, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x15: ADC rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 0, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x16: PUSH SS */
    SCInstr({-1, -1, -1, -1, &segment_s1_ss_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x17: POP SS */
    SCInstr({-1, -1, -1, -1, &segment_s1_ss_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x18: SBB r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x19: SBB r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1a: SBB r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1b: SBB r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1c: SBB AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, CF, -1, 0, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1d: SBB rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, CF, -1, 0, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1e: PUSH DS */
    SCInstr({-1, -1, -1, -1, &segment_s1_ds_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1f: POP DS */
    SCInstr({-1, -1, -1, -1, &segment_s1_ds_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x20: AND r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x21: AND r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x22: AND r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x23: AND r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x24: AND AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x25: AND rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x26: SEGMENT OVERRIDE ES */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x27: DAA AL */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DAA, CF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "daa", -1, -1, -1, -1, NULL, NULL}),
    /* 0x28: SUB r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x29: SUB r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2a: SUB r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2b: SUB r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2c: SUB AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, 0, -1, 0, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2d: SUB rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, 0, -1, 0, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2e: SEGMENT OVERRIDE CS */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2f: DAS AL */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DAS, CF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "das", -1, -1, -1, -1, NULL, NULL}),

    /* 0x30: XOR r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x31: XOR r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x32: XOR r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x33: XOR r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x34: XOR AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x35: XOR rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x36: SEGMENT OVERRIDE SS */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x37: AAA AL */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_AAA, CF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "aaa", -1, -1, -1, -1, NULL, NULL}),
    /* 0x38: CMP r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x39: CMP r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3a: CMP r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3b: CMP r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3c: CMP AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 0, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3d: CMP rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 0, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3e: SEGMENT OVERRIDE DS */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3f: AAS AL */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_AAS, CF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "aas", -1, -1, -1, -1, NULL, NULL}),

    /* 0x40: INC EAX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x41: INC ECX */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x42: INC EDX */
    SCInstr({-1, -1, -1, -1, &register_dword_edx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x43: INC EBX */
    SCInstr({-1, -1, -1, -1, &register_dword_ebx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x44: INC ESP */
    SCInstr({-1, -1, -1, -1, &register_dword_esp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x45: INC EBP */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x46: INC ESI */
    SCInstr({-1, -1, -1, -1, &register_dword_esi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x47: INC EDI */
    SCInstr({-1, -1, -1, -1, &register_dword_edi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x48: DEC EAX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x49: DEC ECX */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4a: DEC EDX */
    SCInstr({-1, -1, -1, -1, &register_dword_edx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4b: DEC EBX */
    SCInstr({-1, -1, -1, -1, &register_dword_ebx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4c: DEC ESP */
    SCInstr({-1, -1, -1, -1, &register_dword_esp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4d: DEC EBP */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4e: DEC ESI */
    SCInstr({-1, -1, -1, -1, &register_dword_esi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4f: DEC EDI */
    SCInstr({-1, -1, -1, -1, &register_dword_edi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x50: PUSH EAX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x51: PUSH ECX */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x52: PUSH EDX */
    SCInstr({-1, -1, -1, -1, &register_dword_edx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x53: PUSH EBX */
    SCInstr({-1, -1, -1, -1, &register_dword_ebx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x54: PUSH ESP */
    SCInstr({-1, -1, -1, -1, &register_dword_esp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x55: PUSH EBP */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x56: PUSH ESI */
    SCInstr({-1, -1, -1, -1, &register_dword_esi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x57: PUSH EDI */
    SCInstr({-1, -1, -1, -1, &register_dword_edi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x58: POP EAX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x59: POP ECX */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5a: POP EDX */
    SCInstr({-1, -1, -1, -1, &register_dword_edx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5b: POP EBX */
    SCInstr({-1, -1, -1, -1, &register_dword_ebx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5c: POP ESP */
    SCInstr({-1, -1, -1, -1, &register_dword_esp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5d: POP EBP */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5e: POP ESI */
    SCInstr({-1, -1, -1, -1, &register_dword_esi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5f: POP EDI */
    SCInstr({-1, -1, -1, -1, &register_dword_edi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x60: PUSHAD EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI/PUSHAW AX, CX, DX, BX, SP, BP, SI, DI*/
    SCInstr({-1, -1, -1, -1, &register_dword_all_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "pushad", -1, -1, -1, -1, NULL, NULL}),
    /* 0x61: POPAD EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI/POPAW AX, CX, DX, BX, SP, BP, SI, DI*/
    SCInstr({-1, -1, -1, -1, &register_dword_all_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "popad", -1, -1, -1, -1, NULL, NULL}),
    /* 0x62: BOUND r16/32, m16/32&16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_BOUND, 0, 0, -1, 1, -1, NULL, NULL, "bound ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x63: ARPL r/m16, r16 */
    SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &register_word_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ARPL, ZF, 0, -1, 1, -1, NULL, NULL, "arpl ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x64: SEGMENT OVERRIDE FS */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x65: SEGMENT OVERRIDE GS */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x66: OPERAND SIZE OVERRIDE */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x67: ADDRESS SIZE OVERRIDE */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x68: PUSH imm16/32 */
    SCInstr({-1, -1, -1, -1, &immediate_dword_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x69: IMUL r16/32, r/m16/32, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IMUL, CF | OF, 0, -1, 1, -1, NULL, NULL, "imul ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6a: PUSH imm8 */
    SCInstr({-1, -1, -1, -1, &immediate_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6b: IMUL r16/32, r/m16/32, imm8 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IMUL, CF | OF, 0, -1, 1, -1, NULL, NULL, "imul ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6c: INS INT8 PTR ES:[EDI/DI], DX */
    SCInstr({-1, -1, -1, -1, &memory_byte_edi_es, &register_word_dx_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_INS, 0, 0, -1, 0, -1, NULL, NULL, "ins ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6d: INS INT32/INT16 PTR ES:[EDI/DI], DX */
    SCInstr({-1, -1, -1, -1, &memory_dword_edi_es, &register_word_dx_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_INS, 0, 0, -1, 0, -1, NULL, NULL, "ins ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6e: OUTS DX, INT8 PTR ES:[EDI/DI] */
    SCInstr({-1, -1, -1, -1, &register_word_dx_s1, &memory_byte_edi_es, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_OUTS, 0, 0, -1, 0, -1, NULL, NULL, "outs ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6f: OUTS DX, INT32/INT16 PTR ES:[EDI/DI] */
    SCInstr({-1, -1, -1, -1, &register_word_dx_s1, &memory_dword_edi_es, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_OUTS, 0, 0, -1, 0, -1, NULL, NULL, "outs ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x70: JO SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JO, 0, 0, -1, 0, -1, NULL, NULL, "jo short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x71: JNO SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNO, 0, 0, -1, 0, -1, NULL, NULL, "jno short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x72: JB SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JB, 0, 0, -1, 0, -1, NULL, NULL, "jb short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x73: JNB SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNB, 0, 0, -1, 0, -1, NULL, NULL, "jnb short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x74: JE SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JE, 0, 0, -1, 0, -1, NULL, NULL, "je short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x75: JNE SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNE, 0, 0, -1, 0, -1, NULL, NULL, "jne short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x76: JBE SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JBE, 0, 0, -1, 0, -1, NULL, NULL, "jbe short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x77: JA SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JA, 0, 0, -1, 0, -1, NULL, NULL, "ja short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x78: JS SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JS, 0, 0, -1, 0, -1, NULL, NULL, "js short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x79: JNS SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNS, 0, 0, -1, 0, -1, NULL, NULL, "jns short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7a: JPE SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JPE, 0, 0, -1, 0, -1, NULL, NULL, "jpe short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7b: JPO SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JPO, 0, 0, -1, 0, -1, NULL, NULL, "jpo short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7c: JL SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JL, 0, 0, -1, 0, -1, NULL, NULL, "jl short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7d: JGE SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JGE, 0, 0, -1, 0, -1, NULL, NULL, "jge short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7e: JLE SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JLE, 0, 0, -1, 0, -1, NULL, NULL, "jle short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7f: JG SHORT re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JG, 0, 0, -1, 0, -1, NULL, NULL, "jg short ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x80: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_80_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x81: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_81_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x82: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_82_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x83: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_83_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x84: TEST r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_TEST, OF | CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "test ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x85: TEST r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_TEST, OF | CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "test ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x86: XCHG r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 1, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x87: XCHG r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 1, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x88: MOV r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x89: MOV r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8a: MOV r8, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8b: MOV r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8c: MOV r/m16, Segment */
    SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &segment_s1_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8d: LEA r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_LEA, 0, 0, -1, 1, -1, NULL, NULL, "lea ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8e: MOV Segment, r/m16 */
    SCInstr({-1, -1, -1, -1, &segment_s1_s1_s1, &memory_word_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8f: POP r/m16/32 */
    SCInstr({-1, -1, -1, -1, &notexist_s1_8f_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x90: NOP */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_NOP, 0, 0, -1, 0, -1, NULL, NULL, "nop", -1, -1, -1, -1, NULL, NULL}),
    /* 0x91: XCHG rAX, rCX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_ecx_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x92: XCHG rAX, rDX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_edx_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x93: XCHG rAX, rBX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_ebx_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x94: XCHG rAX, rSP */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_esp_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x95: XCHG rAX, rBP */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_ebp_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x96: XCHG rAX, rSI */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_esi_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x97: XCHG rAX, rDI */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_dword_edi_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x98: CWD EAX, AX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &register_word_ax_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  CLASS_CWD, 0, 0, -1, 0, -1, NULL, NULL, "cwde", -1, -1, -1, -1, NULL, NULL}),
    /* 0x99: CDW EDX, EAX */
    SCInstr({-1, -1, -1, -1, &register_qword_edx_s1_default, &register_dword_eax_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  CLASS_CDQ, 0, 0, -1, 0, -1, NULL, NULL, "cdq", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9a: CALL FAR ptr16:16/32 */
    SCInstr({-1, -1, -1, -1, &flow_addrfarabs_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_CALL, 0, 0, -1, 0, -1, NULL, NULL, "call far ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9b: WAIT */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_WAIT, 0, 0, -1, 0, -1, NULL, NULL, "wait", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9c: PUSHFD EFLAGS */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "pushfd", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9d: POPFD EFLAGS */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "popfd", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9e: SAHF AH */
    SCInstr({-1, -1, -1, -1, &register_byte_ah_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SAHF, SF | ZF | AF | PF | CF, 0, -1, 0, -1, NULL, NULL, "sahf", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9f: LAHF AH */
    SCInstr({-1, -1, -1, -1, &register_byte_ah_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_LAHF, 0, 0, -1, 0, -1, NULL, NULL, "lahf", -1, -1, -1, -1, NULL, NULL}),

    /* 0xa0: MOV AL, moffs8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &memoryoffset_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa1: MOV rAX, moffs16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &memoryoffset_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa2: MOV moffs8, AL */
    SCInstr({-1, -1, -1, -1, &memoryoffset_byte_s1_s1, &register_byte_al_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa3: MOV moffs16/32, rAX */
    SCInstr({-1, -1, -1, -1, &memoryoffset_dword_s1_s1, &register_dword_eax_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa4: MOVS m8, m8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_edi_es, &memory_byte_esi_ds, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOVS, 0, 0, -1, 0, -1, NULL, NULL, "movs ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa5: MOVS m16/32, m16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_edi_es, &memory_dword_esi_ds, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOVS, 0, 0, -1, 0, -1, NULL, NULL, "movs ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa6: CMPS m8, m8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_esi_ds, &memory_byte_edi_es, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMPS, 0, 0, -1, 0, -1, NULL, NULL, "cmps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa7: CMPS m16/32, m16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_esi_ds, &memory_dword_edi_es, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMPS, 0, 0, -1, 0, -1, NULL, NULL, "cmps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa8: TEST AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_TEST, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "test ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa9: TEST rAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_TEST, OF | SF | ZF | CF | PF, 0, -1, 0, -1, NULL, NULL, "test ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xaa: STOS m8, AL */
    SCInstr({-1, -1, -1, -1, &memory_byte_edi_es, &register_byte_al_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_STOS, 0, 0, -1, 0, -1, NULL, NULL, "stos ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xab: STOS m16/32, rAX */
    SCInstr({-1, -1, -1, -1, &memory_dword_edi_es, &register_dword_eax_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_STOS, 0, 0, -1, 0, -1, NULL, NULL, "stos ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xac: LODS AL, m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &memory_byte_esi_ds, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_LODS, 0, 0, -1, 0, -1, NULL, NULL, "lods ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xad: LODS rAX, m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &memory_dword_esi_ds, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_LODS, 0, 0, -1, 0, -1, NULL, NULL, "lods ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xae: SCAS m8, AL */
    SCInstr({-1, -1, -1, -1, &memory_byte_edi_es, &register_byte_al_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SCAS, OF | SF | ZF | AF | PF | CF, 0, -1, 0, -1, NULL, NULL, "scas ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xaf: SCAS m16/32, rAX */
    SCInstr({-1, -1, -1, -1, &memory_dword_edi_es, &register_dword_eax_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SCAS, 0, 0, -1, 0, -1, NULL, NULL, "scas ", -1, -1, -1, -1, NULL, NULL}),

    /* 0xb0: MOV AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb1: MOV CL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_cl_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb2: MOV DL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_dl_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb3: MOV BL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_bl_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb4: MOV AH, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_ah_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb5: MOV CH, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_ch_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb6: MOV DH, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_dh_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb7: MOV BH, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_bh_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb8: MOV EAX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb9: MOV ECX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xba: MOV EDX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_edx_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbb: MOV EBX, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_ebx_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbc: MOV ESP, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_esp_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbd: MOV EBP, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbe: MOV ESI, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_esi_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbf: MOV EDI, imm16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_edi_s1, &immediate_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 0, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),

    /* 0xc0: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_c0_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc1: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_c1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc2: RETN imm16 */
    SCInstr({-1, -1, -1, -1, &immediate_word_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_RETN, 0, 0, -1, 0, -1, NULL, NULL, "retn ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc3: RETN */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_RETN, 0, 0, -1, 0, -1, NULL, NULL, "retn ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc4: LES ES, r16/32, m16:16/32 */
    SCInstr({-1, -1, -1, -1, &segment_s1_es_s1_default, &register_dword_s1_s1, &memory_fword_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_LES, 0, 0, -1, 1, -1, NULL, NULL, "les ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc5: LES DS, r16/32, m16:16/32 */
    SCInstr({-1, -1, -1, -1, &segment_s1_ds_s1_default, &register_dword_s1_s1, &memory_fword_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_LDS, 0, 0, -1, 1, -1, NULL, NULL, "lds ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc6: MOV r/m8, imm8 */
    SCInstr({-1, -1, -1, -1, &notexist_s1_c6_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc7: MOV r/m16/32, imm16/32 */
    SCInstr({-1, -1, -1, -1, &notexist_s1_c7_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc8: ENTER rBP, imm16, imm8 */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1_default, &immediate_word_s1_s1, &immediate_byte_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ENTER, 0, 0, -1, 0, -1, NULL, NULL, "enter ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc9: LEAVE rBP */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1_default,NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_LEAVE, 0, 0, -1, 0, -1, NULL, NULL, "leave ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xca: RETF imm16 */
    SCInstr({-1, -1, -1, -1, &immediate_word_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_RETF, 0, 0, -1, 0, -1, NULL, NULL, "retf ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcb: RETF */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_RETF, 0, 0, -1, 0, -1, NULL, NULL, "retf ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcc: INT 3 */
    SCInstr({-1, -1, -1, -1, &immediate_byte_3_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_INT3, 0, 0, -1, 0, -1, NULL, NULL, "int3", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcd: INT imm8 */
    SCInstr({-1, -1, -1, -1, &immediate_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_INT, 0, 0, -1, 0, -1, NULL, NULL, "int ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xce: INTO EFLAGS */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, STACK_OPERATE_INSTRUCTION, UNDEFINED_CLASS, IF | TF, 0, -1, 0, -1, NULL, NULL, "into", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcf: IRET */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, SPECIAL_MNEMONIC, CLASS_IRETD, 0, 0, -1, 0, -1, NULL, NULL, "iretd", -1, -1, -1, -1, NULL, NULL}),

    /* 0xd0: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_d0_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd1: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_d1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd2: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_d2_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd3: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_d3_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd4: AAM AL, AH(, imm8) */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &register_byte_ah_s1_default, &immediate_byte_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, SPECIAL_MNEMONIC, CLASS_AAM, SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "aam ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd5: AAD AL, AH(, imm8) */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &register_byte_ah_s1_default, &immediate_byte_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, SPECIAL_MNEMONIC, CLASS_AAD, SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "aad ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd6: SALC AL */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SALC, SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "salc", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd7: XLAT AL, m8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &memory_byte_ebx_al_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XLAT, 0, 0, -1, 0, -1, NULL, NULL, "xlat ", -1, -1, -1, -1, NULL, NULL}),
    /* Float point instruction: from 0xd8 to 0xdf */
    /* 0xd8: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_d8_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_d9_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xda: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_da_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdb: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_db_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdc: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_dc_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdd: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_dd_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xde: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_de_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdf: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_df_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0xe0: LOOPDNE rCX, re18 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1_default, &flow_reladdrshort_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_LOOPDNE, 0, 0, -1, 0, -1, NULL, NULL, "loopdne short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe1: LOOPDE rCX, re18 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1_default, &flow_reladdrshort_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_LOOPDE, 0, 0, -1, 0, -1, NULL, NULL, "loopde short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe2: LOOPD rCX, re18 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1_default, &flow_reladdrshort_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_LOOPD, 0, 0, -1, 0, -1, NULL, NULL, "loopd short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe3: JCXZ rCX, re18 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, &register_dword_ecx_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, CLASS_JEXCZ, 0, 0, -1, 0, -1, NULL, NULL, "jecxz short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe4: IN AL, imm8 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_IN, 0, 0, -1, 0, -1, NULL, NULL, "in ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe5: IN rAX, imm8 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &immediate_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_IN, 0, 0, -1, 0, -1, NULL, NULL, "in ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe6: OUT imm8, AL */
    SCInstr({-1, -1, -1, -1, &immediate_byte_s1_s1, &register_byte_al_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_OUT, 0, 0, -1, 0, -1, NULL, NULL, "out ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe7: OUT imm8, rAX */
    SCInstr({-1, -1, -1, -1, &immediate_byte_s1_s1, &register_dword_eax_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_OUT, 0, 0, -1, 0, -1, NULL, NULL, "out ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe8: CALL rel16/32 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_CALL, 0, 0, -1, 0, -1, NULL, NULL, "call ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe9: JMP rel16/32 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_JMP, 0, 0, -1, 0, -1, NULL, NULL, "jmp ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xea: JMP FAR ptr16:16/32 */
    SCInstr({-1, -1, -1, -1, &flow_addrfarabs_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_JMPF, 0, 0, -1, 0, -1, NULL, NULL, "jmp far ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xeb: JMP SHORT rel8 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOW_INSTRUCTION, CLASS_JMP_SHORT, 0, 0, -1, 0, -1, NULL, NULL, "jmp short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xec: IN AL, DX */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1, &register_word_dx_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_IN, 0, 0, -1, 0, -1, NULL, NULL, "in ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xed: IN rAX, DX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, &register_word_dx_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_IN, 0, 0, -1, 0, -1, NULL, NULL, "in ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xee: OUT DX, AL */
    SCInstr({-1, -1, -1, -1, &register_word_dx_s1, &register_byte_al_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_OUT, 0, 0, -1, 0, -1, NULL, NULL, "out ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xef: OUT DX, rAX */
    SCInstr({-1, -1, -1, -1, &register_word_dx_s1, &register_dword_eax_s1, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_OUT, 0, 0, -1, 0, -1, NULL, NULL, "out ", -1, -1, -1, -1, NULL, NULL}),

    /* 0xf0: PREFIX LOCK */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf1: INT1 */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_INT1, 0, 0, -1, 0, -1, NULL, NULL, "int1", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf2: PREFIX REPNZ */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf3: PREFIX REP */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf4: HLT */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_HLT, 0, 0, -1, 0, -1, NULL, NULL, "hlt", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf5: CMC */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_CMC, 0, 0, -1, 0, -1, NULL, NULL, "cmc", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf6: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_f6_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf7: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_f7_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf8: CLC */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_CLC, CF, 0, -1, 0, -1, NULL, NULL, "clc", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf9: STC */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_STC, CF, 0, -1, 0, -1, NULL, NULL, "stc", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfa: CLI */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_CLI, IF, 0, -1, 0, -1, NULL, NULL, "cli", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfb: STI */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_STI, IF, 0, -1, 0, -1, NULL, NULL, "sti", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfc: CLD */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_CLD, DF, 0, -1, 0, -1, NULL, NULL, "cld", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfd: STD */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, CLASS_STD, DF, 0, -1, 0, -1, NULL, NULL, "std", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfe: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_fe_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xff: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_ff_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
};

SCInstr getTwoByteOpcode[] = {
    /* 0x00: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_0f00_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x01: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_0f01_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x02: LAR r16/32, m16 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_LAR, ZF, 0, -1, 1, -1, NULL, NULL, "lar ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x03: LSL r16/32, m16 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_LSL, ZF, 0, -1, 1, -1, NULL, NULL, "lsl ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x04: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x05: SYSCALL */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, CF | PF | AF | ZF | SF | TF | IF | DF | OF, 0, -1, 0, -1, NULL, NULL, "syscall", -1, -1, -1, -1, NULL, NULL}),
    /* 0x06: CLTS CR0 */
    SCInstr({-1, -1, -1, -1, &cr_s1_cr0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, TS, 0, -1, 0, -1, NULL, NULL, "clts", -1, -1, -1, -1, NULL, NULL}),
    /* 0x07: SYSRET */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, CF | PF | AF | ZF | SF | TF | IF | DF | OF, 0, -1, 0, -1, NULL, NULL, "sysret", -1, -1, -1, -1, NULL, NULL}),
    /* 0x08: INVD */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "invd", -1, -1, -1, -1, NULL, NULL}),
    /* 0x09: WBINVD */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "wbinvd", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0a: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0b: UD2 */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "ud2", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0d: PREFETCHW m8 */
    SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, CF | PF | AF | ZF | SF | TF | IF | DF | OF, 0, -1, 1, -1, NULL, NULL, "prefetchw ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x10: MOVUPS xmm, xmm/m128 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movups ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x11: MOVUPS xmm/m128, xmm */
    SCInstr({-1, -1, -1, -1, &xmmmem_dqword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movups ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x12: MOVLPS xmm, xmm/m64 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movlps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x13: MOVLPS m64, xmm */
    SCInstr({-1, -1, -1, -1, &xmmmem_fixed_qword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movlps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x14: UNPCKLPS xmm, xmm/m64 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "unpcklps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x15: UNPCKLPS xmm, xmm/m64 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "unpcklps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x16: MOVLHPS xmm, xmm/m64 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x17: MOVHPS m64, xmm */
    SCInstr({-1, -1, -1, -1, &xmmmem_fixed_qword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movaps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x18: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_0f18_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x19: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1a: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1b: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1d: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x1f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x20: MOV r32, CRn */
    SCInstr({-1, -1, -1, -1, &register_fixed_dword_s1_s1_default, &cr_s1_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x21: MOV r32, DRn */
    SCInstr({-1, -1, -1, -1, &register_fixed_dword_s1_s1_default, &dr_s1_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x22: MOV CRn, r32 */
    SCInstr({-1, -1, -1, -1, &cr_s1_s1_s1, &register_fixed_dword_s1_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x23: MOV DRn, r32 */
    SCInstr({-1, -1, -1, -1, &dr_s1_s1_s1, &register_fixed_dword_s1_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x24: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x25: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x26: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x27: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x28: MOVAPS xmm, xmm/m128 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x29: MOVAPS xmm/m128, xmm */
    SCInstr({-1, -1, -1, -1, &xmmmem_dqword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2a: CVTPI2PS xmm, mm/m64 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cvtpi2ps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2b: MOVNTPS xmm/m128, xmm */
    SCInstr({-1, -1, -1, -1, &xmmmem_dqword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movntps ", -1, -1, -1, -1, NULL, NULL}),
    //不想写了...
    /* 0x2c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2d: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x2f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x30: WRMSR MSR, ECX, EAX, EDX */
    SCInstr({-1, -1, -1, -1, &msr_s1_s1_s1_default, &register_dword_ecx_s1_default, &register_dword_eax_s1_default, &register_dword_edx_s1_default,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "wrmsr", -1, -1, -1, -1, NULL, NULL}),
    /* 0x31: RDTSC EAX, EDX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &register_dword_edx_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "rdtsc", -1, -1, -1, -1, NULL, NULL}),
    /* 0x32: RDMSR EAX, EDX, ECX, MSR */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &register_dword_edx_s1_default, &register_dword_ecx_s1_default, &msr_s1_s1_s1_default,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "rdmsr", -1, -1, -1, -1, NULL, NULL}),
    /* 0x33: RDPMC EAX, EDX, PMC */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &register_dword_edx_s1_default, &pmc_s1_s1_s1_default, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "rdpmc", -1, -1, -1, -1, NULL, NULL}),
    /* 0x34: SYSENTER SS, ESP */
    SCInstr({-1, -1, -1, -1, &segment_s1_ss_s1_default, &register_dword_esp_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, IF, 0, -1, 0, -1, NULL, NULL, "sysenter", -1, -1, -1, -1, NULL, NULL}),
    /* 0x35: SYSEXIT SS, ESP */
    SCInstr({-1, -1, -1, -1, &segment_s1_ss_s1_default, &register_dword_esp_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "sysexit", -1, -1, -1, -1, NULL, NULL}),
    /* 0x36: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x37: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x38: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x39: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3a: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3b: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3d: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x3f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x40: CMOVO r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovo ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x41: CMOVNO r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovno ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x42: CMOVB r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x43: CMOVNB r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovnb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x44: CMOVZ r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovz ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x45: CMOVNZ r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovnz ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x46: CMOVBE r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovbe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x47: CMOVNBE r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovnbe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x48: CMOVS r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovs ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x49: CMOVNS r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovns ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4a: CMOVP r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovpe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4b: CMOVNP r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovpo ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4c: CMOVL r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovl ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4d: CMOVNL r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovnl ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4e: CMOVLE r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovle ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x4f: CMOVNLE r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cmovnle ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x50: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x51: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x52: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x53: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x54: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x55: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x56: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x57: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x58: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x59: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5a: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5b: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5d: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x5f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x60: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x61: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x62: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x63: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x64: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x65: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x66: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x67: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x68: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x69: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6a: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6b: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6d: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x6f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x70: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x71: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x72: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x73: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x74: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x75: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x76: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x77: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x78: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x79: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7a: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7b: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7c: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7d: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7e: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0x7f: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0x80: JO rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JO, 0, 0, -1, 1, -1, NULL, NULL, "jo ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x81: JNO rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNO, 0, 0, -1, 1, -1, NULL, NULL, "jno ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x82: JB rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JB, 0, 0, -1, 1, -1, NULL, NULL, "jb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x83: JNB rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION,CLASS_JNB,  0, 0, -1, 1, -1, NULL, NULL, "jnb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x84: JE rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JE, 0, 0, -1, 1, -1, NULL, NULL, "je ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x85: JNE rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNE, 0, 0, -1, 1, -1, NULL, NULL, "jne ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x86: JBE rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JBE, 0, 0, -1, 1, -1, NULL, NULL, "jbe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x87: JA rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JA, 0, 0, -1, 1, -1, NULL, NULL, "ja ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x88: JS rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JS, 0, 0, -1, 1, -1, NULL, NULL, "js ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x89: JNS rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JNS, 0, 0, -1, 1, -1, NULL, NULL, "jns ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8a: JPE rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JPE, 0, 0, -1, 1, -1, NULL, NULL, "jpe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8b: JPO rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JPO, 0, 0, -1, 1, -1, NULL, NULL, "jpo ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8c: JL rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JL, 0, 0, -1, 1, -1, NULL, NULL, "jl ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8d: JGE rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JGE, 0, 0, -1, 1, -1, NULL, NULL, "jge ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8e: JLE rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JLE, 0, 0, -1, 1, -1, NULL, NULL, "jle ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x8f: JG rel16/32  */
    SCInstr({-1, -1, -1, -1, &flow_reladdrfar_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JG, 0, 0, -1, 1, -1, NULL, NULL, "jg ", -1, -1, -1, -1, NULL, NULL}),

    /* 0x90: SETO r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "seto ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x91: SETNO r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setno ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x92: SETB r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x93: SETNB r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setnb ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x94: SETE r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "sete ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x95: SETNE r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setne ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x96: SETBE r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setbe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x97: SETA r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "seta ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x98: SETS r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "sets ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x99: SETNS r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setns ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9a: SETPE r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setpe ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9b: SETPO r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setpo ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9c: SETL r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setl ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9d: SETGE r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setge ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9e: SETLE r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setle ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9f: SETG r/m8  */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "setg ", -1, -1, -1, -1, NULL, NULL}),

    /* 0xa0: PUSH FS  */
    SCInstr({-1, -1, -1, -1, &segment_s1_fs_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa1: POP FS  */
    SCInstr({-1, -1, -1, -1, &segment_s1_fs_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa2: CPUID  */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &register_dword_ecx_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "cpuid", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa3: BT r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "bt ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa4: SHLD r/m16/32, r16/32, imm8 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, &immediate_byte_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "shld ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa5: SHLD r/m16/32, r16/32, CL */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, &register_byte_cl_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "shld ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa6: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa7: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa8: PUSH GS  */
    SCInstr({-1, -1, -1, -1, &segment_s1_gs_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xa9: POP GS  */
    SCInstr({-1, -1, -1, -1, &segment_s1_gs_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xaa: RSM Flags */
    SCInstr({-1, -1, -1, -1, &register_word_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, SF | AF | PF | OF | IF | TF | CF | ZF | DF, 0, -1, 0, -1, NULL, NULL, "rsm", -1, -1, -1, -1, NULL, NULL}),
    /* 0xab: BTS r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "bts ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xac: SHRD r/m16/32, r16/32, imm8 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, &immediate_byte_s1_s1, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "shrd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xad: SHRD r/m16/32, r16/32, CL */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, &register_byte_cl_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "shrd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xae: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_0fae_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xaf: IMUL r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IMUL, CF | OF, 0, -1, 1, -1, NULL, NULL, "imul ", -1, -1, -1, -1, NULL, NULL}),

    /* 0xb0: CMPXCHG r/m8, AL, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_al_s1_default, &register_byte_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF | CF | PF | AF | SF | OF, 0, -1, 1, -1, NULL, NULL, "cmpxchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb1: CMPXCHG r/m16/32, EAX, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_eax_s1_default, &register_dword_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF | CF | PF | AF | SF | OF, 0, -1, 1, -1, NULL, NULL, "cmpxchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb2: LSS SS, r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &segment_s1_ss_s1_default, &register_dword_s1_s1, &memory_fword_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lss ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb3: BTR r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "btr ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb4: LFS FS, r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &segment_s1_fs_s1_default, &register_dword_s1_s1, &memory_fword_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lfs ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb5: LGS GS, r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &segment_s1_gs_s1_default, &register_dword_s1_s1, &memory_fword_s1_s1, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lgs ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb6: MOVZX r16/32, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movzx ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb7: MOVZX r16/32, r/m16 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_word_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movzx ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb8: POPCNT r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_word_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, OF | SF | AF | CF | PF | ZF, 0, -1, 1, -1, NULL, NULL, "popcnt ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xb9: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xba: NEED FURTHER PARSED */
    SCInstr({-1, -1, -1, -1, &notexist_s1_0fba_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NEED_FURTHER_PARSED, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbb: BTC r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "btc ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbc: BSF r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF, 0, -1, 1, -1, NULL, NULL, "bsf ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbd: BSF r16/32, r/m16/32 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF, 0, -1, 1, -1, NULL, NULL, "bsr ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbe: MOVSX r16/32, r/m8 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movsx ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xbf: MOVSX r16/32, r/m16 */
    SCInstr({-1, -1, -1, -1, &register_dword_s1_s1, &memory_word_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movsx ", -1, -1, -1, -1, NULL, NULL}),

    /* 0xc0: XADD r/m8, r8 */
    SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF | PF | AF | SF | ZF | OF, 0, -1, 1, -1, NULL, NULL, "xadd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc1: XADD r/m16/32, r16/32 */
    SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF | PF | AF | SF | ZF | OF, 0, -1, 1, -1, NULL, NULL, "xadd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc2: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc3: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc4: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc5: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc6: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc7: CMPXCHG8B m64, EAX, EDX */
    SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1,
     &register_dword_eax_s1_default, &register_dword_edx_s1_default, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF, 0, -1, 1, -1, NULL, NULL, "cmpxchg8b ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc8: BSWAP EAX */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xc9: BSWAP ECX */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xca: BSWAP EDX */
    SCInstr({-1, -1, -1, -1, &register_dword_edx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcb: BSWAP EBX */
    SCInstr({-1, -1, -1, -1, &register_dword_ebx_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcc: BSWAP ESP */
    SCInstr({-1, -1, -1, -1, &register_dword_esp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcd: BSWAP EBP */
    SCInstr({-1, -1, -1, -1, &register_dword_ebp_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xce: BSWAP ESI */
    SCInstr({-1, -1, -1, -1, &register_dword_esi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcf: BSWAP EDI */
    SCInstr({-1, -1, -1, -1, &register_dword_edi_s1, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "bswap ", -1, -1, -1, -1, NULL, NULL}),

    //懒得写了
    /* 0xd0: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd1: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd2: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd3: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd4: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd5: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd6: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd7: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd8: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xda: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdb: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdc: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdd: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xde: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdf: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0xe0: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe1: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe2: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe3: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe4: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe5: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe6: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe7: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe8: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe9: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xea: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xeb: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xec: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xed: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xee: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xef: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),

    /* 0xf0: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf1: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf2: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf3: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf4: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf5: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf6: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf7: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf8: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xf9: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfa: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfb: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfc: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfd: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xfe: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* 0xff: UNDEFINED INSTRUCTION */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
};

SCInstr getOneByteWithAuxiliaryOpcode[][8] = {
    /* 0x80 */
    {
        /* AuxiliaryOpcode = 0: ADD r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: OR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: ADC r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: SBB r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: AND r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SUB r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: XOR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: CMP r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0x81 */
    {
        /* AuxiliaryOpcode = 0: ADD r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: OR r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: ADC r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: SBB r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: AND r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SUB r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: XOR r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: CMP r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0x82 */
    {
        /* AuxiliaryOpcode = 0: ADD r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: OR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: ADC r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: SBB r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: AND r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SUB r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: XOR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: CMP r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0x83 */
    {
        /* AuxiliaryOpcode = 0: ADD r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADD, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "add ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: OR r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_OR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "or ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: ADC r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ADC, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "adc ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: SBB r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SBB, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "sbb ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: AND r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AND, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "and ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SUB r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SUB, OF | SF | ZF | AF | CF | PF, CF, -1, 1, -1, NULL, NULL, "sub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: XOR r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_XOR, OF | SF | ZF | CF | PF, 0, -1, 1, -1, NULL, NULL, "xor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: CMP r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CMP, OF | SF | ZF | AF | CF | PF, 0, -1, 1, -1, NULL, NULL, "cmp ", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0x8f */
    {
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 1, -1, NULL, NULL, "pop ", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0xc0 */
    {
        /* AuxiliaryOpcode = 0: ROL r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROL, OF, CF, -1, 1, -1, NULL, NULL, "rol ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ROR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROR, OF, CF, -1, 1, -1, NULL, NULL, "ror ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: RCL r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCL, OF, CF, -1, 1, -1, NULL, NULL, "rcl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: RCR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCR, OF, CF, -1, 1, -1, NULL, NULL, "rcr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SHL r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SHR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: SAL r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sal ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SAR r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sar ", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0xc1 */
    {
        /* AuxiliaryOpcode = 0: ROL r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROL, OF, CF, -1, 1, -1, NULL, NULL, "rol ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ROR r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROR, OF, CF, -1, 1, -1, NULL, NULL, "ror ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: RCL r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCL, OF, CF, -1, 1, -1, NULL, NULL, "rcl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: RCR r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCR, OF, CF, -1, 1, -1, NULL, NULL, "rcr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SHL r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SHR r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: SAL r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sal ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SAR r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sar ", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0xc6 */
    {
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    },
    /* 0xc7 */
    {
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_MOV, 0, 0, -1, 1, -1, NULL, NULL, "mov ", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd0 */
    {
        /* AuxiliaryOpcode = 0: ROL r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ROL, OF, CF, -1, 1, -1, NULL, NULL, "rol ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ROR r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ROR, OF, CF, -1, 1, -1, NULL, NULL, "ror ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: RCL r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_RCL, OF, CF, -1, 1, -1, NULL, NULL, "rcl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: RCR r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_RCR, OF, CF, -1, 1, -1, NULL, NULL, "rcr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SHL r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SHL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SHR r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SHR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: SAL r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SAL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sal ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SAR r/m8, 1 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SAR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sar ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd1 */
    {
        /* AuxiliaryOpcode = 0: ROL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ROL, OF, CF, -1, 1, -1, NULL, NULL, "rol ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ROR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_ROR, OF, CF, -1, 1, -1, NULL, NULL, "ror ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: RCL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_RCL, OF, CF, -1, 1, -1, NULL, NULL, "rcl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: RCR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_RCR, OF, CF, -1, 1, -1, NULL, NULL, "rcr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SHL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SHL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SHR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SHR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: SAL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SAL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sal ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SAR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_SAR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sar ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd2 */
    {
        /* AuxiliaryOpcode = 0: ROL r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROL, OF, CF, -1, 1, -1, NULL, NULL, "rol ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ROR r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROR, OF, CF, -1, 1, -1, NULL, NULL, "ror ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: RCL r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCL, OF, CF, -1, 1, -1, NULL, NULL, "rcl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: RCR r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCR, OF, CF, -1, 1, -1, NULL, NULL, "rcr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SHL r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SHR r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: SAL r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sal ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SAR r/m8, CL */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sar ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd3 */
    {
        /* AuxiliaryOpcode = 0: ROL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROL, OF, CF, -1, 1, -1, NULL, NULL, "rol ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ROR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_ROR, OF, CF, -1, 1, -1, NULL, NULL, "ror ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: RCL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCL, OF, CF, -1, 1, -1, NULL, NULL, "rcl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: RCR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_RCR, OF, CF, -1, 1, -1, NULL, NULL, "rcr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SHL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shl ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: SHR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SHR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "shr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: SAL r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAL, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sal ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SAR r/m16/32, CL */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &register_byte_cl_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_SAR, OF | ZF | PF, CF, -1, 1, -1, NULL, NULL, "sar ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd8 */
    {
        /* AuxiliaryOpcode = 0: FADD ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FADD, C1, 0, -1, 1, -1, NULL, NULL, "fadd ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FMUL ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FMUL, C1, 0, -1, 1, -1, NULL, NULL, "fmul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FCOM ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCOMP ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FSUB ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUB, C1, 0, -1, 1, -1, NULL, NULL, "fsub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FSUBR ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUBR, C1, 0, -1, 1, -1, NULL, NULL, "fsubr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FDIV ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIV, C1, 0, -1, 1, -1, NULL, NULL, "fdiv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FDIVR ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fdivr ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd9 */
    {
        /* AuxiliaryOpcode = 0: FLD ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLD, C1, 0, -1, 1, -1, NULL, NULL, "fld ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FST ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FST, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fst ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FSTP ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fstp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FLDENV m14/28 */
        SCInstr({-1, -1, -1, -1, &memory_28_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDENV, 0, 0, -1, 1, -1, NULL, NULL, "fldenv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FLDCW m16 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDCW, 0, 0, -1, 1, -1, NULL, NULL, "fldcw ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FSTENV m14/28 */
        SCInstr({-1, -1, -1, -1, &memory_28_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTENV, 0, 0, -1, 1, -1, NULL, NULL, "fstenv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FSTCW m16 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDCW, C1, 0, -1, 1, -1, NULL, NULL, "fldcw ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xda */
    {
        /* AuxiliaryOpcode = 0: FIADD ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIADD, C1, 0, -1, 1, -1, NULL, NULL, "fiadd ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FIMUL ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIMUL, C1, 0, -1, 1, -1, NULL, NULL, "fimul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FICOM ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FICOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "ficom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FICOMP ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FICOMP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "ficomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FISUB ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISUB,C1, 0, -1, 1, -1, NULL, NULL, "fisub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FISUBR ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISUBR, C1, 0, -1, 1, -1, NULL, NULL, "fisubr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FIDIV ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIDIV, C1, 0, -1, 1, -1, NULL, NULL, "fidiv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FIDIVR ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fidivr ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdb */
    {
        /* AuxiliaryOpcode = 0: FILD ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FILD, C1, 0, -1, 1, -1, NULL, NULL, "fild ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FISTTP m32int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTTP, C1, 0, -1, 1, -1, NULL, NULL, "fisttp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FIST m32int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIST, C1, 0, -1, 1, -1, NULL, NULL, "fist ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FISTP m32int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTP, C1, 0, -1, 1, -1, NULL, NULL, "fistp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, C1, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FLD ST, m80real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_tbyte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLD, 0, 0, -1, 1, -1, NULL, NULL, "fld ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FCOMI ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMI, 0, 0, -1, 1, -1, NULL, NULL, "fcomi ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FSTP m80real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_tbyte_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTP, C1, 0, -1, 1, -1, NULL, NULL, "fstp ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdc */
    {
        /* AuxiliaryOpcode = 0: FADD ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FADD, C1, 0, -1, 1, -1, NULL, NULL, "fadd ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FMUL ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FMUL, C1, 0, -1, 1, -1, NULL, NULL, "fmul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FCOM ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCOMP ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FSUB ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUB, C1, 0, -1, 1, -1, NULL, NULL, "fsub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FSUBR ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUBR, C1, 0, -1, 1, -1, NULL, NULL, "fsubr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FDIV ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIV, C1, 0, -1, 1, -1, NULL, NULL, "fdiv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FDIVR ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fdivr ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdd */
    {
        /* AuxiliaryOpcode = 0: FLD ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLD, C1, 0, -1, 1, -1, NULL, NULL, "fld ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FISTTP m64real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTTP, C1, 0, -1, 1, -1, NULL, NULL, "fisttp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FST m64real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FST, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fst ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FSTP m64real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fstp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FRSTOR m94/108byte */
        SCInstr({-1, -1, -1, -1, &memory_108_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FRSTOR, 0, 0, -1, 1, -1, NULL, NULL, "frstor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FSAVE m94/108byte */
        SCInstr({-1, -1, -1, -1, &memory_108_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSAVE, 0, 0, -1, 1, -1, NULL, NULL, "fsave ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FSTSW m16 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTSW, C1, 0, -1, 1, -1, NULL, NULL, "fstsw ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xde */
    {
        /* AuxiliaryOpcode = 0: FIADD ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIADD, C1, 0, -1, 1, -1, NULL, NULL, "fiadd ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FIMUL ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIMUL, C1, 0, -1, 1, -1, NULL, NULL, "fimul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FICOM ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FICOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "ficom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FICOMP ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FICOMP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "ficomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FISUB ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISUB, C1, 0, -1, 1, -1, NULL, NULL, "fisub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FISUBR ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISUBR, C1, 0, -1, 1, -1, NULL, NULL, "fisubr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FIDIV ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIDIV, C1, 0, -1, 1, -1, NULL, NULL, "fidiv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FIDIVR ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fidivr ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdf */
    {
        /* AuxiliaryOpcode = 0: FILD ST0, m16int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FILD, C1, 0, -1, 1, -1, NULL, NULL, "fild ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: NOT DEFINED */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, C1, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FIST m16int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIST, C1, 0, -1, 1, -1, NULL, NULL, "fist ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FISTP m16int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTP, C1, 0, -1, 1, -1, NULL, NULL, "fistp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FBLD ST0, m80dec */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_tbyte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FBLD, C1, 0, -1, 1, -1, NULL, NULL, "fbld ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FILD ST, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FILD, 0, 0, -1, 1, -1, NULL, NULL, "fild ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FBSTP m80dec, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_tbyte_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FBSTP, 0, 0, -1, 1, -1, NULL, NULL, "fbstp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FISTP m64real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTP, C1, 0, -1, 1, -1, NULL, NULL, "fistp ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xf6 */
    {
        /* AuxiliaryOpcode = 0: TEST r/m8, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_TEST, OF | CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "test ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: NOT r/m8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_NOT, 0, 0, -1, 1, -1, NULL, NULL, "not ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: NEG r/m8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_NEG, CF | OF | SF | ZF | AF | PF, 0, -1, 1, -1, NULL, NULL, "neg ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: MUL AX, AL, r/m8 */
        SCInstr({-1, -1, -1, -1, &register_word_ax_s1_default, &register_byte_al_s1_default, &memory_byte_s1_s1, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MUL, OF | CF, 0, -1, 1, -1, NULL, NULL, "mul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: IMUL AX, AL, r/m8 */
        SCInstr({-1, -1, -1, -1, &register_word_ax_s1_default, &register_byte_al_s1_default, &memory_byte_s1_s1, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IMUL, OF | CF, 0, -1, 1, -1, NULL, NULL, "imul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: DIV AL, AH, AX, r/m8 */
        SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &register_byte_ah_s1_default, &register_word_ax_s1_default, &memory_byte_s1_s1,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DIV, 0, 0, -1, 1, -1, NULL, NULL, "div ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: IDIV AL, AH, AX, r/m8 */
        SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &register_byte_ah_s1_default, &register_word_ax_s1_default, &memory_byte_s1_s1,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IDIV, 0, 0, -1, 1, -1, NULL, NULL, "idiv ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xf7 */
    {
        /* AuxiliaryOpcode = 0: TEST r/m16/32, imm16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_TEST, OF | CF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "test ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: NOT r/m16/32*/
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_NOT, 0, 0, -1, 1, -1, NULL, NULL, "not ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: NEG r/m16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_NEG, CF | OF | SF | ZF | AF | PF, 0, -1, 1, -1, NULL, NULL, "neg ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: MUL rDX, rAX, r/m16/32 */
        SCInstr({-1, -1, -1, -1, &register_dword_edx_s1_default, &register_dword_eax_s1_default, &memory_dword_s1_s1, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_MUL, OF | CF, 0, -1, 1, -1, NULL, NULL, "mul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: IMUL rDX, rAX, r/m16/32 */
        SCInstr({-1, -1, -1, -1, &register_dword_edx_s1_default, &register_dword_eax_s1_default, &memory_dword_s1_s1, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IMUL, OF | CF, 0, -1, 1, -1, NULL, NULL, "imul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: DIV rDX, rAX, r/m16/32 */
        SCInstr({-1, -1, -1, -1, &register_dword_edx_s1_default, &register_dword_eax_s1_default, &memory_dword_s1_s1, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DIV, 0, 0, -1, 1, -1, NULL, NULL, "div ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: IDIV rDX, rAX, r/m16/32 */
        SCInstr({-1, -1, -1, -1, &register_dword_edx_s1_default, &register_dword_eax_s1_default, &memory_dword_s1_s1, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_IDIV, 0, 0, -1, 1, -1, NULL, NULL, "idiv ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xfe */
    {
        /* AuxiliaryOpcode = 0: INC r/m8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: DEC r/m8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xff */
    {
        /* AuxiliaryOpcode = 0: INC r/m16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_INC, OF | AF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "inc ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: DEC r/m16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_DEC, OF | AF | SF | ZF | PF, 0, -1, 1, -1, NULL, NULL, "dec ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: CALL r/m16/32  */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_CALL, 0, 0, -1, 1, -1, NULL, NULL, "call ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: CALLF r/m16/32  */
        SCInstr({-1, -1, -1, -1, &memory_fword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_CALLF, 0, 0, -1, 1, -1, NULL, NULL, "call far ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: JMP r/m16/32  */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JMP, 0, 0, -1, 1, -1, NULL, NULL, "jmp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: JMPF r/m16/32  */
        SCInstr({-1, -1, -1, -1, &memory_fword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JMPF, 0, 0, -1, 1, -1, NULL, NULL, "jmp far ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: PUSH r/m16/32 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 1, -1, NULL, NULL, "push ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, SPECIAL_MNEMONIC,  UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0x0f00 */
    {
        /* AuxiliaryOpcode = 0: SLDT m16, LDTR */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &ldtr_s1_s1_s1_default, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "sldt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: STR m16, TR */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &tr_s1_s1_s1_default, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "str ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: LLDT LDTR, m16  */
        SCInstr({-1, -1, -1, -1, &ldtr_s1_s1_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lldt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: LTR TR, m16  */
        SCInstr({-1, -1, -1, -1, &tr_s1_s1_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "ltr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: VERR r/m16  */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF, 0, -1, 1, -1, NULL, NULL, "verr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: VERW r/m16  */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, ZF, 0, -1, 1, -1, NULL, NULL, "verw ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0x0f01 */
    {
        /* AuxiliaryOpcode = 0: SGDT m, GDTR */
        SCInstr({-1, -1, -1, -1, &memory_fixed_fword_s1_s1, &gdtr_s1_s1_s1_default, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "sgdt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: SIDT m, IDTR */
        SCInstr({-1, -1, -1, -1, &memory_fixed_fword_s1_s1, &idtr_s1_s1_s1_default, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "sidt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: LGDT GDTR, m  */
        SCInstr({-1, -1, -1, -1, &gdtr_s1_s1_s1_default, &memory_fixed_fword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lgdt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: LIDT IDTR, m  */
        SCInstr({-1, -1, -1, -1, &idtr_s1_s1_s1_default, &memory_fixed_fword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lidt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: SMSW  m16, MSW */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &msw_s1_s1_s1_default, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "smsw ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: LMSW MSW, r/m16 */
        SCInstr({-1, -1, -1, -1, &msw_s1_s1_s1_default, &memory_word_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "lmsw ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: INVLPG m */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "invlpg ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0x0f18 */
    {
        /* AuxiliaryOpcode = 0: PREFETCHNTA m8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "prefetchnta ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: PREFETCHT0 m8 */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "prefetcht0 ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: PREFETCHT1 m8  */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "prefetcht1 ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: PREFETCHT2 m8  */
        SCInstr({-1, -1, -1, -1, &memory_byte_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "prefetcht2 ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0x0fae */
    {
        /* AuxiliaryOpcode = 0: FXSAVE m512 */
        SCInstr({-1, -1, -1, -1, &memory_512_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "fxsave ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FXRSTOR m512 */
        SCInstr({-1, -1, -1, -1, &memory_512_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "fxrstor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: LDMXCSR m32 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "ldmxcsr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: STMXCSR m32 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "stmxcsr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: XSAVE m32, EDX, EAX */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, &register_dword_edx_s1_default, &register_dword_eax_s1_default, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "xsave ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: XRSTOR m32 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_dword_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "xrstor ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: MFENCE */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "mfence", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: SFENCE */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "sfence", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0x0fba */
    {
        /* AuxiliaryOpcode = 0: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: BT r/m16/32, imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "bt ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: BTS r/m16/32 imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "bts ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: BTR r/m16/32 imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "btr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: BTC r/m16/32 imm8 */
        SCInstr({-1, -1, -1, -1, &memory_dword_s1_s1, &immediate_byte_s1_s1, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, CF, 0, -1, 1, -1, NULL, NULL, "btc ", -1, -1, -1, -1, NULL, NULL})
    }
};

SCInstr floatInstruction_2[][8] = {
    /* 0xd8_2 */
    {
        /* AuxiliaryOpcode = 0: FADD ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FADD, C1, 0, -1, 1, -1, NULL, NULL, "fadd ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FMUL ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FMUL, C1, 0, -1, 1, -1, NULL, NULL, "fmul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FCOM ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCOMP ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FSUB ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUB, C1, 0, -1, 1, -1, NULL, NULL, "fsub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FSUBR ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUBR, C1, 0, -1, 1, -1, NULL, NULL, "fsubr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FDIV ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIV, C1, 0, -1, 1, -1, NULL, NULL, "fdiv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FDIVR ST0, ST(i) */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fdivr ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xd9_2 */
    {
        /* AuxiliaryOpcode = 0: FLD ST0, m32real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLD, C1, 0, -1, 1, -1, NULL, NULL, "fld ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FXCH ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, UNDEFINED_CLASS, C1, 0, -1, 1, -1, NULL, NULL, "fxch ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FNOP */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, FLOAT_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "fnop", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xda_2 */
    {
        /* AuxiliaryOpcode = 0: FCMOVB ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVB, C1, 0, -1, 1, -1, NULL, NULL, "fcmovb ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FCMOVE ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVE, C1, 0, -1, 1, -1, NULL, NULL, "fcmove ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FCMOVBE ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVBE, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcmovbe ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCMOVU ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVU, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcmovu ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FISUB ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISUB, C1, 0, -1, 1, -1, NULL, NULL, "fisub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FUCOMPP ST0, ST1 */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_st1_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FUCOMPP, C1, 0, -1, 1, -1, NULL, NULL, "fucompp", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FIDIV ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIDIV, C1, 0, -1, 1, -1, NULL, NULL, "fidiv ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FIDIVR ST0, m32int */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_dword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fidivr ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdb_2 */
    {
        /* AuxiliaryOpcode = 0: FCMOVNB ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVNB, C1, 0, -1, 1, -1, NULL, NULL, "fcmovnb ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FCMOVNE ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVNE, C1, 0, -1, 1, -1, NULL, NULL, "fcmovne ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FCMOVNBE ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVNBE, C1, 0, -1, 1, -1, NULL, NULL, "fcmovnbe ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCMOVNU ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCMOVNU, C1, 0, -1, 1, -1, NULL, NULL, "fcmovnu ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: ??? */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, C1, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FUCOMI ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FUCOMI, 0, 0, -1, 1, -1, NULL, NULL, "fucomi ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FCOMI ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMI, 0, 0, -1, 1, -1, NULL, NULL, "fcomi ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FSTP m80real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_tbyte_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTP, C1, 0, -1, 1, -1, NULL, NULL, "fstp ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdc_2 */
    {
        /* AuxiliaryOpcode = 0: FADD STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FADD, C1, 0, -1, 1, -1, NULL, NULL, "fadd ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FMUL STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FMUL, C1, 0, -1, 1, -1, NULL, NULL, "fmul ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FCOM ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCOMP ST0, m64real */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &memory_fixed_qword_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fcomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FSUB STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUBR, C1, 0, -1, 1, -1, NULL, NULL, "fsubr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FSUBR STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUB, C1, 0, -1, 1, -1, NULL, NULL, "fsub ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FDIV STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIVR, C1, 0, -1, 1, -1, NULL, NULL, "fdivr ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FDIVR STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIV, C1, 0, -1, 1, -1, NULL, NULL, "fdiv ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdd_2 */
    {
        /* AuxiliaryOpcode = 0: FFREE STi */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FFREE, C1, 0, -1, 1, -1, NULL, NULL, "ffree ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FISTTP m64real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTTP, C1, 0, -1, 1, -1, NULL, NULL, "fisttp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FST ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FST, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fst ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FSTP ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTP, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "fstp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FUCOM ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FUCOM, 0, 0, -1, 1, -1, NULL, NULL, "fucom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FUCOMP ST0, STi*/
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FUCOMP, 0, 0, -1, 1, -1, NULL, NULL, "fucomp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FSAVE m94/108byte */
        SCInstr({-1, -1, -1, -1, &memory_108_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSAVE, 0, 0, -1, 1, -1, NULL, NULL, "fsave ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FSTSW m16 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTSW, C1, 0, -1, 1, -1, NULL, NULL, "fstsw ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xde_2 */
    {
        /* AuxiliaryOpcode = 0: FADDP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FADDP, C1, 0, -1, 1, -1, NULL, NULL, "faddp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: FMULP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FMULP, C1, 0, -1, 1, -1, NULL, NULL, "fmulp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FICOM STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FICOM, C1 | C2 | C3, 0, -1, 1, -1, NULL, NULL, "ficom ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FCOMPP ST0, ST1 */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_st1_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMPP, 0, 0, -1, 0, -1, NULL, NULL, "fcompp", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FSUBRP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUBRP, C1, 0, -1, 1, -1, NULL, NULL, "fsubrp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FSUBP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSUBP, C1, 0, -1, 1, -1, NULL, NULL, "fsubp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FDIVRP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIVRP, C1, 0, -1, 1, -1, NULL, NULL, "fdivrp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FDIVP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDIVP, C1, 0, -1, 1, -1, NULL, NULL, "fdivp ", -1, -1, -1, -1, NULL, NULL})
    },
    /* 0xdf_2 */
    {
        /* AuxiliaryOpcode = 0: FFREEP STi, ST0 */
        SCInstr({-1, -1, -1, -1, &float_s1_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FFREEP, C1, 0, -1, 1, -1, NULL, NULL, "ffreep ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 1: NOT DEFINED */
        SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, C1, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 2: FIST m16int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FIST, C1, 0, -1, 1, -1, NULL, NULL, "fist ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 3: FISTP m16int, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_word_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTP, C1, 0, -1, 1, -1, NULL, NULL, "fistp ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 4: FSTSW AX */
        SCInstr({-1, -1, -1, -1, &register_word_ax_s1, NULL, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSTSW, C1, 0, -1, 1, -1, NULL, NULL, "fstsw ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 5: FUCOMIP ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FUCOMIP, 0, 0, -1, 1, -1, NULL, NULL, "fucomip ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 6: FCOMIP ST0, STi */
        SCInstr({-1, -1, -1, -1, &float_s1_st0_s1, &float_s1_s1_s1, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOMIP, 0, 0, -1, 1, -1, NULL, NULL, "fcomip ", -1, -1, -1, -1, NULL, NULL}),
        /* AuxiliaryOpcode = 7: FISTP m64real, ST0 */
        SCInstr({-1, -1, -1, -1, &memory_fixed_qword_s1_s1, &float_s1_st0_s1_default, NULL, NULL,
         -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FISTP, C1, 0, -1, 1, -1, NULL, NULL, "fistp ", -1, -1, -1, -1, NULL, NULL})
    }
};

SCInstr specialInstruction[] = {
    /* 0xd9e0: FCHS ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCHS, C1, 0, -1, 0, -1, NULL, NULL, "fchs", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9e1: FABS ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FABS, C1, 0, -1, 0, -1, NULL, NULL, "fabs", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9e4: FTST ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FTST, C1, 0, -1, 0, -1, NULL, NULL, "ftst", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9e5: FXAM ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FXAM, C1, 0, -1, 0, -1, NULL, NULL, "fxam", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9e8: FLD1 ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLD1, C1, 0, -1, 0, -1, NULL, NULL, "fld1", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9e9: FLDL2T ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDL2T, C1, 0, -1, 0, -1, NULL, NULL, "fldl2t", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9ea: FLDL2E ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDL2T, C1, 0, -1, 0, -1, NULL, NULL, "fldl2t", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9eb: FLDPI ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDPI, C1, 0, -1, 0, -1, NULL, NULL, "fldpi", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9ec: FLDLG2 ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDLG2, C1, 0, -1, 0, -1, NULL, NULL, "fldlg2", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9ed: FLDLN2 ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDLN2, C1, 0, -1, 0, -1, NULL, NULL, "fldln2", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9ee: FLDZ ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FLDZ, C1, 0, -1, 0, -1, NULL, NULL, "fldz", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f0: F2XM1 ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_F2XM1, C1, 0, -1, 0, -1, NULL, NULL, "f2xm1", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f1: FYL2X ST1, ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st1_s1_default, &float_s1_st0_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FYL2X, C1, 0, -1, 0, -1, NULL, NULL, "fyl2x", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f2: FPTAN ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FPTAN, C1, 0, -1, 0, -1, NULL, NULL, "fptan", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f3: FPATAN STi, ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st1_s1_default, &float_s1_st0_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FAPTAN, C1, 0, -1, 1, -1, NULL, NULL, "faptan", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f4: FXTRACT ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FXTRACT, C1, 0, -1, 0, -1, NULL, NULL, "fxtract", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f5: FPREM1 ST0, ST1 */
    SCInstr({-1, -1, -1, -1, &float_s1_st1_s1_default, &float_s1_st0_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FPREM1, C1, 0, -1, 0, -1, NULL, NULL, "fprem1", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f6: FDECSTP */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDECSTP, C1, 0, -1, 0, -1, NULL, NULL, "fdecstp", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f7: FINCSTP */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FINCSTP, C1, 0, -1, 0, -1, NULL, NULL, "fincstp", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f8: FPREM ST0, ST1 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_st1_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FPREM, C1, 0, -1, 1, -1, NULL, NULL, "fprem", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9f9: FYL2XP1 ST1, ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st1_s1_default, &float_s1_st0_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FYL2XP1, C1, 0, -1, 0, -1, NULL, NULL, "fyl2xp1", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9fa: FSQRT ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSQRT, C1, 0, -1, 0, -1, NULL, NULL, "fsqrt", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9fb: FSINCOS ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSINCOS, C1, 0, -1, 0, -1, NULL, NULL, "fsincos", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9fc: FRNDINT ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FRNDINT, C1, 0, -1, 0, -1, NULL, NULL, "frndint", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9fd: FSCALE ST0, ST1 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, &float_s1_st1_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSCALE, C1, 0, -1, 0, -1, NULL, NULL, "fscale", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9fe: FSIN ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FSIN, C1, 0, -1, 0, -1, NULL, NULL, "fsin", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd9ff: FCOS ST0 */
    SCInstr({-1, -1, -1, -1, &float_s1_st0_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FCOS, C1, 0, -1, 0, -1, NULL, NULL, "fcos", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdbe0: FNENI */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FENI, 0, 0, -1, 0, -1, NULL, NULL, "feni", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdbe1: FNDISI */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FDISI, 0, 0, -1, 0, -1, NULL, NULL, "fdisi", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdbe2: FNCLEX */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FNCLEX, 0, 0, -1, 0, -1, NULL, NULL, "fnclex", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdbe3: FNINIT */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FNINIT, 0, 0, -1, 0, -1, NULL, NULL, "fninit", -1, -1, -1, -1, NULL, NULL}),
    /* 0xdbe4: FNSETPM */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, FLOAT_INSTRUCTION, CLASS_FNSETPM, 0, 0, -1, 0, -1, NULL, NULL, "fnsetpm", -1, -1, -1, -1, NULL, NULL}),
    /* 0x60_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_all_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "pushaw", -1, -1, -1, -1, NULL, NULL}),
    /* 0x61_1*/
    SCInstr({-1, -1, -1, -1, &register_dword_all_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "popaw", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9c_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_PUSH, 0, 0, -1, 0, -1, NULL, NULL, "pushfw", -1, -1, -1, -1, NULL, NULL}),
    /* 0x9d_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, STACK_OPERATE_INSTRUCTION, CLASS_POP, 0, 0, -1, 0, -1, NULL, NULL, "popfw", -1, -1, -1, -1, NULL, NULL}),
    /* 0x90_1 */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, IRREPLACEABLE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "pause", -1, -1, -1, -1, NULL, NULL}),
    /* 0x90_2 */
    SCInstr({-1, -1, -1, -1, &register_word_ax_s1, &register_word_ax_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_XCHG, 0, 0, -1, 0, -1, NULL, NULL, "xchg ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x98_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_eax_s1_default, &register_word_ax_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CWD, 0, 0, -1, 0, -1, NULL, NULL, "cbw", -1, -1, -1, -1, NULL, NULL}),
    /* 0x99_1 */
    SCInstr({-1, -1, -1, -1, &register_qword_edx_s1_default, &register_dword_eax_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, CLASS_CDQ, 0, 0, -1, 0, -1, NULL, NULL, "cwd", -1, -1, -1, -1, NULL, NULL}),
    /* 0xcf_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_all_flags_s1_default, NULL, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, STACK_OPERATE_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "iretw", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd4_1 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &register_byte_ah_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AAM, SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "aam", -1, -1, -1, -1, NULL, NULL}),
    /* 0xd5_1 */
    SCInstr({-1, -1, -1, -1, &register_byte_al_s1_default, &register_byte_ah_s1_default, NULL, NULL,
     -1, -1, -1, -1, 0, -1, -1, NORMAL_INSTRUCTION, CLASS_AAD, SF | ZF | PF, 0, -1, 0, -1, NULL, NULL, "aad", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe0_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1_default, &flow_reladdrshort_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_LOOPDNE, 0, 0, -1, 0, -1, NULL, NULL, "loopwne short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe1_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1_default, &flow_reladdrshort_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_LOOPDE, 0, 0, -1, 0, -1, NULL, NULL, "loopwe short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe2_1 */
    SCInstr({-1, -1, -1, -1, &register_dword_ecx_s1_default, &flow_reladdrshort_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_LOOPD, 0, 0, -1, 0, -1, NULL, NULL, "loopw short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0xe3_1 */
    SCInstr({-1, -1, -1, -1, &flow_reladdrshort_s1_s1, &register_dword_ecx_s1_default, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, FLOW_INSTRUCTION, CLASS_JEXCZ, 0, 0, -1, 0, -1, NULL, NULL, "jcxz short ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f10_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movss ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f10_2 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movupd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f10_3 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movsd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f11_1 */
    SCInstr({-1, -1, -1, -1, &xmmmem_fixed_dword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movss ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f11_2 */
    SCInstr({-1, -1, -1, -1, &xmmmem_dqword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movupd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f11_3 */
    SCInstr({-1, -1, -1, -1, &xmmmem_fixed_dword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movsd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f12_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movlpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f12_2 */
    SCInstr({-1, -1, -1, -1, &xmmre_fixed_dword_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movddup ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f12_3 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movsldup ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f12_4 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhlps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f13_1 */
    SCInstr({-1, -1, -1, -1, &xmmmem_fixed_qword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movlpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f14_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "unpcklpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f15_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "unpcklpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f16_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f16_2 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movshdup ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f16_3 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movlhps ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f17_1 */
    SCInstr({-1, -1, -1, -1, &xmmmem_fixed_qword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movapd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f28_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_dqword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f29_1 */
    SCInstr({-1, -1, -1, -1, &xmmmem_dqword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movhpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f2a_1 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &memory_fixed_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cvtpi2ss ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f2a_2 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &xmmmem_fixed_qword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cvtpi2pd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f2a_3 */
    SCInstr({-1, -1, -1, -1, &xmmre_xmm_s1_s1, &memory_fixed_dword_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "cvtsi2sd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0f2b_1 */
    SCInstr({-1, -1, -1, -1, &xmmmem_dqword_s1_s1, &xmmre_xmm_s1_s1, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, NORMAL_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 1, -1, NULL, NULL, "movntpd ", -1, -1, -1, -1, NULL, NULL}),
    /* 0x0fb8_1 */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, OF | SF | AF | CF | PF | ZF, 0, -1, 1, -1, NULL, NULL, "???", -1, -1, -1, -1, NULL, NULL}),
    /* only prefix */
    SCInstr({-1, -1, -1, -1, NULL, NULL, NULL, NULL,
     -1, -1, -1, -1, -1, -1, -1, UNDEFINED_INSTRUCTION, UNDEFINED_CLASS, 0, 0, -1, 0, -1, NULL, NULL, "", -1, -1, -1, -1, NULL, NULL})
};

#endif
