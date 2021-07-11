#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
 * Simple program to experiment with looping
 */

int main()
{
    int f = 1;      /* Number we compute the factorial of */
    int origin;
    int fac = 1;    /* Initial value of factorial */

    while (f>=0)
    {
        printf("Number to compute the factorial of: ");
        scanf("%d", &f);
        origin = f;

        if (origin<0)
        {
            exit(1);
        }
        if (origin == 0)
        {
            fac = 1;
        }

        while(f > 0)
        {
            fac = fac * f;
            f--;
        }

        printf("%d! = %d\n", origin, fac);
    }
}
