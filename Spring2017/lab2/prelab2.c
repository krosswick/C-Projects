//Kyle Rosswick
//klrmt5
//Lab L
#include <stdio.h>

int main (void)
{

	float num1;
	float num2;

	printf("\n\nEnter the first number:");
	scanf("%f", &num1);
	
		while(num1<0)
		{
		printf("\n\nNo Negatives Please.\n");
		printf("Enter the first number:");
		scanf("%f", &num1);
		}

	printf("\n\nEnter the second number please:");
	scanf("%f", &num2);

		while(num2<0)
		{
		printf("\n\nNo Negatives Please.\n");
		printf("Enter the second number:");
		scanf("%f", &num2);
		}

	float num3 = num2 + num1;
	printf("\n\nAddition: %.2f + %.2f = %.2f\n\n", num1, num2, num3);

	num3 = num1 - num2;
	printf("Subtraction: %.2f - %.2f = %.2f\n\n", num1, num2, num3);
	
	num3 = num1 * num2;
	printf("Multiplication: %.2f * %.2f = %.2f\n\n", num1, num2, num3);

	num3 = num1 / num2;
	printf("Division: %.2f / %.2f = %.2f\n\n", num1, num2, num3);
		if(num1 == 0)
		{
			printf("You cant devide by 0!\nEnter new number:");
			scanf("%.2f", num1);
		}

	if(num1 < num2)
	
		printf("%.2f is smaller than %.2f\n\n", num1, num2);
	
	else if (num1 > num2)
	{
		printf("%.2f is bigger than %.2f\n\n", num1, num2);
	}

	if (num1 == num2)
	
		printf("%.2f is equal to %f.2", num1, num2);

	return 0;
}
