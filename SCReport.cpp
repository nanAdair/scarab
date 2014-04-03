/*
 * =====================================================================================
 *
 *       Filename:  SCReport.cpp
 *
 *    Description:  Print functions.
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
#include "SCReport.h"


/*
 *  timestamp() -- return a timestamp string in a static buffer.
 *
 *  Returns an empty string if timestamps are not wanted.
 */
static char *getTimestamp() {
    static char buf[20];

    if (1) {    // TODO: option for showing timestamp or not
        sprintf(buf, "%5.2f ", clock() / (double) CLOCKS_PER_SEC);
        return buf;
    } 
    else {
        return "";
    }
}



/*
 *  report(level,fmt,args) -- issue report message of the given level.
 *
 *  Should be called only after level has been validated by the REPORT macro.
 */
void Report(int level, char *fmt, ...) {


    // print the report message
    char *space = "            ";
    va_list args;
    va_start(args, fmt);
    fprintf(stdout, "%s%d  ", getTimestamp(), level);
    if (level > RP_DETAIL) {
        fprintf(stdout, space + 18 - 2 * level);	// indent
    }
    vfprintf(stdout, fmt, args);
    fprintf(stdout, "\n");
    va_end(args);
}

