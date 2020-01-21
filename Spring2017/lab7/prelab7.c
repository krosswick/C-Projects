//Kyle Rosswick
//klrmt5
//Lab L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int error_check(int);
void initialize_2Darray(int[][MAX], int);
void print_2Darray(int[][MAX], int);
int findZeros(int arr[][MAX], int size);
int findEvenOdd(int arr[][MAX], int size);
void loadDiagonal(int [][MAX], int, int[MAX]);
void print1DArray(int arr[], int);
void printTranspose(int arr[][MAX], int);

int main(void)
{
	int input;
	int arr[MAX][MAX];
	int darr[MAX];
	int zcount, ecount, ocount;
	srand(time(NULL));

	printf("\nEnter the size of the array:");
	scanf("%d", &input);
	error_check(input);
	while(error_check(input) == 1){
		printf("\nPlease enter a value between 1 and 20:");
		scanf("%d", &input);
	}

	initialize_2Darray(arr, input);
	print_2Darray(arr, input);
	zcount = findZeros(arr, input);
	ecount = findEvenOdd(arr, input);
	ocount = input * input - ecount;

	printf("\n\nThere are %d zero(s) in this 2D array.", zcount);
	printf("\n\nThere are %d even numbers in this 2D array.", ecount);
	printf("\n\nThere are %d odd numbers in this 2D array.", ocount);
	loadDiagonal(arr, input, darr);
	print1DArray(darr, input);
	printf("\n\nTranspose of the 2D array is:\n");
	printTranspose(arr, input);
	


	return 0;
}

int error_check(int check)
{
	while (check < 1 || check > 20){
		return 1;
	}

	return 0;
}

void initialize_2Darray(int arr[MAX][MAX], int size)
{
	int i, j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			arr[i][j]=rand()%10;
		}
	}
	
	return;
}

void print_2Darray(int arr[MAX][MAX], int size)
{
	int i, j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return;
}

int findZeros(int arr[MAX][MAX], int size)
{
	int i, j;
	int zcount = 0;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			if(arr[i][j] == 0){
				zcount++;
			}
		}	
	}

	return zcount;
}

int findEvenOdd(int arr[][MAX], int size)
{
	int i, j;
	int ecount = 0;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			if(arr[i][j] % 2 == 0){
				ecount++;
			}
		}
	}

	return ecount;
}

void loadDiagonal(int arr[][MAX], int size, int darr[MAX])
{
	int i, j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			if(i==j){
				darr[i] = arr[i][j];		
			}
		}
	}		

	return;
}

void print1DArray(int arr[], int num)
{
	int i;

	printf("\n\nThe primary diagonal elements in the 2D array, loaded into 1D array are:");
	for(i=0; i<num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}

void printTranspose(int arr[][MAX], int size)
{
	int i, j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			//arr[j][i] = arr[i][j];
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
}
