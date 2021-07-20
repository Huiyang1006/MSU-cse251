#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Name :  Huiyang Zhao
 * 
 * Simple Wumpus game in 1D
*/

/* Add any #defines here */
/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
/* Number of rooms in our Cave */
#define CaveSize 20
#define ArraySize (CaveSize + 2)
/* Directions I can face */
#define Left 0
#define Right 1



/* Add any function prototypes here */
int* CreateWorld(int[]);
int* GetEmptyRoom(int[]);
void DisplayWorld(int[], int*, int);
int DifferenceByDirection(int);
bool DisplayStatus(int[], int*);
bool fire(int*, int*, int);
 
int main()
{

    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    int direction;

    int *room;
    int *witcher;

    char command[20];

    
    /* Seed the random number generator */
    srand(time(NULL));
    
    witcher = CreateWorld(cave);

    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 2;

    /* The game loop */
    while(true)
    {
        if(DisplayStatus(cave, agentRoom))
            break;
        DisplayWorld(cave, agentRoom, agentDirection);
        /* Get the command */
        printf("Command: ");
        scanf("%20s", command);

        if(strcmp(command, "quit") == 0)
        {
            /* Exit, we are doing */
            break;
        }
        else if(strcmp(command, "move") == 0)
        {
            /* Move command */
            /* What way do we need to go? */
            direction = DifferenceByDirection(agentDirection);
            if( *(agentRoom + direction) != End)
                agentRoom += direction;
        }
        else if(strcmp(command, "turn") == 0)
        {
            agentDirection = !agentDirection;
        }
        else if(strcmp(command, "fire") == 0)
        {
            //direction = DifferenceByDirection(agentDirection);
            if(fire(agentRoom, witcher, agentDirection))
                break;
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
}

int *CreateWorld(int cave[])
{
    /* Initialize cave to empty */
    int i;
    int *room;

    for(i = 0;  i<ArraySize;  i++)
        cave[i] = Empty;

    /* Set the ends */
    cave[0] = End;
    cave[ArraySize-1] = End;

    /* Get a random empty room and put the Wumpus in it */
    room = GetEmptyRoom(cave);
    *room = Wumpus;

    return room;
}

int *GetEmptyRoom(int cave[])
{
    int room;
    
    do
    {
        room = rand() % ArraySize;
    } while(cave[room] != Empty);
    
    return &cave[room];
}

void DisplayWorld(int cave[], int *agent, int agentDir)
{
    int *room;
    
    for(room = cave + 1;  *room != End;  room++)
    {
        if(room == agent)
        {
            switch(agentDir)
            {
            case Left:
                printf("<A  ");
                break;
                
            case Right:
                printf(" A> ");
            }
            
            continue;
        }

        switch(*room)
        {
        case Wumpus:
            printf("-W- ");
            break;
            
        default:
            printf(" .  ");
            break;    
        }
    }
    printf("\n");
}

int DifferenceByDirection(int dir)
{
    if(dir == Left)
        return -1;
    else
        return 1;
}

bool DisplayStatus(int cave[], int *agent)
{
    if(*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus.\n");
        return true;
    }
    if(*(agent-1) == Wumpus || *(agent + 1) == Wumpus)
    {
        printf("I smell a Wumpus.\n");
    }
   
    /* We will return true to indicate we are dead! */
    return false;
}

bool fire(int *agent, int *witcher, int direction)
{
    int distance;

    distance = agent - witcher;
    
    if ((distance <= 3 && distance > 0 && !direction) || (distance >= -3 && distance < 0 && direction))
    {
        printf("Getcha!\n");
        *witcher = Empty;
        return 1;
    }
    //printf("Distance: %d, Direction: %d\n", distance, direction);
    else
        return 0;
}
