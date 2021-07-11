#include <stdio.h>
#include <stdlib.h>

/*
 *this is a simple program to calculate people's tax.
 */
int calculate(int);

// int calculate(int money)
// {

// }

int main()
{
	const int DepenDeduct = 3650;	/* The deducted amount for each dependents. */
	int income;						/* People's income. */
	int TaxableIncome;				/* Deducted income. */
	double tax;						/* Tax that shall be paid. */
	int status;						/* People's filing status. */
	int dependents;					/* Number of dependents. */
	int deduction;					/* The standard deduction. */
	int NumChild;					/* The number of your children. */
	int TotalDeduction;				/* The total deduction of your tax. */

	printf("Please enter your annual income: ");
	if(!scanf("%d", &income) || income < 0)
	{
		printf("Invalid input.\n");
		exit(1);
	} 
	else if (income<9350)
	{
		tax = 0;
		printf("The tax you need to pay is: %.2f.\n", tax);
		return 0;
	}

	printf("Please enter your filing status: \n");
	printf("(1) Single.\n");
	printf("(2) Married, filing jointly.\n");
	printf("(3) Married, filing seperately.\n");
	printf("Please enter a number: ");
	if(!scanf("%d", &status) || status < 1 || status > 3)
	{
		printf("Invalid input.\n");
		exit(1);
	}
	else
	{
		switch(status)
		{
			case 1:
				dependents = 1;
				deduction = 5700;
				break;
			case 2:
				printf("Please enter the number of your children: ");
				if(!scanf("%d", &NumChild) || NumChild < 0)
				{
					printf("Invalid input.\n");
					exit(1);
				}
				dependents = 2 + NumChild;
				deduction = 11400;
				break;
			case 3:
				dependents = 1;
				deduction = 5700;
				break;
		}
		TotalDeduction = deduction + dependents * DepenDeduct;
	}
	TaxableIncome = income - TotalDeduction;

	if (TaxableIncome <= 16750)
		tax = 0 + 0.1 * TaxableIncome;
	else if (TaxableIncome <= 68000)
		tax = 1675 + 0.15 * (TaxableIncome - 16750);
	else if (TaxableIncome <= 137300)
		tax = 9352.50 + 0.25 * (TaxableIncome - 68000);
	else
		tax = 26687.50 + 0.28 * (TaxableIncome - 137300);

	printf("The calculated tax is: %.2f.\n", tax);

	return 0;
}
