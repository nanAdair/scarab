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

#ifndef __Scarab__SCLog__
#define __Scarab__SCLog__


#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>


#define RL_ONE		1
#define RL_TWO		2
#define RL_THREE	3
#define RL_FOUR		4
#define RL_FIVE		5

/*
 *  report(level,fmt,args) -- issue report message of the given level.
 *
 *  Should be called only after level has been validated by the REPORT macro.
 */
void SCLog(int level, const char *fmt, ...);



#endif
