//Kyle Rosswick
//klrmt5
//Lab1
//Section L

#include <stdio.h>

int main (void)
{
	float dist;
	float speed;

	printf("\n\n\n\n    Hello world!\n\n");

	printf("*****Bonus part*****\n\n");

	printf(" Enter the distance:");
	scanf("%f", &dist);

		while (dist<0)
		{
			printf("\nDistance should be a positive number.\n\n");
			printf("Enter the distance:");
			scanf("%f", &dist);
		}

	printf("\n\nEnter the speed:");
	scanf("%f", &speed);

		while(speed<0)
		{
			printf("\nSpeed should be a positive number.");
			printf("\n\nEnter the speed:");
			scanf("%f", &speed);
		}

	float time = dist / speed;

	printf("\n\nFlight time of the plane is %f seconds!", time);			
	
	
	return 0;
}
