/*
 * =====================================================================================
 *
 *       Filename:  version.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/21/2014 06:39:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef VERSION_H
#define VERSION_H
#include <vector>
#include <elf.h>
#include <iostream>
#include <string.h>
#include "section.h"
#include "type.h"

class SCSection;
class SCSectionList;

class SCVersionDef 
{
    public:
        friend class SCVersionList;
        SCVersionDef() {}
        
        void
        init(int , SCSection *, SCSection *);
        
        int
        getNextOffset()
        { return this->ver_content->vd_next; }
        
        UINT8 *
        getName()
        { return this->ver_name; }
        
    private:
        Elf32_Verdef *ver_content;
        Elf32_Verdaux *ver_aux;
        UINT8 *ver_name;
};

class SCVersionList
{
    public:
        void
        init(SCSectionList*);
        
        /* FIXME How to release the space */
        ~SCVersionList()
        {
            vector<SCVersionDef*>::iterator it;
            for (it = ver_list.begin(); it != ver_list.end(); ++it)
                delete *it;
        }
        
        UINT8 *
        getVersionName(UINT16 ver_number)
        {
            vector<SCVersionDef*>::iterator it;
            for (it = ver_list.begin(); it != ver_list.end(); ++it) {
                if ((*it)->ver_content->vd_ndx == ver_number)
                    return (*it)->getName();
            }
        }
        
    private:
        vector<SCVersionDef*> ver_list;
};
#endif
