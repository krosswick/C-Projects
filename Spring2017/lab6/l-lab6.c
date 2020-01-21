//Kyle Rosswick
//Paw Print: klrmt5
//Lab Section: L
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50

int check_error(int);
void initialize_array(int[], int);
void print_array(int[], int);
int max(int[], int);
float average(int[], int);
int count_numbers(int[], int, int);

int main (void)
{
	int array1[MAX]={0};
	int array2[MAX]={0};
	int size;
	int count;
	srand(time(NULL));

	printf("\nEnter the size of the input: ");
	scanf("%d", &size);
	check_error(size);
	
	while(check_error(size) == 1){
		printf("\nError: Invalid input. Please enter the size 1-50: ");
		scanf("%d", &size);
	}

	initialize_array(array1, size);
	printf("\nInput array 1:\n");
	print_array(array1, size);
	printf("\nThe maximum number is present at the index location %d in the array.\n", max(array1, size));
	printf("The average of the numbers for array 1 is %.2f\n\n", average(array1, size));

	initialize_array(array2, size);
	printf("\nInput array 2:\n");
	print_array(array2, size);
	printf("\nThe maximum number is present at the index location %d int the array.\n", max(array2, size));
	printf("The average of the numbers for array 1 is %.2f\n\n", average(array2, size));
	
	printf("Enter a number: ");
	scanf("%d", &count);
	printf("The count of %ds in the first array is %d\n\n", count, count_numbers(array1, size, count));
	printf("The count of %ds in the second array is %d\n", count, count_numbers(array2, size, count));

	printf("\n");	

	return 0;

}

int check_error(int check)
{
	while(check < 1 || check > 50){
		return 1;
	}

	return 0;
}

void initialize_array(int arr[], int num)
{	
	int i = 0;
	
	for(i=0; i<num; i++){
		arr[i] = (rand() % 9) +1;
	}

	return;
}

void print_array(int arr[], int num)
{
	int i;

	for(i=0; i<num; i++){
		printf("%d ", arr[i]);
	}

	return;
}

int max(int arr[], int num)
{
	int i;
	int max = 0;
	int index = 0;

	for(i=0; i<num; i++){

		if(max < arr[i]){
			max = arr[i];
			index = i;
		}
	}
	return index;
}

float average(int arr[], int num)
{
	int i;
	float avg = 0;

	for(i=0; i<num; i++){
		avg += arr[i];	
	}
	
	avg = avg / num;

	return avg;
		
}

int count_numbers(int arr[], int num, int value)
{
	int i;
	int count = 0;

	for(i=0; i<num; i++){
		
		if(arr[i] == value){
			count++;
		}
	}	

	return count;
}
