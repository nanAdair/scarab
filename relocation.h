/*
 * =====================================================================================
 *
 *       Filename:  relocation.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2014 04:40:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef RELOCATION_H
#define RELOCATION_H

#include <vector>
#include "type.h"

class Relocation
{
    private:
        UINT32 rel_offset;
        UINT8  rel_type;
        UINT32 rel_link;
        UINT32 rel_info;
        UINT32 rel_sym_index;
        UINT32 rel_value;
        UINT32 rel_addend;
};

class Relocation_List
{
    public:
        void
        add_item(Relocation*);
    
    private:
        vector<Relocation*> rel_list;
};

#endif
