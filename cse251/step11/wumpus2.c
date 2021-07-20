#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Name :  <insert name here>
 * 
 * Simple Wumpus game in 2D
*/

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
#define Pit 3
#define Agent 4

/* Number of rooms in our Cave in each dimension */
#define CaveSize 10
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Up 1
#define Right 2
#define Down 3

int* CreateWorld(int[ArraySize][ArraySize]);
int *GetEmptyRoom(int[ArraySize][ArraySize]);
void DisplayWorld(int[ArraySize][ArraySize], int*, int);
int DifferenceByDirection(int);
bool DisplayStatus(int[ArraySize][ArraySize], int*);
bool fire(int *, int*, int);

 
int main()
{
    int *agentRoom;
    int agentDirection;
    char command[20];

    int cave[ArraySize][ArraySize];
    int d;

    int* witcher;

    /* Seed the random number generator */
    srand(time(NULL));

    agentRoom = GetEmptyRoom(cave);
    *agentRoom = Agent;
    agentDirection = rand() % 4;
    witcher = CreateWorld(cave);
    *agentRoom = Empty;
    
    
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
            d = DifferenceByDirection(agentDirection);
            
            if(*(agentRoom + d) != End)
                agentRoom += d;
        }
        else if(strcmp(command, "turn") == 0)
        {
            agentDirection ++;
            if(agentDirection > Down)
                agentDirection = Left;
        }
        else if(strcmp(command, "fire") == 0)
        {
            if(fire(agentRoom, witcher, agentDirection))
                break;
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
    
}

int* CreateWorld(int cave[ArraySize][ArraySize])
{
    int i, j;
    int *room;
    int *pit;
    
    for(i = 0;  i<ArraySize;  i++)
    {
        for(j = 0;  j<ArraySize;  j++)
        {
            if(i == 0 || j == 0 || i == ArraySize-1 || j == ArraySize-1)
            {
                cave[i][j] = End;
            }
            else
            {
                cave[i][j] = Empty;
            }
        }
    }

    room = GetEmptyRoom(cave);
    *room = Wumpus;
    for (i = 0; i < 10; ++i)
    {
        pit = GetEmptyRoom(cave);
        if (pit == room || *pit == Agent || *pit == Pit)
        {
            i--;
            //printf("Test1\n");
        }
        else
        {
            *pit = Pit;
            //printf("Test2\n");
        }
        
    }

    return room;
}

int *GetEmptyRoom(int cave[ArraySize][ArraySize])
{
    int row, col;
    int *room;
    
    do
    {
        /* We need a random number in each dimension */
        row = rand() % ArraySize;
        col = rand() % ArraySize;
        
        room = &cave[row][col];
    } while(*room != Empty);
    
    return room;
}

void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir)
{
    int row, col;
    int *room;
    
    /* Loop over the rows of the cave */
    for(row=1;  row <= CaveSize + 1;  row++)
    {
        /* 
         * This loop lets us print an up direction 
         * above the agent or a v below the agent
         */
         
        for(col=1; col<=CaveSize; col++)
        {
            if(&cave[row][col] == agent && agentDir == Up)
            {
                printf(" ^  ");
            }
            else if(&cave[row-1][col] == agent && agentDir == Down)
            {
                printf(" v  ");
            }
            else
            {
                printf("    ");
            }
        }
        
        printf("\n");
        if(row > CaveSize)
            break;
            
        /*
         * This loop prints the agent or the room contents
         */ 
         
        for(col=1; col<=CaveSize; col++)
        {
            room = &cave[row][col];
            if(room == agent)
            {
                switch(agentDir)
                {
                case Left:
                    printf("<A  ");
                    break;
                    
                case Right:
                    printf(" A> ");
                    break;
                    
                default:
                    printf(" A  ");
                    break;
                        
                }
                continue;
            }
            
            switch(*room)
            {
            case Wumpus:
                printf("-W- ");
                break;

            case Pit:
                printf(" O  ");
                break;
                
            default:
                printf(" .  ");
                break;    
            }  
            
        }

        printf("\n");
    }
    
}

bool DisplayStatus(int cave[ArraySize][ArraySize], int *agent)
{
    if(*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus.\n");
        return true;
    }
    if(*agent == Pit)
    {
        printf("You fell into a pit.\n");
        return true;
    }
    if(*(agent-1) == Wumpus || *(agent + 1) == Wumpus || 
        *(agent + ArraySize) == Wumpus || *(agent - ArraySize) == Wumpus)
    {
        printf("I smell a Wumpus.\n");
    }
    if(*(agent-1) == Pit || *(agent + 1) == Pit || 
        *(agent + ArraySize) == Pit || *(agent - ArraySize) == Pit)
    {
        printf("I feel a draft\n");
    }
   
    /* We will return true to indicate we are dead! */
    return false;
}

int DifferenceByDirection(int dir)
{
    switch(dir)
    {
    case Up:
        return -ArraySize;
        break;
        
    case Down:
        return ArraySize;
        break;

    case Left:
        return -1;
        break;

    case Right:
        return 1;
        break;

    default:
        return 0;
        printf("False Direction\n");
    }
}

bool fire(int *agent, int *witcher, int direction)
{
    int distance;
    int count;

    distance = agent - witcher;
    
    if ((distance <= 3 && distance > 0 && direction == Left) || (distance >= -3 && distance < 0 && direction == Right))
    {
        printf("Getcha!\n");
        *witcher = Empty;
        return 1;
    }
    for(count = -3; count <=3; count++)
    {
        if (count == 0)
        {
            continue;
        }
        else if (distance == count * ArraySize)
        {
            printf("Getcha!\n");
            *witcher = Empty;
            return 1;
        }
    }

    printf("Distance: %d, Direction: %d\n", distance, direction);

    return 0;
}