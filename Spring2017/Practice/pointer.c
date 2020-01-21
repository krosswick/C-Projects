//Quiz 9 CS1050

#include <stdio.h>

int main(void)
{
	int a, b;
	int *aPtr;

	a = 8;
	
	printf("\n%p", &a);

	aPtr = &a;

	printf("\n%d", *aPtr);
	printf("\n%p", aPtr);
	b = *aPtr;
	printf("\n%d", b);
	printf("\n%p", &b);
	printf("\n%d", 2* *aPtr);
	printf("\n%p", &aPtr);

	return 0;
}
