/*
 * =====================================================================================
 *
 *       Filename:  SCFunction.h
 *
 *    Description:  Definition of class SCFunction and SCFunctionList.
 *
 *        Version:  1.0
 *        Created:  2014/03/20 15时37分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __Scarab__SCFunction__
#define __Scarab__SCFunction__

#include "type.h"
#include <string>

class SCInstr;
class SCBlock;


class SCFunction
{
    public:
        SCFunction();
        ~SCFunction();
        
        void setFlag(UINT32 flag);
        bool hasFlag(UINT32 flag);
        void removeFlag(UINT32 flag);

        void setFirstBlock(SCBlock* bbl);
        void setLastBlock(SCBlock* bbl);
        void setName(std::string& name);
        void setEntryBlock(SCBlock* bbl);
        void setExitBlock(SCBlock* bbl);

        SCBlock* getFirstBlock();
        SCBlock* getLastBlock();
        std::string getName();
        SCBlock* getEntryBlock();
        SCBlock* getExitBlock();
        
        // methods
    


    private:
        UINT32 f_flags;                // flags
        SCBlock *f_first;         // first basic block in this function 和f_entry不一样 n
        SCBlock *f_last;          // last basic block in this function n
        UINT32 f_id;                   // unique identifier for the function y
        std::string f_name;                  // function name n
        SCBlock *f_entry;                // entry block y
        SCBlock *f_exit;                 // exit block y
};


class SCFunctionList {
    public:
        SCFunctionList();
        static SCFunctionList* sharedFunctionList();
        void createFunctionList(BlockListT bbls);
        void markFunctions();
        void deleteFunctions(SCFunction* first, SCFunction* last);

    private:
        FunListT p_funs;
};

#endif
