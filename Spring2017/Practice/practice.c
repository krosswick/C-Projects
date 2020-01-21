#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char age[20];
	char mel[20];

	printf("Kyle, how old are you?\n");
	scanf("%s", age);

	printf("Mel, how old are you?\n");
	scanf("%s", mel);

	printf("Kyle, you are %s years old and Mel, you are %s years old", age, mel);

	return 0;
}
