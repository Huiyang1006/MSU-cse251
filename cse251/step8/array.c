#include <stdio.h>
#define NumMovies 10
#define MaxGrosses 5

/* 
 * Name : Huiyang Zhao
 * Program to experiment with arrays
 */


 
int main()
{
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech", 
                         "Just Go With It", "Gnomeo and Juliet", "Drive Angry", 
                         "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son", 
                         "True Grit"};
    double sum;
    int i, j;

    int highestGrossIndex = 0;
    int highestGrossIndex2 = 0;
    double highestGross = 0;
    double highestGross2 = 0;
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    
    sum = 0;        /* Initialize to zero */
    for(i = 0;  i<NumMovies;  i++)
    {
        printf("Movie %2d %33s: %.0f\n", i+1, names[i], gross[i]);
        sum = sum + gross[i];
    }
    for(j=0;j<MaxGrosses;j++)
    {
        for(i=0, highestGrossIndex2 = -1;  i<NumMovies;  i++)
        {
            if (gross[i] > highestGross)
            {
                highestGrossIndex = i;
                highestGross = gross[highestGrossIndex];
            }
            if (gross[i] < maxGross[j] && gross[i] > highestGross2)
            {
                highestGrossIndex2 = i;
                highestGross2 = gross[highestGrossIndex2];
            }
        }
        if (highestGrossIndex2 == -1)
        {
            printf("No film made less than %.f\n", maxGross[j]);
        }
        else
        {
            printf("The highest gross less than %.f is %.f at gross[%d]\n", 
                maxGross[j], gross[highestGrossIndex2], highestGrossIndex2);
        }

    }
    printf("Total gross for these films was $%.0f\n", sum); 

    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

}
