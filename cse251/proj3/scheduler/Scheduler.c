#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_XOPEN
#include <time.h>
#include "Scheduler.h"
#include "Menu.h"

void Sort(struct event *, int);

int main()
{
	time_t start;
	int option;
	int numevents = 0;

	struct event *events;
	events = malloc(sizeof(struct event));

	LoadFile("Schedule.dat");
	
	while((option = GetOption()))
	{
		
		switch(option)
		{
			case 1:
				if (numevents == 0)
					;
				else
					events = realloc(events, sizeof(struct event) * (numevents + 1));

				events[numevents] = Option1(events[numevents]);

				Sort(events, numevents);

				numevents++;

				SaveFile("Schedule.dat", events, numevents-1);
				break;

			case 2:
				Option2(events, numevents);
				break;

			case 3:
				Option3(events, numevents);
				break;

			case 4:
				Option4(events, &numevents);
				SaveFile("Schedule.dat", events, numevents-1);
		}
	}
	
	/* Free the memory */
	free(events);

	return 0;
}

void Sort(struct event *eve, int length)
{
	int i, j;
	struct event tempEvent;

	for (i = 0; i < length; ++i)
	{
		for (j = 0; j < length - i; ++j)
		{
			if (eve[j].start_time > eve[j+1].start_time)
			{
				//printf("Test!\n");
				tempEvent = eve[j];
				eve[j] = eve[j+1];
				eve[j+1] = tempEvent;
			}
		}
	}
}