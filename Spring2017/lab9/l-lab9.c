//Kyle Rosswick
//klrmt5
//lab L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void initialize_array(int *, int);
void print_array(int*, int);
float mean(int*, int);
float median(int*, int);
void sort(int*, int);
//float standard_deviation(int*, int);

int main(void)
{

	srand(time(NULL));
	int size = 0;
	int arr[MAX];
	int *ptr;

	ptr = arr;

	printf("\nEnter the size of the input: ");
	scanf("%d", &size);

	while(size > 100 || size < 1){
		printf("\nEnter a size between 1 and 100.");
		scanf("%d", &size);
	}

	initialize_array(ptr, size);
	printf("Input Array is: ");
	print_array(ptr, size);
	
	printf("\n\n");

	sort(ptr, size);
	printf("Sorted Array is: ");
	print_array(ptr, size);

	printf("Median is %.2f", median(ptr, size));



	return 0;
}

void initialize_array(int *ptr, int size)
{
	int i;
	
	for(i=0; i<size; i++){
		*(ptr + i) = rand()%6;
	}	
			
	return;	
}

void print_array(int *ptr, int size)
{
	int i;

	for(i=0; i<size; i++){
		printf("%d ", *(ptr + i));
	}

	return;
}

float mean(int *ptr, int size)
{
	float iAvg = 0;
	float tAvg = 0;
	int i;

	for(i = 1; i < size; i++){
		iAvg += *(ptr + i);
		tAvg += iAvg/size;
	}

	return tAvg;
}

void sort(int *ptr, int size)
{
	int i, j, temp;

	for(i=0; i< size - 1; i++){
		for(j=0; j<size - i - 1; j++)
		{
			if(*(ptr + j ) > *(ptr + j + 1))
			{
				temp = *(ptr+j);
				*(ptr+j)=*(ptr+j+1);
				*(ptr+j+1)=temp;
			}
		}
	}

	//printf("The sorted array is %d", *ptr);

	return;
}
	
float median(int *ptr, int size)
{
	float medi = 0;

	int middle= 0;

	if((size % 2) == 0){
		middle = (size / 2);
		medi = ((float)*(ptr + middle) + *(ptr+(middle-1))) / 2;
	}

	else{
		middle = (int)(size /2);
		medi = *(ptr + middle);
	}
	
	return medi;

}

/*float standard_deviation(int *ptr, int size)
{
	int i, count, total, mean;
	float std;

	mean(ptr, size);

	for(i=0; i<size; i++){
		total += pow(mean - *(ptr+i));
	}
	
	std = sqrt(total/ (size - 1));

	return std;

	

}*/
