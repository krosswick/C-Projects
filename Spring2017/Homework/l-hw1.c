#include <stdio.h>

int main ()
{
	int choice, kWh, charge, restart;
	int numofbills = 0;
	float rate, total, amount;
	float billtotal = 0;
	
	do 
	{

	printf("***** ELECTRICITY BILL CALCULATOR *****\n");
	printf("\n\n1. Residential\n2. Commercial\n3. Industrial");
	printf("\n\nChoose the type of connection you have:");
	scanf("%d", &choice);

		while(choice != 1 && choice != 2 && choice != 3)
		{
			printf("\nInvalid Choice! Please Enter 1, 2, or 3 depending on your plan.\n");
			printf("\n 1. Residential\n 2. Commercial\n 3. Industrial\n");
			printf("\nChoose the type of connection you have:");
			scanf("%d", &choice);
		}

	printf("\nEnter the number of units (in kWh):");
	scanf("%d", &kWh);

		while (kWh < 0)
		{
			printf("\nThe number should be positive.\n");
			printf("Enter the number of units in kWh:");
			scanf("%d", &kWh);
		}
	
	switch (choice) 
	{
		case 1: if (kWh > 0 && kWh <= 300)
			rate = .075;
			if (kWh > 300 && kWh <= 750)
			rate = .1;
			if (kWh > 750 && kWh <= 1500)
			rate = .135;
			if (kWh > 1500)
			rate = .15;
	break;
		case 2: if (kWh > 0 && kWh <= 300)
			rate = .105;
			if (kWh > 300 && kWh <= 750)
			rate = .14;
			if (kWh > 750 && kWh <= 1500)
			rate = .175;
			if (kWh > 1500)
			rate = .2;
	break;
		case 3: if (kWh > 0 && kWh <= 300)
			rate = .365;
			if (kWh > 300 && kWh <= 750)
			rate = .4;
			if (kWh > 750 && kWh <= 1500)
			rate = .455;
			if (kWh > 1500)
			rate = .5;
	break;
	}
	
	amount = rate * kWh;
	printf("Total energy charge for the customer is $%.2f\n", amount);
		if (choice == 1)
			charge = 25;
		if (choice == 2)
			charge = 90;
		if (choice == 3)
			charge = 850;
	total = amount + charge;
	printf("Total bill due from this connection is: $%.2f\n", total);
	printf("Do you want to continue and calculate another bill? If yes, enter 1. If not, enter 0:");
	scanf("%d", &restart);
	numofbills++;
	billtotal += total;
	
		while (restart != 1 && restart !=0)
		{
			printf("\nYou have to choose 1 to calculate again or 0 to quit:");
			scanf("%d", &restart);
		}
	}
	while (restart == 1);
	printf("\nYou calculated the bill %d times and the total amount from all the bills due is $%.2f", numofbills, billtotal);

	printf("\n\nExiting Electricity Bill Calculator...");	
	printf("\n\n***Bonus Part***\n\n");

	int bonusNum;
	int i;
	int sum = 0;

	printf("\n\nEnter a number:");
	scanf("%d", &bonusNum);
	while(bonusNum < 0)
	{
		printf("\nPositive numbers only!");
		printf("\nEnter a number:");
		scanf("%d", &bonusNum);
	}


	printf("\nThe numbers are: ");
		for(i=0; i<= bonusNum; i++)
		{
			printf("%d ", i);
		}


	for(i=0; i <= bonusNum; ++i)
	{
		sum += i;
	}
	printf("\n\nThe sum of all numbers from 0 to %d is %d\n\n", bonusNum, sum);

	
	sum = 0;
	for(i=0; i<= bonusNum; i +=2)
	{
		sum += i;
	}
	printf("The sum of the even numers is:%d", sum);

	sum = 0;
	for(i=0; i<= bonusNum; i++)
	{
		if(i % 2 == 1)
		{
			sum += i;
		}
	}
	printf("\n\nThe sum of the odd numbers is:%d", sum);

	return (0);
}







