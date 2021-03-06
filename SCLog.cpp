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
#include "SCLog.h"


/*
 *  timestamp() -- return a timestamp string in a static buffer.
 *
 *  Returns an empty string if timestamps are not wanted.
 */
static const char *getTimestamp() {
    static char buf[20];

    if (1) {    // TODO: option for showing timestamp or not
        // sprintf(buf, "%5.2f ", clock() / (double) CLOCKS_PER_SEC);
        // return buf;
        time_t pt=time(NULL);
        tm* local = localtime(&pt);
        sprintf(buf, "%d:%d:%d", local->tm_hour, local->tm_min, local->tm_sec);
        return buf;
    } 
    else {
        return "";
    }
}


void SCLog(int level, const char *fmt, ...) {
    // print the report message
    va_list args;
    va_start(args, fmt);

    if (level != RL_ZERO)
    {
        fprintf(stdout, "[%s]", getTimestamp());
        for(int i=1; i<level; ++i)
            fprintf(stdout, "\t");
        fprintf(stdout, "[%d] ", level);
    }
    
    vfprintf(stdout, fmt, args);
    fprintf(stdout, "\n");
    va_end(args);
}
