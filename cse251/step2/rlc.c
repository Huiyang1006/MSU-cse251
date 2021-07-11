#include <stdio.h>
#include <math.h>

/*
 *this is a simple program to compute the resonant frequency
 *of an RLC circuit.
 */

int main()
{
  double capicitance; /*capacitance in microfarads.*/
  double inductance;  /*inductance in milihenrys.*/
  double omega;       /*radians per second.*/
  double frequency;   /*in Hertz, f = w/2pi.*/
  
  printf("Input Capacitance (microfarads): ");
  scanf("%lf", &capicitance);
  printf("Input inductance (milihenrys): ");
  scanf("%lf", &inductance);

  omega = 1.0 / sqrt(inductance/1000*capicitance/1000000);
  frequency = omega / (2*M_PI);
  printf("Resonant frequency: %.2f\n", frequency);

  return 0;
}
