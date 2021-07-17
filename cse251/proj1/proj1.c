#include<stdio.h>
#include<math.h>

#define MAX_N 100000
#define MIN_N 10
#define ERROR 1e-10

double func(double);
double integral(double, double, int);

/*
∗ CSE 251 Project 1
∗ By: ¡your name here¿ ∗
∗ Complete the following table:
*
* a        b        n        estimate
* -1       1       1883     1.178979838
* 0        10 	   2028     0.489888070
* -1000   1000	  18861     0.999796418
* 10       15	   1515     0.016860599
* 0.1      0.2     138  	0.096211811
*/



int main()
{
	double a, b;
	double sum = 0;
	double temp_sum;
	double decrease = 1;

	int n = MIN_N;
	//int i = 1;

	printf("Please enter the value of a: ");
	scanf("%lf", &a);
	printf("Please enter the value of b: ");
	scanf("%lf", &b);

	// printf("The n starts from: ");
	// scanf("%d", &n);

	//integral(a, b, n);
	do
	{
		temp_sum = sum;
		sum = integral(a, b, n);
		if (temp_sum == 0)
			printf("%d: %.9f\n", n, sum);
		decrease = fabs(sum - temp_sum);
		printf("%d: %.9lf %e\n", n, sum, decrease);

	} while(n++ <= MAX_N && decrease > ERROR);


}

double func(double x)
{
	double result;

	if (x==0)
	{
		result = 1;
	}
	else
	{
		result = sin(M_PI * x) / (M_PI * x);
	}

	return result;
}

double integral(double a, double b, int n)
{
	double sum = 0;
	double delta;
	double input;
	int i;

	delta = (b - a) / n;

	for (int i = 1; i <= n; i++)
	{
		input = a + (i - 0.5) * delta;
		sum = sum + delta * func(input);
		//sum = sum + delta * func(a, delta, i);
		//printf("sum:\t%d\t%f\n",i, sum);
	}

	return sum;
}