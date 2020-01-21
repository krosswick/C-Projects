#include<stdio.h>

int main (void)
{
	int i;
	for (i = 2; i <=8; i+= 3)
		printf("%d ", i);

	int z= 0, y = 6, x = 3;
	z = x % y;
	printf("\n%d", z);
	return 0;
}
