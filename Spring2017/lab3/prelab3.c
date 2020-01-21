#include <stdio.h>
#include <math.h>

int main (void)
{
	int choice, length;
	float area = 0;
	
	printf("Area calculation\n1.)Square\n2.)Cube\n3.)Circle\nPlease select a choice:");
	scanf("%d", &choice);

	while(choice < 1 || choice > 3){
		printf("\nIncorrect choice. Please select option 1, 2, or 3:");
		scanf("%d", &choice);
	}
	
	printf("\nEnter a positive number:");
	scanf("%d", &length);

	while(length <= 0){
		printf("\nOnly positive numbers will be accepted. Re-enter a positive number:");
		scanf("%d", &length);
	}

	switch(choice){
		case 1: area = length * length;
		printf("\nThe length of the side of the square is %d", length);
		printf("\nArea of the Square is %.2f\n", area);
break;
		case 2: area = 6 *length *length;
		printf("\nThe length of the side of the cube is %d", length);
		printf("\nArea of the Cube is %.2f\n", area);
break;
		case 3: area = 3.14159 * length * length;
		printf("\nThe length of the circle is %d", length);
		printf("\nArea of the Circle is %.2f\n", area);
break;
	}

	return 0;
}
