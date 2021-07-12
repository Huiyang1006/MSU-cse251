#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



/* 
 * Name : Huiyang Zhao
 * Program to draw playing cards
 */

/* Function declaration */
void PrintCard(int card, int suit);
void DrawCard(int *card, int * suit);
void PrintResult(int ,int ,int, int);

int main()
{
    int suit;
    int card;
    int card1, suit1;
    int card2, suit2;
    
    srand(time(NULL));

    do {
        DrawCard(&card1, &suit1);
        PrintCard(card1, suit1);

        DrawCard(&card2, &suit2);
        PrintCard(card2, suit2);

        PrintResult(card1, card2, suit1, suit2);
    } while(card1 == card2 && suit1 == suit2);
}

void DrawCard(int *card, int * suit)
{
     /* Create a random card and suit */
    /* This will compute a random number from 0 to 3 */
    *suit = rand() % 4;
    
    /* This will compute a random number from 1 to 13 */
    *card = rand() % 13 + 1;
}

void PrintCard(int card, int suit)
{
    switch(card)
    {
    case 1:
        printf("Ace");
        break;
        
    case 11:
        printf("Jack");
        break;
        
    case 12:
        printf("Queen");
        break;
        
    case 13:
        printf("King");
        break;
        
    default:
        printf("%d", card);
        break;
    }
    
    printf(" of ");
    
    switch(suit)
    {
    case 0:
        printf("Hearts");
        break;
        
    case 1:
        printf("Diamonds");
        break;
        
    case 2:
        printf("Spades");
        break;
        
    case 3:
        printf("Clubs");
        break;
    }

    printf("\n");    
}

void PrintResult(int num1, int num2, int type1, int type2)
{
    if (num1 == num2)
    {
        if (type1==type2)
        {
            printf("There is a tie.\n");
        }
        else if (type1<type2)
        {
            printf("Player1 wins.\n");
        }
        else
        {
            printf("Player2 wins.\n");
        }
    }
    else if (num1<num2)
    {
        if (num1 == 1)
        {
            printf("Player1 wins.\n");
        }
        else
        {
            printf("Player2 wins.\n");
        }
    }
    else
    {
        if (num2 == 1)
        {
            printf("Player2 wins.\n");
        }
        else
        {
            printf("Player1 wins.\n");
        }
    }
}
