/*
 * =====================================================================================
 *
 *       Filename:  version.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/21/2014 06:41:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "version.h"

class SCSection;
class SCSectionList;

/* store only one version to the field
 * for we take the first version to be default.*/
void SCVersionDef::init(int offset, SCSection *dynstr, SCSection *vd)
{
    this->ver_content = (Elf32_Verdef *)(vd->getSecData() + offset);
    int offset_aux;
    offset_aux = this->ver_content->vd_aux;
    this->ver_aux = (Elf32_Verdaux *)(vd->getSecData() + offset + offset_aux);
    this->ver_name = dynstr->getSecData() + this->ver_aux->vda_name;
}

void SCVersionList::init(SCSectionList *sl)
{
    SCSection *dynstr, *vd, *dynamic;
    int offset, numberOfVersions;
    dynstr = sl->getSectionByName(".dynstr");
    vd = sl->getSectionByName(".gnu.version_d");
    dynamic = sl->getSectionByName(".dynamic");
    offset = 0;
    numberOfVersions = dynamic->getDynamicAttributeData(DT_VERDEFNUM);
    
    for (int i = 0; i < numberOfVersions; i++) {
        SCVersionDef *version = new SCVersionDef();
        version->init(offset, dynstr, vd);
        offset += (int)version->getNextOffset();
        this->ver_list.push_back(version);
    }
}
