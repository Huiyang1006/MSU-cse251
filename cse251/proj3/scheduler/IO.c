#include <stdio.h>
#include <string.h>
#define __USE_XOPEN
#include <time.h>
#include "Scheduler.h"

time_t InputDate(char *prompt)
{
    char buffer[100];
    char *result;
    struct tm date;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while(result == NULL);

    /* Convert to time_t format */
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    return mktime(&date);
}

time_t InputTime(char *prompt, time_t date)
{
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        result = strptime(buffer, "%I:%M%p", &time);

    } while(result == NULL);

    return mktime(&time);
}

void InputEvent(char *str, int max)
{
    char buffer[100];
    
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);
    
    /* Remove any \n we may have input */
    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';
        
    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max-1] = '\0';
}

void OutputTime(struct tm ttime)
{
    int hour12;
    int is_afternoon;
    char afternoon_flag[][20] = {"AM", "PM"};

    hour12 = ttime.tm_hour%12;
    is_afternoon = ttime.tm_hour/12;
    printf("%d:%02d%s\t", hour12, ttime.tm_min, afternoon_flag[is_afternoon]);   
}

void OutputFull(struct event eve)
{
    struct tm ttime;
    struct tm ttime1;
    struct tm ttime2;

    ttime = *localtime(&eve.date);
    ttime1 = *localtime(&eve.start_time);
    ttime2 = *localtime(&eve.end_time);
    printf("  %d/%d/%d\t", ttime.tm_mon+1, ttime.tm_mday, ttime.tm_year + 1900);
    OutputTime(ttime1);
    OutputTime(ttime2);
    printf("%s\n", eve.name);
}