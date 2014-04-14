#include "disasm.h"
#include "dis-table.h"

const char *RepeatPrefixes[] = {"lock", "rep", "repe", "repne"};
const char *SegmentRegisters[] = {"es", "cs", "ss", "ds", "fs", "gs", "seg?", "seg?"};
const char *Register32[] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi", "ebx + al"};
const char *Register16[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
const char *Register8[] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
const char *Register16_ModRM[] = {"bx + si", "bx + di", "bp + si", "bp + di", "si", "di", "bp", "bx", "bx + al", "ax", "cx", "dx", "sp"};
const char *FloatPointRegister[] = {"st(0)", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)"};
const char *ControlRegister[] = {"cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7"};
const char *DebugRegister[] = {"dr0", "dr1", "dr2", "dr3", "dr4", "dr5", "dr6", "dr7"};
const char *XMMRegister[] = {"xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"};
const char *MMRegister[] = {"mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7"};
const char *PTR[] = {"word ptr ", "dword ptr ", "word ptr ", "byte ptr "};

Disasm::Disasm()
{
    currentByte = 0;
    codeSize = 0;
    address = 0;
    base = 0;
}

INT8 Disasm::decodePrefix()
{
    currentByte++;
    switch((unsigned char)machineCode[currentByte - 1]){
    case PREFIX_LOCK:
        if (lockAndRepeat != -1)
            return COLLIDED_PREFIX;
        lockAndRepeat = PREFIX_LOCK;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_REPN:
        if (lockAndRepeat != -1)
            return COLLIDED_PREFIX;
        lockAndRepeat = PREFIX_REPN;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_REP:
        if (lockAndRepeat != -1)
            return COLLIDED_PREFIX;
        lockAndRepeat = PREFIX_REP;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_CS:
        if (segmentOverride != -1)
            return COLLIDED_PREFIX;
        segmentOverride = CS;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_SS:
        if (segmentOverride != -1)
            return COLLIDED_PREFIX;
        segmentOverride = SS;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_DS:
        if (segmentOverride != -1)
            return COLLIDED_PREFIX;
        segmentOverride = DS;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_ES:
        if (segmentOverride != -1)
            return COLLIDED_PREFIX;
        segmentOverride = ES;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_FS:
        if (segmentOverride != -1)
            return COLLIDED_PREFIX;
        segmentOverride = FS;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_GS:
        if (segmentOverride != -1)
            return COLLIDED_PREFIX;
        segmentOverride = GS;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_OPERAND:
        if (OperandSizeOverride != -1)
            return COLLIDED_PREFIX;
        OperandSizeOverride = PREFIX_OPERAND;
        return CONTINUE_DECODING_PREFIX;
    case PREFIX_ADDRESS:
        if (AddressSizeOverride != -1)
            return COLLIDED_PREFIX;
        AddressSizeOverride = PREFIX_ADDRESS;
        return CONTINUE_DECODING_PREFIX;
    default:
        currentByte--;
    }
    return NOT_PREFIX;
}

void Disasm::preprocessingFloatPointInstruction()
{
    INT8 mod = (machineCode[currentByte] >> 6) & 3;
    INT8 rm = (machineCode[currentByte]) & 7;
    INT8 regop = (machineCode[currentByte] >> 3) & 7;
    INT32 opcode = instruction->opcode;
    currentByte++;

    switch(opcode){
    case 0xd8:
    {
        if (mod != 3)
            break;
        memcpy(instruction, &floatInstruction_2[FLOAT_d8][regop & 7], sizeof(INSTRUCTION));
        break;
    }
    case 0xd9:
    {
        switch((unsigned char)regop){
        case 0:
        {
            if (mod != 3)
                break;
            memcpy(instruction, &floatInstruction_2[FLOAT_d9][regop & 7], sizeof(INSTRUCTION));
            break;
        }
        case 1:
        {
            if (mod != 3)
                break;
            memcpy(instruction, &floatInstruction_2[FLOAT_d9][regop & 7], sizeof(INSTRUCTION));
            break;
        }
        case 2:
        {
            // modR/M = 0xd0
            if ((unsigned char)machineCode[currentByte - 1] == 0xd0)
                memcpy(instruction, &floatInstruction_2[FLOAT_d9][regop & 7], sizeof(INSTRUCTION));
            break;
        }
        case 4:
        {
            if ((unsigned char)machineCode[currentByte - 1] == 0xe0)
                memcpy(instruction, &specialInstruction[SPECIAL_d9e0], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xe1)
                memcpy(instruction, &specialInstruction[SPECIAL_d9e1], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xe4)
                memcpy(instruction, &specialInstruction[SPECIAL_d9e4], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xe5)
                memcpy(instruction, &specialInstruction[SPECIAL_d9e5], sizeof(INSTRUCTION));
            break;
        }
        case 5:
        {
            if ((unsigned char)machineCode[currentByte - 1] == 0xe8)
                memcpy(instruction, &specialInstruction[SPECIAL_d9e8], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xe9)
                memcpy(instruction, &specialInstruction[SPECIAL_d9e9], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xea)
                memcpy(instruction, &specialInstruction[SPECIAL_d9ea], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xeb)
                memcpy(instruction, &specialInstruction[SPECIAL_d9eb], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xec)
                memcpy(instruction, &specialInstruction[SPECIAL_d9ec], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xed)
                memcpy(instruction, &specialInstruction[SPECIAL_d9ed], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xee)
                memcpy(instruction, &specialInstruction[SPECIAL_d9ee], sizeof(INSTRUCTION));
            break;
        }
        case 6:
        {
            if ((unsigned char)machineCode[currentByte - 1] == 0xf0)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f0], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf1)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f1], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf2)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f2], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf3)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f3], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf4)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f4], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf5)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f5], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf6)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f6], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf7)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f7], sizeof(INSTRUCTION));
            break;
        }
        case 7:
        {
            if ((unsigned char)machineCode[currentByte - 1] == 0xf8)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f8], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xf9)
                memcpy(instruction, &specialInstruction[SPECIAL_d9f9], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xfa)
                memcpy(instruction, &specialInstruction[SPECIAL_d9fa], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xfb)
                memcpy(instruction, &specialInstruction[SPECIAL_d9fb], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xfc)
                memcpy(instruction, &specialInstruction[SPECIAL_d9fc], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xfd)
                memcpy(instruction, &specialInstruction[SPECIAL_d9fd], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xfe)
                memcpy(instruction, &specialInstruction[SPECIAL_d9fe], sizeof(INSTRUCTION));
            else if ((unsigned char)machineCode[currentByte - 1] == 0xff)
                memcpy(instruction, &specialInstruction[SPECIAL_d9ff], sizeof(INSTRUCTION));
            break;
        }
        }
        break;
    }
    case 0xda:
    {
        if (mod != 3)
            break;
        if (regop == 5 && (unsigned char)machineCode[currentByte - 1] != 0xe9)
            break;
        memcpy(instruction, &floatInstruction_2[FLOAT_da][regop & 7], sizeof(INSTRUCTION));
        break;
    }
    case 0xdb:
    {
        if ((unsigned char)machineCode[currentByte - 1] == 0xe0)
            memcpy(instruction, &specialInstruction[SPECIAL_dbe0], sizeof(INSTRUCTION));
        else if ((unsigned char)machineCode[currentByte - 1] == 0xe1)
            memcpy(instruction, &specialInstruction[SPECIAL_dbe1], sizeof(INSTRUCTION));
        else if ((unsigned char)machineCode[currentByte - 1] == 0xe2)
            memcpy(instruction, &specialInstruction[SPECIAL_dbe2], sizeof(INSTRUCTION));
        else if ((unsigned char)machineCode[currentByte - 1] == 0xe3)
            memcpy(instruction, &specialInstruction[SPECIAL_dbe3], sizeof(INSTRUCTION));
        else if ((unsigned char)machineCode[currentByte - 1] == 0xe4)
            memcpy(instruction, &specialInstruction[SPECIAL_dbe4], sizeof(INSTRUCTION));
        else{
            if (mod != 3)
                break;
            memcpy(instruction, &floatInstruction_2[FLOAT_db][regop & 7], sizeof(INSTRUCTION));
        }
        break;
    }
    case 0xdc:
    {
        if (mod != 3)
            break;
        memcpy(instruction, &floatInstruction_2[FLOAT_dc][regop & 7], sizeof(INSTRUCTION));
        break;
    }
    case 0xdd:
    {
        if (mod != 3)
            break;
        memcpy(instruction, &floatInstruction_2[FLOAT_dd][regop & 7], sizeof(INSTRUCTION));
        break;
    }
    case 0xde:
    {
        if (mod != 3)
            break;
        if (regop == 3 && (unsigned char)machineCode[currentByte - 1] != 0xd9)
            break;
        memcpy(instruction, &floatInstruction_2[FLOAT_de][regop & 7], sizeof(INSTRUCTION));
        break;
    }
    case 0xdf:
    {
        if (mod != 3)
            break;
        if (regop == 4 && (unsigned char)machineCode[currentByte - 1] != 0xe0)
            break;
        memcpy(instruction, &floatInstruction_2[FLOAT_df][regop & 7], sizeof(INSTRUCTION));
        break;
    }
    default:
        break;
    }
    instruction->rm = rm;
    instruction->regop = regop;
    instruction->mod = mod;
    instruction->opcode = opcode;

    if ((instruction->dest && instruction->dest->type == OPERAND_MEMORY) ||
        (instruction->src1 && instruction->src1->type == OPERAND_MEMORY) ||
        (instruction->src2 && instruction->src2->type == OPERAND_MEMORY) ||
        (instruction->src3 && instruction->src3->type == OPERAND_MEMORY) ||
        instruction->type == UNDEFINED_INSTRUCTION)
        currentByte--;
}

INT8 Disasm::specialMnemonicProcess()
{
    INT32 opcode = instruction->opcode;
    switch(opcode){
    // PUSHAD
    case 0x60:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_60], sizeof(INSTRUCTION));
        instruction->type = STACK_OPERATE_INSTRUCTION;
        break;
    }
    // POPAD
    case 0x61:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_61], sizeof(INSTRUCTION));
        instruction->type = STACK_OPERATE_INSTRUCTION;
        break;
    }
    // PUSHFD
    case 0x9c:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_9c], sizeof(INSTRUCTION));
        instruction->type = STACK_OPERATE_INSTRUCTION;
        break;
    }
    // POPFD
    case 0x9d:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_9d], sizeof(INSTRUCTION));
        instruction->type = STACK_OPERATE_INSTRUCTION;
        break;
    }
    // NOP
    case 0x90:{
        if ((unsigned char)lockAndRepeat == PREFIX_REP)
            memcpy(instruction, &specialInstruction[SPECIAL_90_1], sizeof(INSTRUCTION));
    else if (OperandSizeOverride == PREFIX_OPERAND)
        memcpy(instruction, &specialInstruction[SPECIAL_90_2], sizeof(INSTRUCTION));
    else
        instruction->type = IRREPLACEABLE_INSTRUCTION;
        break;
    }
    // CBW
    case 0x98:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_98], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    // CDQ
    case 0x99:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_99], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    // IRET
    case 0xcf:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_cf], sizeof(INSTRUCTION));
        instruction->type = STACK_OPERATE_INSTRUCTION;
        break;
    }
    // AAM
    case 0xd4:{
        if ((unsigned char)machineCode[currentByte] == 0x0a){
            currentByte++;
            memcpy(instruction, &specialInstruction[SPECIAL_d4], sizeof(INSTRUCTION));
        }
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    // AAD
    case 0xd5:{
        if ((unsigned char)machineCode[currentByte] == 0x0a){
            currentByte++;
            memcpy(instruction, &specialInstruction[SPECIAL_d5], sizeof(INSTRUCTION));
        }
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0xe0:
    {
        if (AddressSizeOverride == PREFIX_ADDRESS)
            memcpy(instruction, &specialInstruction[SPECIAL_e0], sizeof(INSTRUCTION));
        instruction->type = FLOW_INSTRUCTION;
        break;
    }
    case 0xe1:
    {
        if (AddressSizeOverride == PREFIX_ADDRESS)
            memcpy(instruction, &specialInstruction[SPECIAL_e1], sizeof(INSTRUCTION));
        instruction->type = FLOW_INSTRUCTION;
        break;
    }
    case 0xe2:
    {
        if (AddressSizeOverride == PREFIX_ADDRESS)
            memcpy(instruction, &specialInstruction[SPECIAL_e2], sizeof(INSTRUCTION));
        instruction->type = FLOW_INSTRUCTION;
        break;
    }
    case 0xe3:
    {
        if (AddressSizeOverride == PREFIX_ADDRESS)
            memcpy(instruction, &specialInstruction[SPECIAL_e3], sizeof(INSTRUCTION));
        instruction->type = FLOW_INSTRUCTION;
        break;
    }
    // AUXILIARY OPCODE = 7
    case 0xff:{
        currentByte++;
        instruction->type = UNDEFINED_INSTRUCTION;
        break;
    }
    // 0x0f10
    case 0x0f10:{
        if ((unsigned char)lockAndRepeat == PREFIX_REP)
            memcpy(instruction, &specialInstruction[SPECIAL_0f10_1], sizeof(INSTRUCTION));
        else if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f10_2], sizeof(INSTRUCTION));
        else if ((unsigned char)lockAndRepeat == PREFIX_REPN)
            memcpy(instruction, &specialInstruction[SPECIAL_0f10_3], sizeof(INSTRUCTION));
        lockAndRepeat = -1;
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f11:{
        if ((unsigned char)lockAndRepeat == PREFIX_REP)
            memcpy(instruction, &specialInstruction[SPECIAL_0f11_1], sizeof(INSTRUCTION));
        else if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f11_2], sizeof(INSTRUCTION));
        else if ((unsigned char)lockAndRepeat == PREFIX_REPN)
            memcpy(instruction, &specialInstruction[SPECIAL_0f11_3], sizeof(INSTRUCTION));
        lockAndRepeat = -1;
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f12:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f12_1], sizeof(INSTRUCTION));
        else if ((unsigned char)lockAndRepeat == PREFIX_REPN && ((machineCode[currentByte] >> 6) & 3) != 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f12_2], sizeof(INSTRUCTION));
        else if ((unsigned char)lockAndRepeat == PREFIX_REP && ((machineCode[currentByte] >> 6) & 3) != 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f12_3], sizeof(INSTRUCTION));
        else if (((machineCode[currentByte] >> 6) & 3) == 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f12_4], sizeof(INSTRUCTION));
        lockAndRepeat = -1;
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f13:{
        if (((machineCode[currentByte] >> 6) & 3) == 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f13], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f14: case 0x0f15:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f14], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f16:{
        if (OperandSizeOverride == PREFIX_OPERAND && ((machineCode[currentByte] >> 6) & 3) != 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f16_1], sizeof(INSTRUCTION));
        else if ((unsigned char)lockAndRepeat == PREFIX_REP && ((machineCode[currentByte] >> 6) & 3) != 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f16_2], sizeof(INSTRUCTION));
        else if (((machineCode[currentByte] >> 6) & 3) == 3)
            memcpy(instruction, &specialInstruction[SPECIAL_0f16_3], sizeof(INSTRUCTION));
        lockAndRepeat = -1;
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f17:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f17], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f28:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f28], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f29:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f29], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f2a:{
        if ((unsigned char)lockAndRepeat == PREFIX_REP)
            memcpy(instruction, &specialInstruction[SPECIAL_0f2a_1], sizeof(INSTRUCTION));
        else if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f2a_2], sizeof(INSTRUCTION));
        else if ((unsigned char)lockAndRepeat == PREFIX_REPN)
            memcpy(instruction, &specialInstruction[SPECIAL_0f2a_3], sizeof(INSTRUCTION));
        lockAndRepeat = -1;
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0f2b:{
        if (OperandSizeOverride == PREFIX_OPERAND)
            memcpy(instruction, &specialInstruction[SPECIAL_0f2b], sizeof(INSTRUCTION));
        instruction->type = NORMAL_INSTRUCTION;
        break;
    }
    case 0x0fb8:{
        if ((unsigned char)lockAndRepeat != PREFIX_REP)
            memcpy(instruction, &specialInstruction[SPECIAL_0fb8], sizeof(INSTRUCTION));
        lockAndRepeat = -1;
        break;
    }
    default:
        break;
    }
    instruction->opcode = opcode;
    return DECODE_SUCCESS;
}

INT8 Disasm::validatePrefix(){
    if (lockAndRepeat == -1)
        return PREFIX_QUALIFY;

    if ((unsigned char)lockAndRepeat == PREFIX_LOCK)
        lockAndRepeat = LOCK;
    else if ((unsigned char)lockAndRepeat == PREFIX_REP){
        switch (instruction->opcode) {
        case 0x6c: case 0x6d: case 0xa4: case 0xa5: case 0x6e: case 0x6f: case 0xac: case 0xad:
        case 0xaa: case 0xab:
            lockAndRepeat = REP;
            break;
        case 0xa6: case 0xa7: case 0xae: case 0xaf: case 0xc3:
            lockAndRepeat = REPE;
            break;
        default:
            return PREFIX_NOT_QUALIFY;
        }
    }
    else{
        switch (instruction->opcode) {
        case 0xa6: case 0xa7: case 0xae: case 0xaf:
            lockAndRepeat = REPNE;
            break;
        default:
            return PREFIX_NOT_QUALIFY;
        }
    }

    return PREFIX_QUALIFY;
}

INT8 Disasm::decodeModRM(Operand *operand, INT8 operand_number)
{
    if (operand == NULL)
        return OPERAND_NOT_EXIST;
    INT8 ret = -1;

    if (operand->type == OPERAND_MEMORY || operand->type == OPERAND_MEMORY_OFFSET || operand->type == OPERAND_XMM_MEMORY){
        currentByte++;
        if (instruction->mod != 3 || operand->type == OPERAND_MEMORY_OFFSET){       // memory
            if (operand->operand_size == SIZE_DWORD){
                if (OperandSizeOverride == PREFIX_OPERAND)
                    operand->operand_size = SIZE_WORD;
            }
            else if (operand->operand_size == SIZE_FWORD){
                if (OperandSizeOverride == PREFIX_OPERAND)
                    operand->operand_size = SIZE_DWORD;
            }
            else if (operand->operand_size == SIZE_QWORD){
                if (OperandSizeOverride == PREFIX_OPERAND)
                    operand->operand_size = SIZE_DWORD;
            }
            else if (operand->operand_size != SIZE_WORD &&
                     operand->operand_size != SIZE_BYTE &&
                     operand->operand_size != 512 &&
                     operand->operand_size != SIZE_FIXED_DWORD &&
                     operand->operand_size != SIZE_FIXED_FWORD &&
                     operand->operand_size != SIZE_FIXED_QWORD &&
                     operand->operand_size != SIZE_DQWORD){
                if (operand->operand_size == 108){
                    if (OperandSizeOverride == PREFIX_OPERAND)
                        operand->operand_size = 94;
                }
                else{
                    if (OperandSizeOverride == PREFIX_OPERAND)
                        operand->operand_size /= 2;
                }
            }

            if (operand->segment != -1){
                if (segmentOverride != -1 && operand->segment == DS)
                    operand->segment = segmentOverride;
            }
            else if (AddressSizeOverride == PREFIX_ADDRESS || instruction->rm != 4){    // don't have sib
                if (AddressSizeOverride == PREFIX_ADDRESS){
                    if (segmentOverride != -1)
                        operand->segment = segmentOverride;
                    else if (instruction->rm == 2 || instruction->rm == 3 || (instruction->mod != 00 &&instruction->rm == 6))
                        operand->segment = SS;
                    else
                        operand->segment = DS;
                }
                else{
                    if (segmentOverride != -1)
                        operand->segment = segmentOverride;
                    else if (instruction->mod != 0 && instruction->rm == 5)
                        operand->segment = SS;
                    else
                        operand->segment = DS;
                }
            }
            else{           // have sib
                operand->scale  = (machineCode[currentByte] >> 6) & 3;      // first 2 buts of SIB
                operand->base = machineCode[currentByte] & 0x07;   // last 3 bits of SIB
                operand->index = (machineCode[currentByte] >> 3) & 7;  // middle 3 bits of SIB

                if (segmentOverride != -1)
                    operand->segment = segmentOverride;
                else if (operand->base == 4 || (instruction->mod != 0x0 && operand->base == 5))
                    operand->segment = SS;
                else
                    operand->segment = DS;
            }

            if (AddressSizeOverride == PREFIX_ADDRESS && operand->addressing_size == SIZE_DWORD)
                operand->addressing_size = SIZE_WORD;

            if (operand->type == OPERAND_MEMORY_OFFSET){
                currentByte--;
                ret = getImmediateOrDisplacement(operand, IS_OFFSET, operand->addressing_size);
                if (ret == NOT_ENOUGH_CODE)
                    return ret;
            }
            else{
                if (operand->operand != -1){          // don't need further decode modr/m or sib
                    currentByte--;                    // don't need next byte to decode
                    if (operand->addressing_size == SIZE_WORD){ // a little adjustment
                        if (operand->operand == AX)
                            operand->operand = ADDRESSING_AX;
                        else if (operand->operand == CX)
                            operand->operand = ADDRESSING_CX;
                        else if (operand->operand == DX)
                            operand->operand = ADDRESSING_DX;
                        else if (operand->operand == BX)
                            operand->operand = ADDRESSING_BX;
                        else if (operand->operand == SP)
                            operand->operand = ADDRESSING_SP;
                        else if (operand->operand == BP)
                            operand->operand = ADDRESSING_BP;
                        else if (operand->operand == SI)
                            operand->operand = ADDRESSING_SI;
                        else if (operand->operand == DI)
                            operand->operand = ADDRESSING_DI;
                    }
                }
                else{
                    if (operand->addressing_size == SIZE_WORD || instruction->rm != 4){   // don't have sib
                        operand->operand = instruction->rm & 7;
                        if (instruction->mod == 0){                       // mod = 0
                            if (operand->addressing_size == SIZE_WORD){
                                if (instruction->rm == 6){
                                    operand->operand = -1;
                                    ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_WORD);
                                }
                            }
                            else{
                                if (instruction->rm == 5){
                                    operand->operand = -1;
                                    ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_DWORD);
                                }
                            }
                            if (ret == NOT_ENOUGH_CODE)
                                return ret;
                        }
                        else if (instruction->mod == 1){            // mod = 1
                            ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_BYTE);
                            if (ret == NOT_ENOUGH_CODE)
                                return ret;
                        }
                        else{               // mod = 2
                            if (operand->addressing_size == SIZE_WORD)
                                ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_WORD);
                            else
                                ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_DWORD);
                            if (ret == NOT_ENOUGH_CODE)
                                return ret;
                        }
                    }
                    else{       // need sib
                        operand->operand = -1;
                        operand->scale  = (machineCode[currentByte] >> 6) & 3;      // first 2 buts of SIB
                        operand->base = machineCode[currentByte] & 7;   // last 3 bits of SIB
                        operand->index = (machineCode[currentByte] >> 3) & 7;  // middle 3 bits of SIB
                        instruction->SIB = machineCode[currentByte++];

                        // displacement
                        if (instruction->mod == 0){
                            if (operand->base == 5){
                                operand->base = -1;
                                ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_DWORD);
                            }
                        }
                        else if (instruction->mod == 1)
                            ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_BYTE);
                        else
                            ret = getImmediateOrDisplacement(operand, IS_DISPLACEMENT, SIZE_DWORD);
                        if (ret == NOT_ENOUGH_CODE)
                            return ret;
                    }
                }
            }
        }
        else{      // mod == 3, register
            if (OperandSizeOverride == PREFIX_OPERAND && operand->operand_size == SIZE_DWORD)
                operand->operand_size = SIZE_WORD;

            operand->operand = instruction->rm & 7;

            if (operand->type == OPERAND_XMM_MEMORY){
                operand->operand_size = SIZE_XMM;
                operand->type = OPERAND_XMM_REGISTER;
            }
            else
                operand->type = OPERAND_REGISTER;
        }
    }
    else if (operand->type == OPERAND_REGISTER || operand->type == OPERAND_XMM_REGISTER){
        if (operand->operand == -1)
            operand->operand = instruction->regop & 7;

        if (operand->type == OPERAND_REGISTER){
            if (operand->operand_size == SIZE_DWORD && OperandSizeOverride == PREFIX_OPERAND)
                operand->operand_size = SIZE_WORD;
            else if (operand->operand_size == SIZE_QWORD && OperandSizeOverride == PREFIX_OPERAND)
                operand->scale = SIZE_DWORD;
        }
    }
    else if (operand->type == OPERAND_IMMEDIATE){
        if (operand->operand != -1)
            return DECODE_SUCCESS;
        else if (operand->operand_size == SIZE_BYTE)
            ret = getImmediateOrDisplacement(operand, IS_IMMEDIATE, operand->operand_size);
        else if (operand->operand_size == SIZE_WORD)
            ret = getImmediateOrDisplacement(operand, IS_IMMEDIATE, operand->operand_size);
        else if (operand->operand_size == SIZE_FIXED_DWORD)
            ret = getImmediateOrDisplacement(operand, IS_IMMEDIATE, operand->operand_size);
        else{
            if (OperandSizeOverride == PREFIX_OPERAND){
                operand->operand_size = SIZE_WORD;
                ret = getImmediateOrDisplacement(operand, IS_IMMEDIATE, operand->operand_size);
            }
            else
                ret = getImmediateOrDisplacement(operand, IS_IMMEDIATE, operand->operand_size);
        }
        if (ret == NOT_ENOUGH_CODE)
            return ret;
    }
    else if (operand->type == OPERAND_SEGMENT){
        if (operand->operand == -1)
            operand->operand = instruction->regop;
    }
    else if (operand->type == OPERAND_FLOW){
        if (operand->operand_size == RELATIVE_ADDRESS_SHORT){
            operand->operand = machineCode[currentByte++];
            instruction->new_eip = address + operand->operand + currentByte;

            if (OperandSizeOverride == PREFIX_OPERAND)
                instruction->new_eip &= 0x0000ffff;
        }
        else if (operand->operand_size == ADDRESS_FAR_ABSOLUTE){
            if (OperandSizeOverride == PREFIX_OPERAND)
                operand->operand_size = ADDRESS_FAR_ABSOLUTE_WORD;
            else
                operand->operand_size = ADDRESS_FAR_ABSOLUTE_DWORD;
            ret = getImmediateOrDisplacement(operand, IS_NEW_EIP, operand->operand_size);
            if (ret == NOT_ENOUGH_CODE)
                return ret;

            ret = getImmediateOrDisplacement(operand, IS_NEW_CS, SIZE_WORD);
            if (ret == NOT_ENOUGH_CODE)
                return ret;
        }
        else if (operand->operand_size == RELATIVE_ADDRESS_FAR){
            if (OperandSizeOverride == PREFIX_OPERAND)
                operand->operand_size = RELATIVE_ADDRESS_FAR_WORD;
            else
                operand->operand_size = RELATIVE_ADDRESS_FAR_DWORD;
            ret = getImmediateOrDisplacement(operand, IS_NEW_EIP, operand->operand_size);
            if (ret == NOT_ENOUGH_CODE)
                return ret;

            instruction->new_eip += address + currentByte;

            if (OperandSizeOverride == PREFIX_OPERAND)
                instruction->new_eip &= 0x0000ffff;
        }
    }
    else if (operand->type == OPERAND_FLOAT){
        if (operand->operand == -1)
            operand->operand = instruction->rm;
    }
    else if (operand->type == OPERAND_CR){
        currentByte++;
        if (operand_number == FIRST_OPERAND)
            instruction->src1->operand = instruction->rm;
        else
            instruction->dest->operand = instruction->rm;
        operand->operand = instruction->regop;
    }
    else if (operand->type == OPERAND_DR){
        currentByte++;
        if (operand_number == FIRST_OPERAND)
            instruction->src1->operand = instruction->rm;
        else
            instruction->dest->operand = instruction->rm;
        operand->operand = instruction->regop;
    }
    return DECODE_SUCCESS;
}

INT8 Disasm::getImmediateOrDisplacement(Operand *operand, INT8 type, INT8 size)
{
    INT32 immediate = 0, s = 0;

    if (size == SIZE_BYTE || size == RELATIVE_ADDRESS_SHORT){
        if (codeSize == currentByte)
            return NOT_ENOUGH_CODE;
        s = 8;
    }
    else if (size == SIZE_WORD || size == ADDRESS_FAR_ABSOLUTE_WORD || size == RELATIVE_ADDRESS_FAR_WORD){
        if (codeSize < currentByte + 2)
            return NOT_ENOUGH_CODE;
        s = 16;
    }
    else if (size == SIZE_DWORD || size == ADDRESS_FAR_ABSOLUTE_DWORD || size == RELATIVE_ADDRESS_FAR_DWORD){
        if (codeSize < currentByte + 4)
            return NOT_ENOUGH_CODE;
        s = 32;
    }

    memcpy(&immediate, &machineCode[currentByte], s / 8);
    currentByte += s / 8;
    
    if (type == IS_IMMEDIATE || type == IS_OFFSET)
        operand->operand = immediate;
    else if (type == IS_DISPLACEMENT){
        operand->displacement = immediate;
        operand->displacement_size = size;
    }
    else if (type == IS_NEW_CS)
        instruction->new_cs = immediate;
    else{
	operand->operand = immediate;
        instruction->new_eip = immediate;
    }

    return ADD_SUCCESS;
}

int Disasm::needToChangeSign(Operand *operand, int size, INT8 type)
{
    if (instruction->s == 0 && operand->type == OPERAND_IMMEDIATE)
        return 0;
    switch(size){
    case 8:
        return 1;
    case 16:
        return 0;
    case 32:
        if ((type == IS_DISPLACEMENT && ((operand->displacement & 0xfffff000) == 0xfffff000)) ||
            (type == IS_IMMEDIATE && ((operand->operand & 0xfffff000) == 0xfffff000)))
            return 1;
        return 0;
    }
    return 0;
}

void Disasm::addRegister(Operand *operand, bool isDefault)
{
    if (isDefault)
        return;

    if (operand->operand_size == SIZE_BYTE)
        strcat(assemblyCode, Register8[operand->operand]);
    else if (operand->operand_size == SIZE_WORD)
        strcat(assemblyCode, Register16[operand->operand]);
    else if (operand->operand_size == SIZE_FIXED_DWORD)
        strcat(assemblyCode, Register32[operand->operand]);
    else
        strcat(assemblyCode, Register32[operand->operand]);
}

void Disasm::addRetCode()
{
    int i = 0;
    for (; i < currentByte; i++){
        strcat(ret_machineCode, int2str(&machineCode[i], sizeof(INT8), 1, 0));
        strcat(ret_machineCode, " ");
    }
    
    INT8 *binary = (INT8*)malloc(currentByte);
    memcpy(binary, machineCode, currentByte);
    instruction->binary = binary;
}

void Disasm::addImmediate(char *str, Operand *operand, INT8 size, bool noRegister, INT8 type, bool fixedSize, bool isAbsolute)
{
    int isExtend = (strcmp(instruction->mnemonic, "or ") == 0 || strcmp(instruction->mnemonic, "and ") == 0 ||
                     strcmp(instruction->mnemonic, "xor ") == 0), s = 0, i = 0;
    if (size == SIZE_BYTE)
        s = 8;
    else if (size == SIZE_WORD || size == ADDRESS_FAR_ABSOLUTE_WORD)
        s = 16;
    else if (size == SIZE_DWORD || size == ADDRESS_FAR_ABSOLUTE_DWORD)
        s = 32;

    INT32 immediate = -1;
    if (type == IS_IMMEDIATE || type == IS_OFFSET)
        immediate = operand->operand;
    else if (type == IS_DISPLACEMENT)
        immediate = operand->displacement;
    else if (type == IS_NEW_EIP)
        immediate = instruction->new_eip;
    else if (type == IS_NEW_CS)
        immediate = instruction->new_cs;

    bool minus = false;
    if ((s == 8 && immediate & 0x00000080) || (s == 16 && immediate & 0x00008000) || (s == 32 && immediate & 0x80000000))
	minus = true;
    
    if (minus){
        if (type == IS_IMMEDIATE){
            if (!isAbsolute && needToChangeSign(operand, s, IS_IMMEDIATE)){
                strcat(str, "-");
                immediate *= -1;
            }
        }
        else{
            if (!noRegister){
                if (needToChangeSign(operand, s, IS_DISPLACEMENT)){
                    strcat(str, " - ");
                    immediate *= -1;
                }
                else{
                    strcat(str, " + ");
                }
            }
        }
        if (isExtend && (type == IS_IMMEDIATE))
            strcat(str, int2str(&immediate, s / 8, fixedSize, 1));
        else
            strcat(str, int2str(&immediate, s / 8, fixedSize, 0));
    }
    else if (immediate == 0){
        if (noRegister){
            if (!fixedSize)
                strcat(str, "0");
            else{
                for (; i < s / 4; i++)
                    strcat(str, "0");
            }
        }
    }
    else{
        if (!noRegister)
            strcat(str, " + ");
        strcat(str, int2str(&immediate, s / 8, fixedSize, 0));
    }
}

void Disasm::copyOperand(Operand *operand, INT8 operand_number)
{
    char num[10];
    static int operand_order = FIRST_OPERAND;
    if (operand_number == FIRST_OPERAND)
        operand_order = FIRST_OPERAND;
    if (operand == NULL || operand->isDefault)
        return;
    if (operand_order != FIRST_OPERAND)
        strcat(assemblyCode, ", ");
    if (!operand->isDefault){
        if (operand->type == OPERAND_REGISTER)
            addRegister(operand, 1);
        operand_order++;
    }

    if (operand->type == OPERAND_MEMORY || operand->type == OPERAND_MEMORY_OFFSET || operand->type == OPERAND_XMM_MEMORY){
        if (operand->operand_size == SIZE_BYTE)
            strcat(assemblyCode, "byte ptr ");
        else if (operand->operand_size == SIZE_WORD)
            strcat(assemblyCode, "word ptr ");
        else if (operand->operand_size == SIZE_DWORD)
            strcat(assemblyCode, "dword ptr ");
        else if (operand->operand_size == SIZE_FIXED_DWORD)
            strcat(assemblyCode, "dword ptr ");
        else if (operand->operand_size == SIZE_FWORD)
            strcat(assemblyCode, "fword ptr ");
        else if (operand->operand_size == SIZE_FIXED_FWORD)
            strcat(assemblyCode, "fword ptr ");
        else if (operand->operand_size == SIZE_QWORD)
            strcat(assemblyCode, "qword ptr ");
        else if (operand->operand_size == SIZE_FIXED_QWORD)
            strcat(assemblyCode, "qword ptr ");
        else if (operand->operand_size == SIZE_TBYTE)
            strcat(assemblyCode, "tbyte ptr ");
        else if (operand->operand_size == SIZE_DQWORD)
            strcat(assemblyCode, "dqword ptr ");
        else{
            sprintf(num, "%d", operand->operand_size);

            strcat(assemblyCode, "<");
            strcat(assemblyCode, num);
            strcat(assemblyCode, "-byte");
            strcat(assemblyCode, "> ptr ");
        }

        strcat(assemblyCode, SegmentRegisters[operand->segment & 7]);
        strcat(assemblyCode, ":[");

        if (operand->type == OPERAND_MEMORY_OFFSET)
            addImmediate(assemblyCode, operand, operand->addressing_size, HAS_NO_REGISTER, IS_OFFSET, IS_NOT_FIXED_SIZE, IS_NOT_ABSOLUTE);
        else{
            if (operand->operand != -1){
                if (operand->addressing_size == SIZE_WORD)
                    strcat(assemblyCode, Register16_ModRM[operand->operand & 0xf]);
                else
                    strcat(assemblyCode, Register32[operand->operand & 0xf]);
            }
            if (operand->base != -1)
                strcat(assemblyCode, Register32[operand->base & 7]);
            if (operand->index != -1 && operand->index != 4){
                if (operand->base != -1)
                    strcat(assemblyCode, " + ");
                strcat(assemblyCode, Register32[operand->index & 7]);
                if (operand->scale != -1 && operand->scale != 0){
                    strcat(assemblyCode, " * ");
                    sprintf(num, "%d", (int)pow(2.0, operand->scale));
                    strcat(assemblyCode, num);
                }
            }
            if (operand->displacement_size != -1){
                int noRegister = 0;
                if (operand->operand == -1 && operand->base == -1 && operand->index == -1 && operand->scale == -1)
                    noRegister = 1;

                addImmediate(assemblyCode, operand, operand->displacement_size, noRegister, IS_DISPLACEMENT, IS_NOT_FIXED_SIZE, IS_NOT_ABSOLUTE);
            }
        }
        strcat(assemblyCode, "]");
    }
    else if (operand->type == OPERAND_REGISTER || operand->type == OPERAND_XMM_REGISTER){
        if (operand->operand == -1)
            operand->operand = instruction->regop & 7;

        if (operand->type == OPERAND_REGISTER)
            addRegister(operand, 0);
        else{
            if (operand->operand_size == SIZE_XMM)
                strcat(assemblyCode, XMMRegister[operand->operand]);
            else
                strcat(assemblyCode, MMRegister[operand->operand]);
        }
    }
    else if (operand->type == OPERAND_IMMEDIATE)
        addImmediate(assemblyCode, operand, operand->operand_size, HAS_NO_REGISTER, IS_IMMEDIATE, IS_NOT_FIXED_SIZE, IS_NOT_ABSOLUTE);
    else if (operand->type == OPERAND_SEGMENT){
        strcat(assemblyCode, SegmentRegisters[operand->operand]);
    }
    else if (operand->type == OPERAND_FLOW){
        char temp_cs[10], temp_eip[10];
        strcpy(temp_cs, "\0");
        strcpy(temp_eip, "\0");
        if (operand->operand_size == RELATIVE_ADDRESS_SHORT){
            addImmediate(temp_eip, operand, SIZE_DWORD, HAS_NO_REGISTER, IS_NEW_EIP, IS_FIXED_SIZE, IS_NOT_ABSOLUTE);
            strcat(assemblyCode, temp_eip);
        }
        else if (operand->operand_size == ADDRESS_FAR_ABSOLUTE_DWORD || operand->operand_size == ADDRESS_FAR_ABSOLUTE_WORD){
            addImmediate(temp_eip, operand, operand->operand_size, HAS_NO_REGISTER, IS_NEW_EIP, IS_FIXED_SIZE, IS_ABSOLUTE);
            addImmediate(temp_cs, operand, SIZE_WORD, HAS_NO_REGISTER, IS_NEW_CS, IS_FIXED_SIZE, IS_ABSOLUTE);

            strcat(assemblyCode, temp_cs);
            strcat(assemblyCode, ":");
            strcat(assemblyCode, temp_eip);
        }
        else if (operand->operand_size == RELATIVE_ADDRESS_FAR_DWORD || operand->operand_size == RELATIVE_ADDRESS_FAR_WORD){
            addImmediate(temp_eip, operand, SIZE_DWORD, HAS_NO_REGISTER, IS_NEW_EIP, IS_FIXED_SIZE, IS_NOT_ABSOLUTE);

            strcat(assemblyCode, temp_eip);
        }
    }
    else if (operand->type == OPERAND_FLOAT){
        strcat(assemblyCode, FloatPointRegister[operand->operand & 7]);
    }
    else if (operand->type == OPERAND_CR){
        strcat(assemblyCode, Register32[instruction->rm & 7]);
        strcat(assemblyCode, ", ");
        strcat(assemblyCode, ControlRegister[operand->operand & 7]);
    }
    else if (operand->type == OPERAND_DR){
        strcat(assemblyCode, Register32[instruction->rm & 7]);
        strcat(assemblyCode, ", ");
        strcat(assemblyCode, DebugRegister[operand->operand & 7]);
    }
}

void Disasm::copyPrefix(bool onlyPrefix){
    if (onlyPrefix){
        memcpy(instruction, &specialInstruction[SPECIAL_PREFIX], sizeof(INSTRUCTION));
        strcat(assemblyCode, "prefix ");

        if (segmentOverride != -1){
            strcat(assemblyCode, SegmentRegisters[segmentOverride & 7]);
            strcat(assemblyCode, ":");
        }
        else if (OperandSizeOverride == PREFIX_OPERAND)
            strcat(assemblyCode, "datasize:");
        else if (AddressSizeOverride == PREFIX_ADDRESS)
            strcat(assemblyCode, "addrsize:");
        else if (lockAndRepeat != -1){
            if ((unsigned char)lockAndRepeat == PREFIX_LOCK)
                lockAndRepeat = LOCK;
            else if ((unsigned char)lockAndRepeat == PREFIX_REPN)
                lockAndRepeat = REPNE;
            else
                lockAndRepeat = REP;
            strcat(assemblyCode, RepeatPrefixes[lockAndRepeat & 7]);
            strcat(assemblyCode, ":");
        }
    }
    else{
        if (lockAndRepeat != -1){
            strcat(assemblyCode, RepeatPrefixes[lockAndRepeat & 7]);
            strcat(assemblyCode, " ");
        }
    }
}

void Disasm::copyAssembleAndMachineCode(bool onlyPrefix)
{
    copyPrefix(onlyPrefix);
    strcat(assemblyCode, instruction->mnemonic);
    copyOperand(instruction->dest, FIRST_OPERAND);
    copyOperand(instruction->src1, SECOND_OPERAND);
    copyOperand(instruction->src2, THIRD_OPERAND);
    copyOperand(instruction->src3, FOURTH_OPERAND);
    addRetCode();
}

void Disasm::copyInstruction(INSTRUCTION *instr)
{
    instruction->assembly = assemblyCode;
    instruction->ret_machineCode = ret_machineCode;

    memcpy(instr, instruction, sizeof(INSTRUCTION));
    instr->lockAndRepeat = lockAndRepeat;
    instr->segmentOverride = segmentOverride;
    instr->OperandSizeOverride = OperandSizeOverride;
    instr->AddressSizeOverride = AddressSizeOverride;

    instr->address = address;
    if (instr->new_eip != -1)
        instr->final_address = instr->new_eip;
    else
        instr->final_address = instr->address + currentByte;

    instr->size = currentByte;
    free(instruction);
}

void Disasm::setHandlerIndex(){
    if (!instruction->dest){
	instruction->handlerIndex = HANDLER_32;
	return;
    }

    switch(instruction->dest->operand_size){
    case SIZE_BYTE: case RELATIVE_ADDRESS_SHORT:
	instruction->handlerIndex = HANDLER_8;
	break;
    case SIZE_WORD: case ADDRESS_FAR_ABSOLUTE_WORD: case RELATIVE_ADDRESS_FAR_WORD:
	instruction->handlerIndex = HANDLER_16;
	break;
    default:
	instruction->handlerIndex = HANDLER_32;
	break;
    }
}

INT32 Disasm::disassembler(INT8 MACHINECODE[], int CODESIZE, INT32 addr, INT32 baseAddress, INSTRUCTION *instr)
{
    if (CODESIZE == 0)
        return NOT_ENOUGH_CODE;

    instruction = (INSTRUCTION *)malloc(sizeof(INSTRUCTION));
    assemblyCode = (char *)malloc(100);
    ret_machineCode = (char *)malloc(100);
    strcpy(assemblyCode, "\0");
    strcpy(ret_machineCode, "\0");
    machineCode = MACHINECODE;
    currentByte = 0;
    int hasPrefix = 0;
    codeSize = CODESIZE;
    INT8 ret = -1;
    address = addr;
    base = baseAddress;
    lockAndRepeat = -1;
    segmentOverride = -1;
    OperandSizeOverride = -1;
    AddressSizeOverride = -1;

    // prefix section
    while (currentByte < (int)MAX_INSTRUCTION_SIZE){
        ret = decodePrefix();
        if (ret == COLLIDED_PREFIX){             // collided prefix
            hasPrefix = 1;
            break;
        }
        else if (ret == NOT_PREFIX)          // not prefix
            break;
        else                        // continue decoding
            hasPrefix++;
    }
    if (codeSize == currentByte || ret == COLLIDED_PREFIX){             // only one prefix or collided prefix
        copyAssembleAndMachineCode(ONLY_PREFIX);
        copyInstruction(instr);
        return hasPrefix;
    }

    if (codeSize == currentByte)
        return NOT_ENOUGH_CODE;

    // opcode section
    if ((unsigned char)machineCode[currentByte] == 0x0f){
        if (codeSize == currentByte)
            return NOT_ENOUGH_CODE;
        currentByte++;
        memcpy(instruction, &getTwoByteOpcode[(unsigned char)machineCode[currentByte++]], sizeof(INSTRUCTION));
        instruction->opcode = 0x0f00 + (unsigned char)machineCode[currentByte - 1];
    }
    else{
        memcpy(instruction, &getOneByteOpcode[(unsigned char)machineCode[currentByte++]], sizeof(INSTRUCTION));
        instruction->opcode = (unsigned char)machineCode[currentByte - 1];
    }

    if (instruction->type == NEED_FURTHER_PARSED){
        if (codeSize == currentByte)
            return NOT_ENOUGH_CODE;
        INT8 auxiliary = (machineCode[currentByte] >> 3) & 7;
        memcpy(instruction, &getOneByteWithAuxiliaryOpcode[instruction->dest->operand][auxiliary & 7], sizeof(INSTRUCTION));
        instruction->opcode = (unsigned char)machineCode[currentByte - 1];
    }

    if (instruction->opcode >= 0xd8 && instruction->opcode <= 0xdf)
        preprocessingFloatPointInstruction();
    if (instruction->type == SPECIAL_MNEMONIC){
        if (specialMnemonicProcess() == NOT_ENOUGH_CODE)
            return NOT_ENOUGH_CODE;
    }

    if (validatePrefix() == PREFIX_NOT_QUALIFY){
        copyAssembleAndMachineCode(ONLY_PREFIX);
        copyInstruction(instr);
        return hasPrefix;
    }

    Operand *temp;
    if (instruction->dest){
        temp = instruction->dest;
        instruction->dest = (Operand*)malloc(sizeof(Operand));
        memcpy(instruction->dest, temp, sizeof(Operand));
    }
    if (instruction->src1){
        temp = instruction->src1;
        instruction->src1 = (Operand*)malloc(sizeof(Operand));
        memcpy(instruction->src1, temp, sizeof(Operand));
    }
    if (instruction->src2){
        temp = instruction->src2;
        instruction->src2 = (Operand*)malloc(sizeof(Operand));
        memcpy(instruction->src2, temp, sizeof(Operand));
    }
    if (instruction->src3){
        temp = instruction->src3;
        instruction->src3 = (Operand*)malloc(sizeof(Operand));
        memcpy(instruction->src3, temp, sizeof(Operand));
    }

    // modr/m, sib, immediate section, if exists
    if (instruction->ModRM && instruction->type != FLOAT_INSTRUCTION){
        if (codeSize == currentByte)
            return NOT_ENOUGH_CODE;
        instruction->mod = (machineCode[currentByte] >> 6) & 3;
        instruction->rm = (machineCode[currentByte]) & 7;
        instruction->regop = (machineCode[currentByte] >> 3) & 7;
        instruction->ModRM = machineCode[currentByte];
    }

    // decode 3 operands, if exists
    if (decodeModRM(instruction->dest, FIRST_OPERAND) == NOT_ENOUGH_CODE)
        return NOT_ENOUGH_CODE;
    if (decodeModRM(instruction->src1, SECOND_OPERAND) == NOT_ENOUGH_CODE)
        return NOT_ENOUGH_CODE;
    if (decodeModRM(instruction->src2, THIRD_OPERAND) == NOT_ENOUGH_CODE)
        return NOT_ENOUGH_CODE;
    if (decodeModRM(instruction->src3, FOURTH_OPERAND) == NOT_ENOUGH_CODE)
        return NOT_ENOUGH_CODE;

    setHandlerIndex();

    copyAssembleAndMachineCode(NOT_ONLY_PREFIX);
    copyInstruction(instr);
    return currentByte;
}

char *int2str(void *num, unsigned long size, int fixedSize, int extend){
    int i = 0, j = 0;
    char result_reverse[10];
    unsigned long temp = *((unsigned long*)num);
    char *result = (char *)malloc(10);
    strcpy(result, "\0");
    
    for (; i < int(size * 2); i++){
	if ((temp % 16) >= 10)
	    result_reverse[size * 2 - i - 1] = (temp % 16) - 10 + 'A';
	else
	    result_reverse[size * 2 - i - 1] = (temp % 16) + '0';
	temp /= 16;
    }
    result_reverse[i] = '\0';
    while(1){
	if (result_reverse[0] != '0')
	    break;
	for (j = 0; j < (int)strlen(result_reverse); j++)
	    result_reverse[j] = result_reverse[j + 1];
    }

    if (fixedSize){
	memset(result, '0', size * 2 - strlen(result_reverse));
	result[size * 2 - strlen(result_reverse)] = '\0';
	strcat(result, result_reverse);
    }
    else{
	if (!extend && result_reverse[0] > '9')
	    strcpy(result, "0");
	strcat(result, result_reverse);
    }
    if (extend){
	memset(result, 'F', 8 - strlen(result_reverse));
	result[8 - strlen(result_reverse)] = '\0';
	strcat(result, result_reverse);
    }
    
    return result;
}

