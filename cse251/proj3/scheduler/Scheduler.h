#ifndef SCHEDULER_H
#define SCHEDULER_H
#define FileName "schedule.dat"
#include <time.h>

void Menu();
int GetOption();

struct event
{
  char name[50];
  time_t date;

  time_t start_time;
  time_t end_time;

  //int test;
};

void SaveNum(char *, int);
void SaveFile(char *, struct event *, int);
void LoadFile(char *);

#endif
