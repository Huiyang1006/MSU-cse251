#include <stdio.h>
#include <stdbool.h>

/*
 * My hanoi tower program.
 * By Huiyang Zhao.
 */

#ifndef Num
#define NumPins 3
#define NumDisks 6
#define MaxDiskSize 2 * NumDisks + 1
#endif

void Reset(int[NumPins][NumDisks]);
void DisplayDisk(int);
void DisplayTower(int[NumPins][NumDisks]);
void AutoMove(int[NumPins][NumDisks], int, int, int);
void MoveDisk(int[NumPins][NumDisks], int, int);

int main(void)
{
	int num;
	int tower[NumPins][NumDisks];
	int fm, to;

	printf("Hanoi tower is a very interesting problem\n" 
		"that can be solved with recursion.\n");
	printf("This is a hanoi tower: \n");

	Reset(tower);
	// DisplayTower(tower);

	AutoMove(tower, NumDisks, 1, 3);
	DisplayTower(tower);


	return 0;
}

void Reset(int tower[NumPins][NumDisks])
{
	int i, j;

    for(j=0;  j<NumDisks;  j++)
    {
        tower[0][j] = MaxDiskSize - j * 2;
    }

    for(i=1; i<NumPins;  i++)
    {
        for(j=0;  j<NumDisks;  j++)
        {
            tower[i][j] = 0;
        }
    }
}

void DisplayDisk(int num)
{
	int i;
	int blank = (MaxDiskSize - num) / 2;

	for(i = 0; i < blank; i++)
        printf(" ");

    if(num == 0)
    {
        printf("|");
    }
    else
    {
        for(i = 0; i < num; i++)
            printf("O");
    }

    for(i = 0; i < blank; i++)
        printf(" ");
}

void DisplayTower(int tower[NumPins][NumDisks])
{
	int i;

    printf("\n ");

    DisplayDisk(0);
    printf("  ");
    DisplayDisk(0);
    printf("  ");
    DisplayDisk(0);
    printf("\n");

    for(i=0;  i<NumDisks;  i++)
    {
        printf(" ");

        /* We display from the top down */
        DisplayDisk( tower[0][5 - i] );
        printf("  ");
        DisplayDisk( tower[1][5 - i] );
        printf("  ");
        DisplayDisk( tower[2][5 - i] );
        printf("\n");
    }

    for(i=0;  i<NumPins * MaxDiskSize + (NumPins - 1) * 2 + 3; i++)
        printf("=");

    printf("\n");
}

void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to)
{
	int unused;

	/* What is the unused pin? */
    for(unused=1;  unused <=3;  unused++)
    {
        if(unused != fm && unused != to)
            break;
    }

	/* base case. */
	if (num == 1)
	{
		DisplayTower(tower);
		MoveDisk(tower, fm, to);
		printf("Press return to continue.");
		do {
			;
		} while(getchar()!='\n');
	}
	/* recursive case */
	else {
		AutoMove(tower, num-1, fm, unused);
		AutoMove(tower, 1, fm, to);
		AutoMove(tower, num-1, unused, to);
	}
}

void MoveDisk(int tower[NumPins][NumDisks], int fm, int to)
{
	int f;
    int t;
    int moving;

	fm--;
	to--;

	/* find the position of fm disks. */
	for (f = NumDisks-1; f >= 0; f--)
	{
		if(tower[fm][f] > 0)
            break;
	}
	if(f < 0)
    {
        printf("No disks on that pin.\n");
        return;
    }
	moving = tower[fm][f];
	/* find the position of to disks. */
	for (t = NumDisks-1; t >= 0; t--)
	{
		if(tower[to][t] > 0)
            break;
	}
	/* Test to move legality */
    if(t >= 0 && tower[to][t] < moving)
    {
        printf("\n!!! Illegal move !!!\n");
        return;
    }

    /* And move it */
    t++;
    tower[to][t] = moving;
    //printf("moving: %d, from: %d, to: %d, tower: %d\n", moving, fm, to, tower[fm][f]);
    tower[fm][f] = 0;
    //printf("moving: %d, from: %d, to: %d, tower: %d\n", moving, fm, to, tower[fm][f]);
}