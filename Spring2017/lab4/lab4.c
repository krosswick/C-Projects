//Kyle Rosswick
//klrmt5
//Lab Section L

#include <stdio.h>

int checkError(int);
int checkEven(int);
int checkPrime(int);
int addDigits(int);
void printMizzou(int);

int main(void)
{
	int pNum;
	int pNum2;

	printf("Enter a positive number:");
	scanf("%d", &pNum);

		while(checkError(pNum) == 1){
			printf("\nError! Please enter a positive number larger than zero:");
			scanf("%d", &pNum);
		}

		if(checkEven(pNum) == 1){
			printf("\nThis number is Even.");
		}
		else{
			printf("\nThis number is Odd.");
		}	
	
	int total = addDigits(pNum);
	printf("\nSum of all didgits is %d", total);

	if(checkPrime(pNum) == 1)
		printf("\nThis number is prime.");

	else
		printf("\nThis number is not prime.");

	printf("\nEnter a second number to run Mizzou function! ");
	scanf("%d", &pNum2);
	
	while(pNum2 <= 0 || pNum2 > 35){
		printf("\nEnter a number between 1 and 35: ");
		scanf("%d", &pNum2);
	}

	printMizzou(pNum2);

	return 0;	

}

int checkError (int pNum)
{
	while(pNum <= 0)
		return 1;

	return 0;
}

int checkEven(int pNum)
{
	if((pNum%2) == 0){
	return 1;
	}

	else{
	return 0;
	}
}

int checkPrime(int pNum)
{
	int i;
	int counter = 0;

	for (i = 1; i<=pNum; i++){
		if(pNum % i == 0)
			counter++;
	}
	
	if(counter == 2){	
	return 1;
	}

	return 0;
}

int addDigits (int pNum)
{
	int i;
	int total= 0;
	int digit= 0;
	
	for(i=0; pNum != 0; i++){
		digit = pNum%10;
		total += digit;
		pNum /= 10;
	}
	return total;
}

void printMizzou (int pNum2)
{
	int i;

	for(i=1; i <= pNum2; i++){

		if(i%15 == 0)
			printf("Mizzou ");
		else if(i%5 == 0)
			printf("Zou ");
		else if(i%3 == 0)
			printf("Miz ");
		else
			printf("%d ", i);
	}
	return;
}
