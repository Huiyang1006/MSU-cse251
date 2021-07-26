#include <stdio.h>
#include <string.h>
#include "Scheduler.h"

void LoadFile(char *ffile)
{
    int numEvents;
	char buffer[120];
    int i = 0;

    printf("Loaded file: %s\n", ffile);

	FILE *file = fopen(ffile, "r");
    if(file == NULL)
    {	
    	printf("Failed.\n");
        return;
    }

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "%d", &numEvents);
    printf("NumEvents: %d\n", numEvents);
    //printf("Line: %d\n", i++);

    while(fgets(buffer, sizeof(buffer), file))
    {
        /* Remove the newline at the end of the buffer */
        if(strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n')
         buffer[strlen(buffer) - 1] = '\0';
    	printf("%s\n", buffer);
        //printf("Line: %d\n", i++);
	}

	fclose(file);
}

void SaveFile(char *ffile, struct event *eve, int numEvents)
{
    FILE *file = fopen(ffile, "w");
    if(file == NULL)
    {   
        printf("Failed.\n");
        return;
    }

    fprintf(file, "%d\n", numEvents + 1);

	for (int i = 0; i < numEvents + 1; ++i)
	{
		fprintf(file, "%s\n", eve[i].name);
		fprintf(file, "%s", ctime(&eve[i].start_time));
		fprintf(file, "%s", ctime(&eve[i].end_time));
		//eve[i].start_time
	}

    fclose(file);
}