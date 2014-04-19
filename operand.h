#ifndef __Scarab__Operand__H__
#define __Scarab__Operand__H__

#include "type.h"
#include "dis-table.h"

class Operand{

	public:
		Operand();
		Operand(INT8, INT32, OPERAND_SIZE, OPERAND_TYPE, INT8, INT8, 
			INT8, INT32, int, OPERAND_SIZE, bool);
		Operand(INT8, INT32, OPERAND_SIZE, OPERAND_TYPE, INT8, INT8, 
			INT8, INT32, int, OPERAND_SIZE, int);

		Operand(int, int, OPERAND_SIZE, OPERAND_TYPE, int, int, int, 
			int, int, OPERAND_SIZE, int);
		Operand(int, HAVE_AUXILIARY_CODE, OPERAND_SIZE, OPERAND_TYPE, int, int, int, 
			int, int, OPERAND_SIZE, int);

		INT32 getOperand();

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
};

#endif