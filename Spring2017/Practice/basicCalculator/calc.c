#include <stdio.h>
int main()
{
	float z;
	int a,b,c;
	printf("Enter the first number: ");
	scanf("%d", &a);
	while (a <0) {
		printf("No negitives please.\n");
		printf("Enter first value: ");
		scanf("%d", &a);
	}
	printf("Enter second number: ");
	scanf("%d", &b);
	while (b <0) {
		printf("No negitives please.\n");
		printf("Enter second value. ");
		scanf("%d", &b);
	}
	printf("Addition ");
	c = a + b;
	printf("%d + %d = %d\n", a, b, c);
	printf("Subtraction ");
	c = a - b;
	printf("%d - %d = %d\n", a, b, c);
	printf("Multiplication ");
	c = a * b;
	printf("%d * %d = %d\n", a, b, c);
	printf("Division ");
	z = (float) a / (float) b;
	printf("%d / %d = %f\n", a, b, z);
	if (a>b) {
		printf("%d is greater than %d. ", a, b, c);
	}
	else if (b>a) {
		printf("%d is greater than %d. ", b, a, c);
	}
	return 0;
}

