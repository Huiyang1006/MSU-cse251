#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple program to experiment with looping
 */

int main()
{
    double angle;
    double sinVal;
    double temSin;
    double temAng;
    double delta;
    double fraction;
    int numSteps;
    double maxAngle = M_PI * 2;
    int i, j;
    int numSpaces;
    //char signal = '\\';

    do
    {   
        printf("Please enter the number of steps you want: ");
        scanf("%d", &numSteps);
    } while (numSteps<=2);

    delta = 1.0 / (double)numSteps;
    getchar();

    // printf("please enter the signal you want: ");
    // scanf("%c", &signal);
    

    for(i = 0;  i<=numSteps;  i++)
    {
        //temAng = angle;
        angle = (double)i * delta * maxAngle;
        //temSin = sinVal;
        sinVal = sin(angle);
        numSpaces = (int)(30 * (1 + sinVal));
        /*
        if (angle == 0 && sinVal == 0)
            fraction = 1;
        else
            fraction = (sinVal - temSin) / (angle - temAng);
        */
        
        fraction = cos(angle);

        printf("%3d: %5.2f %6.3f", i, angle, sinVal);
        for (j = 0; j<=numSpaces; j++)
            printf(" ");

        
        //printf("fraction: %2.2f", fraction);
        if (fabs(fraction) < 0.1)
            printf("*");

        if (fraction > 0.1)
            printf("\\");
        else if (fraction < -0.1)
            printf("/");
            //printf("%c\n", signal);

        printf("\n");
    }
}