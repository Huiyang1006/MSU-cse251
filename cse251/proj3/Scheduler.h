#ifndef SCHEDULER_H
#define SCHEDULER_H
#define FileName "schedule.dat"
#include <time.h>

void Menu();
int GetOption();

void InputEvent(char*, int);
time_t InputDate(char*);
time_t InputTime(char*, time_t);
void OutputTime(struct tm);

struct event Option1(struct event);
void Option2(struct event *, int);
void Option3(struct event *, int);
void Option4(struct event *, int *);

void OutputFull(struct event);


struct event
{
  char name[50];
  time_t date;

  time_t start_time;
  time_t end_time;

  //int test;
};


#endif
