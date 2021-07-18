#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 
 * Name : Huiyang Zhao
 * Program to experiment with strings
 */

int StringLength(char[]);
void PrintLength(char[]);
void Reverse(char[]);
int NumberOfSpaces(char[]);
int NumberOfAppearances(char[], char);

int main()
{
    
    char mySentence[80];
    int i;
    int len;
    char ch = 'i';

    printf("Enter a sentence: ");
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    PrintLength(mySentence);

    Reverse(mySentence);
    printf("The reversed sentence is: %s\n", mySentence);

    printf("The number of spaces is: %d\n", NumberOfSpaces(mySentence));

    printf("The character %c has %d appearances.\n", ch, NumberOfAppearances(mySentence, ch));
}

int StringLength(char str[])
{
    int numChars = 0;

    while(str[numChars] != '\0')
    {
        numChars++;
    }

    return numChars;
}

void PrintLength(char str[])
{
    printf("The string %s is %d characters long\n", str, strlen(str));
}

void Reverse(char str[])
{
    int front = 0;
    int back = strlen(str)-1;
    char temp;

    while(front<back)
    {
        temp = str[front];
        str[front] = str[back];
        str[back] = temp;
        front++;
        back--;
    }
}

int NumberOfSpaces(char str[])
{
    int numSpaces = 0;
    int i;

    for(i=0;  str[i] != '\0';  i++)
    {
        //printf("Location %d: %c\n", i, str[i]);
        if(str[i] == ' ')
            numSpaces++;
    }

    return numSpaces;
}

int NumberOfAppearances(char str[], char ch)
{
    int numApear = 0;
    int i;

    for(i=0;  str[i] != '\0';  i++)
    {
        //printf("Location %d: %c\n", i, str[i]);
        if(tolower(str[i]) == ch)
            numApear++;
    }

    return numApear;
}