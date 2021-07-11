#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple lunar lander program.
 * By:  Huiyang Zhao
 */
 
int main()
{
    printf("Lunar Lander - (c) 2012, by <Huiyang Zhao>\n");

    double altitude = 100;      /* Meters. */
    double velocity = 0;        /* Meters per second */
    double fuel = 100;          /* Kilograms. */
    double power = 1.5;         /* Acceleration per pound of fuel. */
    double g = -1.63;           /* Moon gravity in m/s^2. */
    double burn;                /* Amount of fuel to burn. */
    bool valid;                 /* Valid data entry flag. */
    int clock = 0;              /* Record the time used. */

    while(altitude>0)
    {    
        printf("Altitude: %6.2f\n", altitude);
        printf("Velocity: %6.2f\n", velocity);
        printf("You have %.2f kilograms of fuel.\n", fuel);

        do{
            valid = false;

            printf("How much fuel would you like to burn: ");
            if (!scanf("%lf", &burn))
            {
                printf("Please enter a number of fuel to burn.\n");
                getchar();
            }
            else
            {
                if(burn < 0)
                {
                    printf("You can't burn negative fuel.\n");
                }
                else if(burn > 5)
                {
                    printf("You can't burn more than 5 kilograms per second.\n");
                }
                else if(burn > fuel)
                {
                    printf("You can't burn fuel you don't have.\n");
                }
                else
                {
                    printf("Burning %.1f kilograms of fuel.\n", burn);
                    valid = true;
                }
            }
        } while (!valid);

        velocity = velocity + g + power * burn;
        altitude += velocity;
        fuel -= burn;
        clock++;
    }

    printf("You landed with a velocity of %.2f.\n", velocity);
    
    if(fabs(velocity) > 3)
    {
        printf("Your next of kin have been notified.\n");
    }
    printf("It takes you %d seconds to land on the moon.\n", clock);
    printf("%.2lf kilograms fuel is remained.\n", fuel);

}
