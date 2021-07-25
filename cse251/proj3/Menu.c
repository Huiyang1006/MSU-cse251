#include <stdio.h>
#include <string.h>
#include "Scheduler.h"
#include <stdbool.h>

void Menu()
{
	printf(
		"1 - Insert a new event\n"
		"2 - Display all events\n"
		"3 - Now?\n"
		"4 - Delete expired\n"
		"0 - Exit\n");
}

int GetOption()
{
	char buffer[100];
	int option = -1;

	Menu();

	printf("Please select an option: ");
	scanf("%d", &option);
	fflush(stdin);

	if (option<=4 && option>=0)
		return option;
	else
	{
		printf("Error input.\n");
		return 0;
	}
}

struct event Option1(struct event eve)
{
	printf("What is the event: ");
	InputEvent(eve.name, sizeof(eve.name));
	
	//printf("Event date: ");
	eve.date = InputDate("Event date: ");

	//printf("Start time: ");
	eve.start_time = InputTime("Start time: ", eve.date);

	//printf("End time: ");
	eve.end_time = InputTime("End time: ", eve.date);

	//eve.test = 0;

	return eve;
	//test();
}

void Option2(struct event *eve, int length)
{
	struct tm ttime;
	struct tm ttime1;
	struct tm ttime2;

	for (int i = 0; i < length; ++i)
		OutputFull(eve[i]);
}

void Option3(struct event *eve, int length)
{
	time_t t;
	int i;
	bool flag = false;

	struct tm ttime;
	struct tm ttime1;
	struct tm ttime2;

	t = time(NULL);
	//printf("The date/time is %s\n", ctime(&t));

	printf("Currently active events: \n");
	for (i = 0; i < length; ++i)
	{
		if (t>eve[i].start_time && t<eve[i].end_time)
		{
			OutputFull(eve[i]);
			flag = 1;
		}
	}

	if (!flag)
	{
		printf("None\n");
	}
}

void Option4(struct event *eve, int *length)
{
	time_t t;
	int i, j;

	t = time(NULL);

	printf("Deleting: \n");
	for (i = 0; i < *length-1; ++i)
	{
		if (t>eve[i].end_time)
		{
			OutputFull(eve[i]);
			for (j = i; j < *length-1; ++j)
				eve[j] = eve[j+1];
			*length = *length - 1;
			i--;
		}
	}
}