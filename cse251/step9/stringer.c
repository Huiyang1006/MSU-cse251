#include <stdio.h>
#include <string.h>

/* 
 * Name : Huiyang Zhao
 * Program to experiment with strings
 */

int StringLength(char[]);
void PrintLength(char[]);

int main()
{
    char word[] = "chudge";
    char myWord[20];
    char mySentence[80];
    int i;
    int len;

    printf("Enter a sentence: ");
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    printf("Enter a word: ");
    scanf("%79s", myWord);
    myWord[19] = '\0';
    printf("The entered word is: %s\n", myWord);

   /* 
    for(i=0;  word[i] != '\0';  i++)
    {
        printf("Location %d: %c\n", i, word[i]);
    }
    */

    //len = StringLength(word);
    //len = strlen(word);
    //printf("The string %s is %d characters long\n", word, len);
    //printf("The string %s is %d characters long\n", myWord, strlen(myWord));
    //printf("\n");
    PrintLength(mySentence);
    PrintLength(word);
    PrintLength(myWord);
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