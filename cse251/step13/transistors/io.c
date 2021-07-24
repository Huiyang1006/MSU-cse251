#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "transistors.h"

void DisplayTransistor(Tran tran)
{
    printf("Number: %s\n", tran.number);
    switch(tran.type)
    {
    case NPN:
        printf("Type: NPN\n");
        break;
        
    case PNP:
        printf("Type: PNP\n");
        break;
    }
    switch(tran.caseStyle)
    {
    case TO18:
        printf("style: T018\n");
        break;
    case TO92A:
        printf("Style: TO92A\n");
        break;
    case TO92C:
        printf("Style: TO92C\n");
        break;
    case TO220:
        printf("Style: TO220\n");
        break;
    case TO39:
        printf("Style: TO39\n");
    }
    printf("pMax: %.3f\n", tran.pmax);
    printf("icMax: %.3f\n", tran.icmax);
}

struct Transistor InputTransistor()
{
    struct Transistor t1;
    
    printf("Input transistor: ");
    InputString(t1.number, sizeof(t1.number));
    /*t1.type = NPN;*/
    /*t1.caseStyle = TO39;*/

    #if 0
    t1.pmax = 0.500;    /* 500mw */
    t1.icmax = 0.700;   /* 700ma */
    #endif

    t1.type = InputTransistorType("Input type: ");
    t1.caseStyle = InputTransistorType("Input case style: ");
    // printf("Input pMax: ");
    // scanf("%lf", &t1.pmax);
    t1.pmax = InputPositiveValue("Input pMax: ");

    // printf("Input icMax: ");
    // scanf("%lf", &t1.icmax);
    t1.icmax = InputPositiveValue("Input icMax: ");

    return t1;
}

void InputString(char *str, int max)
{
    char buffer[100];
    
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);
    
    /* Remove any \n we may have input */
    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';
        
    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max-1] = '\0';
}

double InputPositiveValue(char *prompt)
{
    char buffer[100];
    double value = 0;
    
    do
    {
        printf("%s", prompt);
     
        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);
        
        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';
            
        sscanf(buffer, "%lf", &value);
    } while(value <= 0);
    
    return value;
}

int InputTransistorType(char *prompt)
{
    char buffer[100];
    int type = 0;
    
    do
    {
        printf("%s", prompt);
     
        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);
        
        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';
            
        sscanf(buffer, "%d", &type);
    } while(type <= 0);
    
    return type;
}

int InputTransistorStyle(char *prompt)
{
    char buffer[100];
    int style = 0;
    
    do
    {
        printf("%s", prompt);
     
        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);
        
        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';
            
        sscanf(buffer, "%d", &style);
    } while(style <= 0);
    
    return style;
}

bool Another()
{
    char get;
    char flag;

    printf("Would you like to enter another transistor (Y/N)? \n");

    scanf("%c", &get);
    getchar();

    get = tolower(get);

    while(get != 'y' && get != 'n')
    {   
        printf("Error, please enter Y/N.\n");
        scanf("%c", &get);
        getchar();
    }
    
    if (get == 'y')
        flag = true;
    else if (get == 'n')
        flag = false;

    return flag;

}