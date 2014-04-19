
#include "operand.h"

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
