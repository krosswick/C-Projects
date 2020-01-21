#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void)
{
	int choice, year;
	float cash, amount, rate;

	printf("\nBank Account Type:\n");
	printf("(1)Checking\n(2)Savings\n(3)Fixed Deposit\nPlease Select a choice:");
	scanf("%d", &choice);

	while(choice < 1 || choice > 3){
		printf("\nIncorrect choice. Please select option 1, 2, or 3:");
		scanf("%d", &choice);
	}

	printf("\nEnter a year:");
	scanf("%d", &year);

	while(year <= 0 || year > 10){
		printf("\nThe year should be between 1 and 10:");
		scanf("%d", &year);
	}

	printf("\nEnter the amount you'd like to deposit:");
	scanf("%f", &amount);
	
	while(amount <= 0){
		printf("\nPlease enter an amount greater than 0:");
		scanf("%f", &amount);
	}

	switch (choice){
		case 1: rate = .05;
break;
		case 2: rate = .1;
break;
		case 3: rate = .15;
break; 
	}

	cash = amount * pow(1 + rate,year);

	printf("The amount after %d year(s) is %.2f", year, cash); 
	
	float total = cash - amount;
	printf("\nThe amount of interest earned on %.2f with a rate of %.2f is %.2f", amount, rate, total); 

	printf("\n\n********Bonus Part********\n");

	int bonusNum, bonusExp;

	printf("Enter a number:");
	bonusNum = 0;
	scanf("%d", &bonusNum);

	printf("Enter an exponent:");
	bonusExp = 0;
	scanf("%d", &bonusExp);
	
	float bonusAnswer = pow(bonusNum, bonusExp);
	printf("pow(%d, %d) = %.6f", bonusNum, bonusExp, bonusAnswer);
	//bonusAnswer = pow(bonusNum, bonusExp);

	return 0;
}
