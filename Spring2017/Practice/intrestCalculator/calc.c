#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main ()
{
	int choice, year;
	float amount, rate;
	printf("Bank Account Type");
	printf("\n (1) Checking\n (2) Saving\n (3) Fixed Deposit\n");
	printf("Please Make A Selection: ");
	scanf("%d", &choice);
	while (choice!=1 && choice!=2 && choice !=3) {
		printf("Incorrect Choice.");
		printf("Bank Account Type");
		printf("\n (1) Checking\n (2) Saving\n (3) Fixed Deposit\n");
		printf("Please Make A Selection: ");
		scanf("%d", &choice);
	}
	printf("Enter A Year: ");
	scanf("%d", &year);
	while (year<=0 || year>10) {
		printf("Number should be between 1-10.\n");
		printf("Enter a year: ");
		scanf("%d", &year);
	}
	printf("Enter the amount: ");
	scanf("%f", &amount);
	while (amount<=0) {
		printf("Incorrect Value. Enter the amount again: ");
		scanf("%f", &amount);
	}
	switch (choice){
		case 1: rate=.01;
break;
		case 2: rate=.03;
break;
		case 3: rate=.07;
break;
		}
	float compound = amount *(1.0+rate,year);
	float total = compound - amount;
	printf("The Total Amount After %d Years Is %.2f\n", year, compound);
	printf("Total Interest Earned On The Amount Is %.2f", total);
	return (0);
}

