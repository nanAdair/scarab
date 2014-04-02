#ifndef DISASM_H
#define DISASM_H

#include "dis.h"

class Disasm
{
public:
    Disasm();
    INT32 disassembler(INT8 MACHINECODE[], int CODESIZE, INT32 addr, INT32 baseAddress, INSTRUCTION *instr);
private:
    int currentByte, codeSize;
    INSTRUCTION *instruction;
    INT8 *machineCode;
    INT8 lockAndRepeat;
    INT8 segmentOverride;
    INT8 OperandSizeOverride;
    INT8 AddressSizeOverride;
    INT32 address, base;
    char *assemblyCode, *ret_machineCode;

    INT8 decodePrefix();
    void copyInstruction(INSTRUCTION *instr);
    INT8 decodeModRM(Operand *operand, INT8 operand_number);
    int needToChangeSign(Operand *operand, int size, INT8 type);
    void preprocessingFloatPointInstruction();
    void addRegister(Operand *operand, bool isDefault);
    INT8 specialMnemonicProcess();
    void allocateOperand(Operand *operand);
    void copyAssembleAndMachineCode(bool onlyPrefix);
    void copyPrefix(bool onlyPrefix);
    void copyOperand(Operand *operand, INT8 operand_number);
    INT8 getImmediateOrDisplacement(Operand *operand, INT8 type, INT8 size);
    void addImmediate(char *str,Operand *operand, INT8 size, bool noRegister, INT8 type, bool fixedSize, bool isAbsolute);
    void addRetCode();
    INT8 validatePrefix();
};

char *int2str(void *num, unsigned long size, int fixedSize, int extend);

#endif // DISASM_H
