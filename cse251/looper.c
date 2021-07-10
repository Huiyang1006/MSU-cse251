#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple program to experiment with looping
 */

int main()
{
    int i = 0;

    printf("My looper program!\n");

    while(i < 10)
    {
        printf("i=%2d\n", i);
        i = i + 1;
    }


}
