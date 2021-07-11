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

int main()
{
    int suit;
    int card;
    int num;
    
    /* 
     . This seeds the random number 
     . generator with the current time 
     */
    srand(time(NULL));
    
    /* Create a random card and suit */
    /* This will compute a random number from 0 to 3 */
    suit = rand() % 4;
    
    /* This will compute a random number from 1 to 13 */
    card = rand() % 13 + 1;

    printf("How many cards do you want to draw: ");
    scanf("%d", &num);
    while (num--!=0)
    {
        PrintCard(card, suit);
        printf("\t");
    }
    
    printf("\n");       

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
   
}
