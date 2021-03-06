
#include "operand.h"
#include <cstring>

Operand::Operand(): segment(0),operand(0),
	operand_size(0),type(0),scale(0),
	index(0),base(0),displacement(0),
	displacement_size(0),addressing_size(0),
	isDefault(false)
{ }

Operand::Operand(INT8 seg, INT32 oper, OPERAND_SIZE oper_size,
	OPERAND_TYPE type, INT8 scale, INT8 idx, INT8 base,
	INT32 disp, int disp_size, OPERAND_SIZE addr_size,
	bool isDef):
		segment(seg), operand(oper),
		operand_size(oper_size), type(type),
		scale(scale), index(idx), base(base),
		displacement(disp), displacement_size(disp_size),
		addressing_size(addr_size), isDefault(isDef)
{ }

Operand::Operand(INT8 seg, INT32 oper, OPERAND_SIZE oper_size,
	OPERAND_TYPE type, INT8 scale, INT8 idx, INT8 base,
	INT32 disp, int disp_size, OPERAND_SIZE addr_size,
	int isDef):
		segment(seg), operand(oper),
		operand_size(oper_size), type(type),
		scale(scale), index(idx), base(base),
		displacement(disp), displacement_size(disp_size),
		addressing_size(addr_size), isDefault(isDef)
{ }

Operand::Operand(int seg, int oper, OPERAND_SIZE oper_size,
	OPERAND_TYPE type, int scale, int idx, int base,
	int disp, int disp_size, OPERAND_SIZE addr_size,
	int isDef)
{ 
	this->segment = (INT8)seg;
	this->operand = (INT32)oper;
	this->operand_size = oper_size;
	this->type = type;
	this->scale = (INT8)scale;
	this->index = (INT8)idx;
	this->base = (INT8)base;
	this->displacement = (INT32)disp;
	this->displacement_size = disp_size;
	this->addressing_size = addr_size;
	this->isDefault = isDef;
}

Operand::Operand(int seg, HAVE_AUXILIARY_CODE oper, OPERAND_SIZE oper_size,
	OPERAND_TYPE type, int scale, int idx, int base,
	int disp, int disp_size, OPERAND_SIZE addr_size,
	int isDef)
{ 
	this->segment = (INT8)seg;
	this->operand = (INT32)oper;
	this->operand_size = oper_size;
	this->type = type;
	this->scale = (INT8)scale;
	this->index = (INT8)idx;
	this->base = (INT8)base;
	this->displacement = (INT32)disp;
	this->displacement_size = disp_size;
	this->addressing_size = addr_size;
	this->isDefault = isDef;
}

INT32 Operand::getOperand() {
	return this->operand;
}

void Operand::serialize(const char* prefix) {
	SCLog(RL_ZERO, "%s====Operand(%x)====", prefix, this);
    
    SCLog(RL_ZERO, "%ssegment: 0x%x", prefix, segment);
    SCLog(RL_ZERO, "%soperand: 0x%x", prefix, operand);
    SCLog(RL_ZERO, "%soperand_size: %d", prefix, operand_size);
    SCLog(RL_ZERO, "%sdisplacement: 0x%x", prefix, displacement);
    SCLog(RL_ZERO, "%sdisplacement_size: %d", prefix, displacement_size);

    char tp[30] = {0};
    if (type == OPERAND_IMMEDIATE)
    	strcpy(tp, "OPERAND_IMMEDIATE");
    else if (type == OPERAND_MEMORY)
		strcpy(tp, "OPERAND_MEMORY");
	else if (type == OPERAND_REGISTER)
		strcpy(tp, "OPERAND_REGISTER");
	else if (type == OPERAND_SEGMENT)
		strcpy(tp, "OPERAND_SEGMENT");
	else if (type == OPERAND_FLOAT)
		strcpy(tp, "OPERAND_FLOAT");
	else if (type == OPERAND_FLOW)
		strcpy(tp, "OPERAND_FLOW");
	

    SCLog(RL_ZERO, "%stype: %d(%s)", prefix, type, tp);

    SCLog(RL_ZERO, "%s====END=Operand(%x)====", prefix, this);
}
