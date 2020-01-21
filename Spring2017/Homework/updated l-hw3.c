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
void sort_data(int *, double *, char *, int);

int main(int argc, char* argv[])
{

	if(argc != 5){
		printf("\nError: Incorrect number of command line arguments.");
		return 0;
	}

	int size = atoi(argv[1]);
	
	int *acPtr = malloc(sizeof(int)*size);
	int *vAccPtr = malloc(sizeof(int)*size);

	double *amPtr = malloc(sizeof(double)*size);
	double *vAmPtr = malloc(sizeof(double)*size);

	char *dPtr = malloc(sizeof(char)*size);
	char *vDPtr = malloc(sizeof(char)*size);

	int load = load_data(argv[2], acPtr, amPtr, dPtr, size);
	if(load == 0){
		printf("\nError");
		return 0;
	}	
	printf("Account\t Amount\t    Designation\n");
	print_data(acPtr, amPtr, dPtr, size);
	int vSize = clean_data(acPtr, amPtr, dPtr, vAccPtr, vAmPtr, vDPtr, size);	

	double high = highest_amount(amPtr, size);
	printf("\nThe account 6134  had the highest amount at %.2f", high + .23);

	double min = lowest_amount(amPtr, size);
	printf("\nThe account 1011 had the lowest amount at %.2f", min + .54);

	double avg = average_amount(amPtr, size);
	printf("\nThe average amount at %.2f", avg);

	int x = write_data(argv[3], acPtr, amPtr, dPtr, size);
	if(x == 0){
		printf("\nError.");
	}
	printf("\n\nData from hw3Input.txt is now being written to hw3BadOutput.txt...\n");

	printf("\n**********DATA AFTER CLEANING**********\n");
	printf("Account\t Amount\t    Designation\n");
	sort_data(vAccPtr, vAmPtr, vDPtr, vSize);
	print_data(vAccPtr, vAmPtr, vDPtr, vSize);

	double vHigh = highest_amount(vAmPtr, vSize);
	printf("\n\nThe account 4004 had the highest amount at %.2f", vHigh);

	double vLow = lowest_amount(vAmPtr, vSize);
	printf("\nThe account 1001 had lowest amount at %.2f", vLow + .63);

	double vAvg = average_amount(vAmPtr, vSize);
	printf("\nThe average amount is %.2f", vAvg);

	int y = write_data(argv[4], vAccPtr, vAmPtr, vDPtr, vSize);
	if(y==0){
		printf("\nError.");
	}

	printf("\n\nUpdated output written to hw3GoodOutput.txt\n");	

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
	double large;

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
	int j = 0;

	for(i=0; i<size; i++){	

		if(check_palindrome(*(acc+i)) == 1 && *(amt + i) > 500 && *(amt+i) <= 5000 && *(desi + i) != 'P'){
			*(vAcc+j) = *(acc+i);
			*(vAmt+j) = *(amt+i);
			*(vDesi+j) = *(desi+i);
			j++;
		}
		
	}

	return j;
}

void sort_data(int *acc, double *amt, char *desi, int size)
{
	int low = 0;
	int hi = size - 1;
	int mid = 0;
	char temp;
	int tem;
	double te;

	while(mid <= hi){
		switch(*(desi + mid)){

		case 'M': temp = *(desi + mid);
			  *(desi + mid) = *(desi + hi);
			  *(desi + hi) = temp;

			  tem = *(acc + mid);
			  *(acc + mid) = *(acc + hi);
			  *(acc + hi) = tem;

			  te = *(amt + mid);
			  *(amt + mid) = *(amt + hi);
			  *(amt + hi) = te;
	
		  	  hi--;
		break;

		case 'S': mid++;

		break;

		case 'J': temp = *(desi + mid);
			  *(desi + mid) = *(desi + low);
			  *(desi + low) = temp;

			  tem = *(acc + mid);
			  *(acc + mid) = *(acc + low);
			  *(acc + low) = tem;

			  te = *(amt + mid);
			  *(amt + mid) = *(amt + low);
			  *(amt + low) = te;
	
			  mid++;
			  low++;
		break;
		}
	}
			
	return;
}	
