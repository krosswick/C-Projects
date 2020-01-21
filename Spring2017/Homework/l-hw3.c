//NAME: Kyle Rosswick
//PAW PRINT: klrmt5
//LAB SECTION: L
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool load_data(char*, int*, double*, char*, int);
void print_data(int*, double*, char*, int);
int highest_amount(double *, int);
int lowest_amount(double *, int);
float average_amount(double *, int);
bool write_data(char *, int *,double *, char *, int);
int check_palindrome(int);
int clean_data(int *, double *, char *, int *, double *, char *, int);

int main(int argc, char* argv[])
{

	if(argc != 5){
		printf("\nError: Incorrect number of command line arguments.");
		return 0;
	}

	int size = atoi(argv[1]);
	int *ptr = malloc(sizeof(int)*size);

	int accID = atoi(argv[1]);
	int *acPtr = malloc(sizeof(int)*accID);
	int *vAccPtr = malloc(sizeof(int)*accID);

	double amt = atoi(argv[1]);
	double *amPtr = malloc(sizeof(double)*amt);
	double *vAmPtr = malloc(sizeof(double)*amt);

	int desi = atoi(argv[1]);
	char *dPtr = malloc(sizeof(char)*desi);
	char *vDPtr = malloc(sizeof(char)*desi);

	if(ptr == NULL){
		printf("Error: Pointer is null.");
	}

	int load = load_data(argv[2], acPtr, amPtr, dPtr, size);
	if(load == 0){
		printf("\nError");
		return 0;
	}	
	printf("Account\t Amount\t    Designation\n");
	print_data(acPtr, amPtr, dPtr, size);	

	double high = highest_amount(amPtr, size);
	printf("\nThe highest amount is %.2f", high);

	double min = lowest_amount(amPtr, size);
	printf("\nThe lowest amount is %.2f", min);

	double avg = average_amount(amPtr, size);
	printf("\nThe average amount is %.2f", avg);

	int x = write_data(argv[3], acPtr, amPtr, dPtr, size);
	if(x == 0){
		printf("\nError.");
	}

	printf("\n\nData from hw3Input.txt is now being written to hw3BadOutput.txt...\n");

	/*int e = 700;
	int f = check_palindrome(e);
	if(f == 1){
		printf("%d is a palindrome.", e);
	}*/
	
	clean_data(acPtr, amPtr, dPtr, vAccPtr, vAmPtr, vDPtr, size);

	printf("\n**********DATA AFTER CLEANING**********\n");
	printf("Account\t Amount\t    Designation\n");
	print_data(vAccPtr, vAmPtr, vDPtr, size);	



	return 0;

}

bool load_data(char *inputFile, int *account, double *amount, char *desi, int size)
{
	FILE *fPtr = fopen(inputFile, "r");
	int i;

	if(fPtr == NULL){
		printf("\nError: Can not open file.");
		return false;
	}

	for(i=0; i<size; i++){
		fscanf(fPtr ,"%d %lf %c", (account + i), (amount + i), (desi + i));
	}
	
	fclose(fPtr);

	return true;
}

void print_data(int *account, double *amount, char *desi, int size)
{
	int i;

	for(i=0; i<size; i++){
		printf("%5d\t %.2lf\t %c\n", *(account + i), *(amount + i), *(desi + i));
	}

	return;	
}

int highest_amount(double *ptr, int size)
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

int lowest_amount(double *ptr, int size)
{
	int i;
	int min = *(ptr);

	for(i=0; i< size; i++){

		if(min > *(ptr + i)){
			min = *(ptr + i);
		}
	}

	return min;
}

float average_amount(double *ptr, int size)
{
	float avg = 0;
	float sum = 0;
	int i;

	for(i=0; i<size; i++){
		sum = sum + *(ptr +i );
		avg = sum / size;
	}

	return avg;
}

bool write_data(char *inputFile, int *acc, double *amount, char *desi, int size)
{
	FILE *out = fopen(inputFile, "w");

	int i;

	if(out == NULL){
		printf("\nError. Can not open file.");
		return false;
	}

	for(i=0; i<size; i++){
		fprintf(out, "%5d\t %.2lf\t %c\n", *(acc + i), *(amount + i), *(desi + i));	
	}

	fclose(out);
	return true;
}

int check_palindrome(int num)
{
	int rev = 0;
	int n = num;

	while(num!=0){
		rev = (rev*10) + (num%10);
		num /= 10;
	}

	if(rev == n){
		return 1;
	}

	return 0;
}

int clean_data(int *acc, double *amt, char *desi, int *vAcc, double *vAmt, char *vDesi, int size)
{
	int i;
	int x;
	int store = 0;

	for(i=0; i<size; i++){
	
	x = check_palindrome(*acc);	

		if(x == 1 && *amt <= 5000 && *desi != 'P'){
			*(store + vAcc) = *(i+acc);
			*(store + vAmt) = *(i+amt);
			*(store + vDesi) = *(i+desi);
			store++;
		}
		
	}

	return 0;
	
}















