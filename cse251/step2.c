#include <stdio.h>
#include <math.h>
/*
 * Name : huiyang
 * 
 * This is my first CSE 251 C program!!!
 */

int main()
{
    double radius = 7.88;
    double height = 12.231;
    int wins = 11;
    int losses = 2;

    double near = 10;
    double far = 22.5;

    double volume, diameter, hypot;
    int games;

    double bottleVolume = 1700;  /* Milliliters */
    double cupVolume = 350;      /* Milliliters */
    double numCups;


    printf("My first C program\n");
    printf("Aren't you impressed?\n");

    printf("The cylinder has a radius of %5.2f and a height of %5.1f\n", radius, height);
    printf("MSU had an %d - %d season in 2010!\n", wins, losses);

    games = wins + losses;
    volume = radius * radius * M_PI * height;
    hypot = sqrt(near * near + far * far);

    numCups = bottleVolume / cupVolume;
    printf("Number of cups: %f\n", numCups);

}