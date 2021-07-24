#ifndef TRANSISTORS_H
#define TRANSISTORS_H
#include <stdbool.h>

/* Types */
#define NPN 1
#define PNP 2

/* Cases */
#define TO18 1
#define TO92A 2
#define TO92C 3
#define TO220 4
#define TO39 5

typedef struct Transistor
{
    char number[10];
    int type;       /* NPN, PNP, etc. */
    int caseStyle;  /* TO18, etc. */
    double pmax;    /* Maximum power dissipation watts */
    double icmax;   /* Maximum collector current amps */
} Tran;

void DisplayTransistor(Tran tran);
struct Transistor InputTransistor();
void InputString(char *str, int max);
double InputPositiveValue(char *prompt);
int InputTransistorType(char *prompt);
int InputTransistorStyle(char *prompt);
bool Another();

#endif