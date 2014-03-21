/*
 * =====================================================================================
 *
 *       Filename:  SCReport.h
 *
 *    Description:  Definition of SCReport class.
 *
 *        Version:  1.0
 *        Created:  2014/03/21 15时30分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>

class SCReport {
    public:
        static SCReport* sharedSCReport();
        static void Report(...);
    
};

