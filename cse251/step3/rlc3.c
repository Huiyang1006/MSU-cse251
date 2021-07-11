#include <stdio.h>
#include <math.h>

/*
 *this is a simple program to compute the resonant frequency
 *of an RLC circuit.
 */

int main()
{
  double capacitance; /*capacitance in microfarads.*/
  double inductance;  /*inductance in milihenrys.*/
  double omega;       /*radians per second.*/
  double frequency;   /*in Hertz, f = w/2pi.*/

  printf("Input Capacitance (microfarads): ");
  scanf("%lf", &capacitance);
  /* change the value of capacitance to 1 when input is invalid.*/
  if(capacitance<=0)
    capacitance = 1;

  printf("Input inductance (milihenrys): ");
  scanf("%lf", &inductance);
  /*change the value of inductance to 1 when input is invalid.*/
  if (inductance<=0)
    inductance =1;

  omega = 1.0 / sqrt(inductance/1000*capacitance/1000000);
  frequency = omega / (2*M_PI);
  printf("Resonant frequency: %.2f\n", frequency);

  return 0;
}


