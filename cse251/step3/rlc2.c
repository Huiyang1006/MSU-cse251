#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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

  bool valid = true;  /*until we know otherwise.*/

  printf("Input Capacitance (microfarads): ");
  scanf("%lf", &capicitance);
  /* Test to see if the user entered an invalid value */
  if(capicitance < 0)
  {
    printf("You moron, you entered a negative capicitance!\n");
    //exit(1);
    valid = false;
  }
  else if(capicitance == 0)
  {
    printf("You are really dumb, you entered zero.\n");
    valid = false;
  }
  else
    printf("Okay, I guess that's reasonable\n");

  printf("Input inductance (milihenrys): ");
  scanf("%lf", &inductance);
  /* Test to see if the user entered an invalid value */
  if(inductance < 0)
  {
    printf("You moron, you entered a negative inductance!\n");
    valid = false;
  }
  else if(inductance == 0)
  {
    printf("You are really dumb, you entered zero.\n");
    valid= false;
  }
  else
    printf("Okay, I guess that's reasonable\n");
  if(valid){
    omega = 1.0 / sqrt(inductance / 1000 * capicitance / 1000000);
    frequency = omega / (2 * M_PI);
    printf("Resonant frequency: %.2f\n", frequency);
     if (frequency <= 20000 && 20 <= frequency)
      printf("This frequency is one I can hear!\n");
  }
  else
    printf("Your input is invalid.\n");

 

  return 0;
}


