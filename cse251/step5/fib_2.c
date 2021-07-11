#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Program to compute Fibonacci numbers with recursion.
 */

int fib(int);

int main()
{
    int fibnum;
    int i = 0;

    printf("Please enter the number of Fibonacci numbers you want: ");
    scanf("%d", &fibnum);
    printf("This is a Fibonacci sequent: \n");
    while(i<fibnum)
    {
        printf("F(%2d) = %2d\n", i, fib(i));
        i++;
    }

    return 0;

}

int fib(int num)
{
    if (num == 0)
        return 0;
    else if (num <= 2)
        return 1;
    else 
        return fib(num-1) + fib(num-2);
}