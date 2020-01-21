//Kyle Rosswick
//klrmt5
//Lab L
#include <stdio.h>

int main (void)
{

	int  num1, num2, num3;
	float num4;

	printf("\n\nEnter the first number:");
	scanf("%d", &num1);
	
		while(num1<0)
		{
		printf("\n\nNo Negatives Please.\n");
		printf("Enter the first number:");
		scanf("%d", &num1);
		}

	printf("\n\nEnter the second number please:");
	scanf("%d", &num2);

		while(num2<0)
		{
		printf("\n\nNo Negatives Please.\n");
		printf("Enter the second number:");
		scanf("%d", &num2);
		}

	num3 = num2 + num1;
	printf("\n\nAddition: %d + %d = %d\n\n", num1, num2, num3);

	num3 = num1 - num2;
	printf("Subtraction: %d - %d = %d\n\n", num1, num2, num3);
	
	num3 = num1 * num2;
	printf("Multiplication: %d * %d = %d\n\n", num1, num2, num3);

		while(num2 == 0)
		{
		printf("You cant devide by 0!\n\nPlease enter the second number:");
		scanf("%d", &num2);
		}
	
	num4 = (float) num1 / num2;
	printf("Division: %d / %d = %.2f\n\n", num1, num2, num4);

	if(num1 < num2)
	
		printf("%d is smaller than %d\n\n", num1, num2);
	
	else if (num1 > num2)
	{
		printf("%d is bigger than %d\n\n", num1, num2);
	}

	if (num1 == num2)
	
		printf("%d is equal to %d", num1, num2);

	return 0;
}
