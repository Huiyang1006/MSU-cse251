#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hanoi.h"
#include "autosolve.h"


/*
 * Automatically solve the Towers of Hanoi problem.
 * This resets the tower to the initial state, then
 * solves it one step at a time.
 */
void Autosolve(int tower[NumPins][NumDisks])
{
    /* Always start with empty tower */
    Reset(tower);
    AutoMove(tower, NumDisks, 1, 3);
    DisplayTower(tower);
}

/*
 * Recursive solution for Towers of Hanoi. Moves num disks from
 * pin fm to pin to.
 */
void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to)
{
    int unused;
    char cmd[2];

    /* Base condition, moving one disk */
    if(num == 1)
    {
        /* This is the only time we actually move a disk */
        DisplayTower(tower);

        printf("Press return");
        fgets(cmd, sizeof(cmd), stdin);

        MoveDisk(tower, fm, to);
        return;
    }

    /* What is the unused pin? */
    for(unused=1;  unused <=3;  unused++)
    {
        if(unused != fm && unused != to)
            break;
    }

    /* Recursive solution for fewer pins */
    AutoMove(tower, num-1, fm, unused);
    AutoMove(tower, 1, fm, to);
    AutoMove(tower, num-1, unused, to);
}

/*
 * Reset the tower to its initial state
 */
void Reset(int tower[NumPins][NumDisks])
{
    int i, j;

    for(j=0;  j<NumDisks;  j++)
    {
        tower[0][j] = 13 - j * 2;
    }

    for(i=1; i<NumPins;  i++)
    {
        for(j=0;  j<NumDisks;  j++)
        {
            tower[i][j] = 0;
        }
    }

}

/*
 * Move a disk from one pin to another
 */
void MoveDisk(int tower[NumPins][NumDisks], int fm, int to)
{
    int f;
    int t;
    int moving;

    /* Where is the pin to move? */
    for(f=NumDisks-1; f>=0;  f--)
    {
        if(tower[fm-1][f] > 0)
            break;
    }

    if(f < 0)
    {
        printf("No disks on that pin\n");
        return;
    }

    /* Size we are moving */
    moving = tower[fm-1][f];

    /* Where is an empty space to move to? */
    for(t=NumDisks-1; t>=0;  t--)
    {
        if(tower[to-1][t] > 0)
            break;
    }

    /* Test to move legality */
    if(t >= 0 && tower[to-1][t] < moving)
    {
        printf("\n!!! Illegal move !!!\n");
        return;
    }

    /* And move it */
    t++;
    tower[to-1][t] = moving;
    tower[fm-1][f] = 0;
}