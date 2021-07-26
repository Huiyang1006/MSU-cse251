#ifndef IO_H
#define IO_H

#include "Scheduler.h"

void InputEvent(char*, int);
time_t InputDate(char*);
time_t InputTime(char*, time_t);
void OutputTime(struct tm);
void OutputFull(struct event);

#endif