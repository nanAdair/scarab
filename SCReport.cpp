/*
 * =====================================================================================
 *
 *       Filename:  SCReport.cpp
 *
 *    Description:  Implementation of class SCReport.
 *
 *        Version:  1.0
 *        Created:  2014/03/21 15时33分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "SCReport.h"


static SCReport* _sharedSCReport = NULL;

SCReport* SCReport::sharedSCReport() {
    if(!_sharedSCReport) {
        _sharedSCReport = new SCReport();
    }
    return _sharedSCReport;
}

void SCReport::Report(...) {
    // TODO: implement it.
    /*printf(__VA_ARGS__);*/
}
