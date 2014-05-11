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

#define RL_ZERO		0
#define RL_ONE		1
#define RL_TWO		2
#define RL_THREE	3
#define RL_FOUR		4
#define RL_FIVE		5

void SCLog(int level, const char *fmt, ...);

// void SCLogSer(int part, const char *fmt, ...);


#endif
