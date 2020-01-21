//NAME: Kyle Rosswick
//LAB SECTION: L
//PAW PRINT: klrmt5

#include <stdio.h>
#include <stdlib.h>

void initialize_array(int *, int);
void print_array(int *, int);
float mean(int*, int);
int max(int*, int);
int min(int*, int);
int loadNumbers(char*, int*, int);
void reverse(int*, int);
int writeData(char *, int *, int);
int main (int argc, char* argv[])
{
	if(argc != 6){
		printf("\nIncorrect number of command line arguments.");
		return 0;
	}

	int size = atoi(argv[1]);
	int *ptr = malloc(sizeof(int)*size);

	//int arr[MAX];
	//ptr = arr;
	
	if(ptr == NULL){
		printf("\nError. Pointer is null.");
		return 0;
	}

	int l = loadNumbers(argv[2], ptr, size);
	if(l == 0){
		printf("Error.");
		return 0;
	}


	//printf("\n\nEnter the size of the input: ");
	//scanf("%d", &size);

	//error check seg faults
	//while(size < 1 || size > 100){
	//	printf("\nError: The input must be between 1-100.\n");
	//	scanf("%d", &size);
	//}


	//initialize_array(ptr, size);

	printf("\nLoading input1.txt...:  ");

	print_array(ptr, size);
	reverse(ptr, size);

	printf("\nThe mean of the array is: %.2f", mean(ptr, size));

	printf("\n\nThe largest number in the array is: %d", max(ptr, size));

	printf("\n\nThe smallest number in the array is: %d", min(ptr, size));

	printf("\n\nThe reversed array is: ");

	print_array(ptr, size);

	int x = writeData(argv[4], ptr, size);
	if(x==0){
	printf("Error.");
	}

	l = loadNumbers(argv[3], ptr, size);
	if(l == 0){
		printf("Error.");
		return 0;
	}

	printf("\n\nLoading input2.txt...:  ");

	print_array(ptr, size);
	reverse(ptr, size);

	printf("\nThe mean of the array is %.2f", mean(ptr, size));

	printf("\n\nThe largest number in the array is: %d", max(ptr, size));

	printf("\n\nThe smallest number in the array is: %d", min(ptr, size));

	printf("\n\nThe reversed array is: ");
	
	print_array(ptr, size);

	printf("\n\n");

	/*int x = writeData(argv[4], ptr, size);
	if(x==0){
		printf("Error.");
		return 0;
	}*/

	x = writeData(argv[5], ptr, size);
	if(x==0){
		printf("Error.");
		return 0;
	}

	free (ptr);	

	return 0;
}

int writeData(char *fn, int *a, int size)
{
	FILE*out = fopen(fn, "w");

	int i;	

	if(out == NULL){
		return 0;
	}
	
	fprintf(out, "Array is: \n");
	
	for(i=0; i<size; i++){
		fprintf(out," %d ", *(a + i));
	}

	int mx = max(a, size);
	fprintf(out, "\nMax number is: %d\n", mx);

	int mn = min(a, size);
	fprintf(out, "Minimum number is: %d\n", mn);

	float avg = mean(a, size);
	fprintf(out, "Average number is: %.2f\n", avg);

	fclose(out);

	return 1;
}

/*void initialize_array(int *ptr, int size)
{
	int i;

	for(i=0; i<size; i++){
		*(ptr + i) = rand()%5 + 1;
	}
	
	return;
} */

void print_array(int *ptr, int size)
{
	int i;

	for(i=0; i<size; i++){
		printf("%d ", *(ptr + i));
	}	
	
	printf("\n");

	return;
}

float mean(int *ptr, int size)
{
	float avg = 0;
	float sum = 0;
	int i;

	for(i=0; i<size; i++){
		sum = sum + *(ptr + i);
		avg = sum / size;
	}

	if(size == 1){
		return (float)*ptr;
	}

	return avg;
}

int max(int *ptr, int size)
{
	int i;	
	int large = 0;

	for(i=0; i<size; i++){
		
		if(large < *(ptr + i)){
			large = *(ptr + i);
		}
	}

	return large;			
}

int min(int *ptr, int size)
{
	int i;
	int min = *(ptr);

	for(i=0; i<size; i++){

		if(min > *(ptr + i)){
			min = *(ptr + i);
		}
	}

	return min;
}

int loadNumbers(char* fn, int *ptr, int size)
{
	FILE *fPtr = fopen(fn, "r");
	int i;

	if(fPtr == NULL){
		printf("\nError: pointer is set to NULL.");
		return 0;
	}
	
	for(i=0; i<size; i++){
		fscanf(fPtr ,"%d", (ptr + i));
	}
	
	fclose(fPtr);
	return 1;
}

void reverse(int *ptr, int size)
{
	int start = 0;
	int temp;

	while(start < size){
		temp = *(ptr + start);
		*(ptr + start) = *(ptr + size -1);
		*(ptr + size -1) = temp;
		start++;
		size--;
	}
	return;
}
