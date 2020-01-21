#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i;

	srand(time(NULL));
	int kyle[5]={0};

	for(i=0; i<5; i++){

		kyle[5] = {(rand() % 9) + 1};
		printf("%d ", kyle[i]);
	}

	return 0;

}
