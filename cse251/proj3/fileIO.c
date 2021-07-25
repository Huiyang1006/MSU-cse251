#include "Scheduler.h"

void SaveFile()
{
	FILE *file = fopen(FileName, "w");
    int i;

    fprintf(file, "%d\n", numEvents);
}

void LoadFile()
{
	FILE *file = fopen(FileName, "r");
    if(file == NULL)
        return;

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "%d", &numEvents);
}