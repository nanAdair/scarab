#ifndef DIS_H
#define DIS_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "type.h"

#define MAX_INSTRUCTION_SIZE sizeof(INSTRUCTION)

/* prefix */
#define PREFIX_LOCK                 0xf0
#define PREFIX_REPN                 0xf2
#define PREFIX_REP                  0xf3
#define PREFIX_CS                   0x2e
#define PREFIX_SS                   0x36
#define PREFIX_DS                   0x3e
#define PREFIX_ES                   0x26
#define PREFIX_FS                   0x64
#define PREFIX_GS                   0x65
#define PREFIX_OPERAND              0x66
#define PREFIX_ADDRESS              0x67
#define LOCK                        0
#define REP                         1
#define REPE                        2
#define REPNE                       3
#define ES                          0
#define CS                          1
#define SS                          2
#define DS                          3
#define FS                          4
#define GS                          5
#define NOT_ONLY_PREFIX             0
#define ONLY_PREFIX                 1

/* register */
#define ADDRESSING_AX               9
#define ADDRESSING_CX               10
#define ADDRESSING_DX               11
#define ADDRESSING_BX               7
#define ADDRESSING_SP               12
#define ADDRESSING_BP               6
#define ADDRESSING_SI               4
#define ADDRESSING_DI               5
// Control Register
#define CR0                         0
#define CR1                         1
#define CR2                         2
#define CR3                         3
// for xlat
#define EBX_PLUS_AL                 8
// for pushad/pushfd, popad/popfd
#define ALL_32BITS_REGISTER         9
#define ALL_EFLAGS                  10

enum REGISTER_FOR_INT8{
    AL, CL, DL, BL, AH, CH, DH, BH, ALL_8BITS_REGISTER
};
enum REGISTER_FOR_INT16{
    AX, CX, DX, BX, SP, BP, SI, DI, ALL_16BITS_REGISTER
};
enum REGISTER_FOR_INT32{
    EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI
};
enum REGISTER_FOR_FLOAT{
    ST0, ST1, ST2, ST3, ST4, ST5, ST6, ST7
};

/* operand type */
enum OPERAND_TYPE{
    OPERAND_IMMEDIATE, OPERAND_MEMORY, OPERAND_REGISTER, OPERAND_SEGMENT,
    OPERAND_FLOAT, OPERAND_FLOW, OPERAND_MEMORY_OFFSET, OPERAND_LDTR,
    OPERAND_TR, OPERAND_GDTR, OPERAND_IDTR, OPERAND_MSW,
    OPERAND_CR, OPERAND_DR, OPERAND_XMM_MEMORY, OPERAND_XMM_REGISTER, OPERAND_MSR,
    OPERAND_PMC
};
/* instruction type */
enum INSTRUCTION_TYPE{
    UNDEFINED_INSTRUCTION,             // the opcode can't be parsed
    NORMAL_INSTRUCTION,                // arithmetic, move, etc
    STACK_OPERATE_INSTRUCTION,         // push, pop, etc
    FLOW_INSTRUCTION,                  // jump, call, return, etc
    IRREPLACEABLE_INSTRUCTION,         // int3, sysenter, in, out, etc
    FLOAT_INSTRUCTION,                 // kind of weird to put it here
    NEED_FURTHER_PARSED,               // this instruction need to be further parsed
    SPECIAL_MNEMONIC                   // special mnemonic
};
/* instruction class */
#define UNDEFINED_CLASS                0xff
enum NORMAL_INSTRUCTION_CLASS{
    CLASS_ADD, CLASS_OR, CLASS_ADC, CLASS_SBB,
    CLASS_AND, CLASS_DAA, CLASS_SUB, CLASS_DAS,
    CLASS_XOR, CLASS_AAA, CLASS_CMP, CLASS_AAS,
    CLASS_INC, CLASS_DEC, CLASS_BOUND, CLASS_ARPL,
    CLASS_IMUL, CLASS_TEST, CLASS_XCHG, CLASS_MOV,
    CLASS_LEA, CLASS_CWD, CLASS_CDQ, CLASS_SAHF,
    CLASS_LAHF, CLASS_MOVS, CLASS_CMPS, CLASS_STOS,
    CLASS_LODS, CLASS_SCAS, CLASS_ROL, CLASS_ROR,
    CLASS_RCL, CLASS_RCR, CLASS_SHL, CLASS_SHR,
    CLASS_SAL, CLASS_SAR, CLASS_LES, CLASS_LDS,
    CLASS_AAM, CLASS_AAD, CLASS_SALC, CLASS_XLAT,
    CLASS_NOT, CLASS_NEG, CLASS_MUL, CLASS_DIV,
    CLASS_IDIV, CLASS_LAR, CLASS_LSL
};
enum STACK_OPERATE_INSTRUCTION_CLASS{
    CLASS_PUSH, CLASS_POP, CLASS_PUSHAD, CLASS_POPAD,
    CLASS_PUSHFD, CLASS_POPFD, CLASS_INFO, CLASS_IRETD
};
enum FLOW_INSTRUCTION_CLASS{
    CLASS_JO, CLASS_JNO, CLASS_JB, CLASS_JNB,
    CLASS_JE, CLASS_JNE, CLASS_JBE, CLASS_JA,
    CLASS_JS, CLASS_JNS, CLASS_JPE, CLASS_JPO,
    CLASS_JL, CLASS_JGE, CLASS_JLE, CLASS_JG,
    CLASS_CALLF, CLASS_RETN, CLASS_RETF, CLASS_LOOPDNE,
    CLASS_LOOPDE, CLASS_LOOPD, CLASS_JEXCZ, CLASS_CALL,
    CLASS_JMP, CLASS_JMPF, CLASS_JMP_SHORT
};
enum FLOAT_INSTRUCTION_CLASS{
    CLASS_FADD, CLASS_FMUL, CLASS_FCOM, CLASS_FCOMP,
    CLASS_FSUB, CLASS_FSUBR, CLASS_FDIV, CLASS_FDIVR,
    CLASS_FLD, CLASS_FXCH, CLASS_FNOP, CLASS_FCMOVB,
    CLASS_FCMOVE, CLASS_FCMOVBE, CLASS_FCMOVU, CLASS_FISUB,
    CLASS_FUCOMPP, CLASS_FIDIV, CLASS_FIFIVR, CLASS_FCMOVNB,
    CLASS_FCMOVNE, CLASS_FCMOVNBE, CLASS_FCMOVNU, CLASS_FUCOMI,
    CLASS_FCOMI, CLASS_FSTP, CLASS_FFREE, CLASS_FISTTP,
    CLASS_FST, CLASS_FUCOM, CLASS_FUCOMP,
    CLASS_FSAVE, CLASS_FSTSW, CLASS_FADDP, CLASS_FMULP,
    CLASS_FICOM, CLASS_FCOMPP, CLASS_FSUBRP,
    CLASS_FSUBP, CLASS_FDIVRP, CLASS_FDIVP, CLASS_FFREEP,
    CLASS_FIST, CLASS_FISTP, CLASS_FUCOMIP, CLASS_FCOMIP,
    CLASS_FCHS, CLASS_FABS, CLASS_FSTS, CLASS_FXAM,
    CLASS_FLD1, CLASS_FLDL2T, CLASS_FLDL2E, CLASS_FLDPI,
    CLASS_FLDLG2, CLASS_FLDLN2, CLASS_FLDZ, CLASS_F2XM1,
    CLASS_FYL2X, CLASS_FPTAN, CLASS_FPATAN, CLASS_FXTRACT,
    CLASS_FPREM1, CLASS_FDECSTP, CLASS_FINCSTP, CLASS_FPREM,
    CLASS_FYL2XP1, CLASS_FSQRT, CLASS_FSINCOS, CLASS_FRNDINT,
    CLASS_FSCALE, CLASS_FSIN, CLASS_FCOS, CLASS_FNENI,
    CLASS_FNDISI, CLASS_FNCLEX, CLASS_FNINIT, CLASS_FNSETPM,
    CLASS_FRSTOR, CLASS_FIADD, CLASS_FIMUL,CLASS_FICOMP,
    CLASS_FISUBR, CLASS_FIDIVR, CLASS_FLDENV, CLASS_FLDCW,
    CLASS_FSTENV, CLASS_FSTCW, CLASS_FILD, CLASS_FBLD,
    CLASS_FBSTP, CLASS_FTST, CLASS_FAPTAN, CLASS_FENI,
    CLASS_FDISI
};
enum IRREPLACEABLE_INSTRUCTION{
    CLASS_NOP, CLASS_INS, CLASS_OUTS, CLASS_WAIT,
    CLASS_ENTER, CLASS_LEAVE, CLASS_INT3, CLASS_INT,
    CLASS_IN, CLASS_OUT, CLASS_INT1, CLASS_HLT,
    CLASS_CMC, CLASS_CLC, CLASS_STC, CLASS_CLI,
    CLASS_STI, CLASS_CLD, CLASS_STD
};

/* immediate type */
enum IMMEDIATE_TYPE{
    IS_IMMEDIATE, IS_DISPLACEMENT, IS_NEW_CS, IS_NEW_EIP, IS_OFFSET
};
/* operand size */
enum OPERAND_SIZE{
    SIZE_INT8, SIZE_INT16, SIZE_INT32, SIZE_FIXED_INT32,
    SIZE_FINT16, SIZE_FIXED_FINT16, SIZE_QINT16, SIZE_FIXED_QINT16,
    SIZE_TINT8, SIZE_DQINT16, RELATIVE_ADDRESS_SHORT, ADDRESS_FAR_ABSOLUTE,
    ADDRESS_FAR_ABSOLUTE_INT32, ADDRESS_FAR_ABSOLUTE_INT16, RELATIVE_ADDRESS_FAR,
    RELATIVE_ADDRESS_FAR_INT32, RELATIVE_ADDRESS_FAR_INT16, SIZE_XMM, SIZE_MM
};

/* pwd */
#define CF                          0x1
#define PF                          0x2
#define AF                          0x4
#define ZF                          0x8
#define SF                          0x10
#define TF                          0x20
#define IF                          0x40
#define DF                          0x80
#define OF                          0x100
// FPU flags
#define C0                          0x200
#define C1                          0x400
#define C2                          0x800
#define C3                          0x1000
// Control Register flags
#define PE                          0x2000
#define MP                          0x4000
#define EM                          0x8000
#define TS                          0x10000
#define ET                          0x20000
#define NE                          0x40000
#define WP                          0x80000
#define AM                          0x100000
#define NW                          0x200000
#define CD                          0x400000
#define PG                          0x800000

/* return condition */
/* for prefix */
#define NOT_PREFIX                  0
#define COLLIDED_PREFIX             -1
#define CONTINUE_DECODING_PREFIX    1
#define PREFIX_NOT_QUALIFY          0
#define PREFIX_QUALIFY              1
/* for addImmediate */
#define NOT_ENOUGH_CODE             0
#define ADD_SUCCESS                 1
/* for decodeModRM */
#define OPERAND_NOT_EXIST           1
#define DECODE_SUCCESS              2
#define DEFAULT_REGISTER            3
/* operand order */
#define FIRST_OPERAND               0
#define SECOND_OPERAND              1
#define THIRD_OPERAND               2
#define FOURTH_OPERAND              3
// addImmediate argument
#define HAS_NO_REGISTER             1
#define HAS_REGISTER                0
#define IS_NOT_FIXED_SIZE           0
#define IS_FIXED_SIZE               1
#define IS_NOT_ABSOLUTE             0
#define IS_ABSOLUTE                 1
// Section type
#define SECTION_OTHER               0
#define SECTION_INIT                1
#define SECTION_TEXT                2
#define SECTION_FINI                3
#define SECTION_PLT                 4

typedef struct _Operand{
    /* segment */
    INT8 segment;
    /* Store register number or immediate */
    INT32 operand;
    /* Store operand size */
    int operand_size;
    /* Store operand type */
    INT8 type;
    /* use for addressing */
    INT8 scale;
    INT8 index;
    INT8 base;
    /* displacement */
    INT32 displacement;
    int displacement_size;
    /* addressing size, if exists */
    INT8 addressing_size;
    /* whether this operand is a default register */
    bool isDefault;
} Operand;

typedef struct _INSTRUCTION{
    /* prefixes */
    INT8 lockAndRepeat;
    INT8 segmentOverride;
    INT8 OperandSizeOverride;
    INT8 AddressSizeOverride;
    /* operands */
    Operand *dest;
    Operand *src1;
    Operand *src2;
    Operand *src3;
    /* use for addressing */
    INT8 mod;
    INT8 rm;
    INT8 regop;
    /* flags */
    INT32 secType;
    INT8 s;        // sign or not
    /* address and final address */
    INT32 address;
    INT32 final_address;
    /* instruction type */
    INT8 type;
    /* instruction class */
    int instr_class;
    /* pwd that might be affected */
    INT32 pwd_affected;
    /* pwd that used */
    INT32 pwd_used;
    /* opcode */
    INT32 opcode;
    /* have ModR/M or not */
    bool ModRM;
    /* SIB */
    INT8 SIB;
    /* assembly */
    char *assembly;
    /* return machine code */
    char *ret_machineCode;
    /* mnemonic */
    const char *mnemonic;
    /* new CS and ESP(if existed) */
    INT16 new_cs;
    INT32 new_eip;
} INSTRUCTION;

#endif
