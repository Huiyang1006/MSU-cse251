#ifndef MENU_H
#define MENU_H

#include "Scheduler.h"

void Menu();
int GetOption();

struct event Option1(struct event);
void Option2(struct event *, int);
void Option3(struct event *, int);
void Option4(struct event *, int *);

#endif
