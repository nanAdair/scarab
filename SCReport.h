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

#ifndef __Scarab__SCReport__
#define __Scarab__SCReport__


#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>


/*
 *  Level definitions for issuing reports.
 */
#define RP_NONE      0	// nothing but errors
#define RP_MAJOR     1	// major milestones
#define RP_MINOR     2	// minor milestones
#define RP_DETAIL    3	// additional details at milestones
#define RP_SMLOOP    4	// small-loop reports (typically < 100 iterations)
#define RP_SMDETAIL  5	// small-loop additional details
#define RP_LGLOOP    6	// large-loop reports (voluminous)
#define RP_LGDETAIL  7	// large-loop additional details
#define RP_TRIVIAL   8	// the most trivial details
#define RP_DEBUG     9	// all debugging messages

/*
 *  report(level,fmt,args) -- issue report message of the given level.
 *
 *  Should be called only after level has been validated by the REPORT macro.
 */
void Report(int level, char *fmt, ...);



#endif
