#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_XOPEN
#include <time.h>
#include "Scheduler.h"

void Sort(struct event *, int);

int main()
{
	time_t start;
	int option;
	int numevents = 1;

	struct event *events;
	events = malloc(sizeof(struct event));

	LoadFile();
	
	while((option = GetOption()))
	{
		
		switch(option)
		{
			case 1:
				if (numevents == 1)
					;
				else
					events = realloc(events, sizeof(struct event) * (numevents));

				events[numevents-1] = Option1(events[numevents-1]);

				Sort(events, numevents);

				numevents++;
				break;

			case 2:
				Option2(events, numevents - 1);
				break;

			case 3:
				Option3(events, numevents - 1);

			case 4:
				Option4(events, &numevents);
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

	for (i = 0; i < length - 1; ++i)
	{
		for (j = 0; j < length - 1 - i; ++j)
		{
			if (eve[j].start_time > eve[j+1].start_time)
			{
				printf("Test!\n");
				tempEvent = eve[j];
				eve[j] = eve[j+1];
				eve[j+1] = tempEvent;
			}
		}
	}
}