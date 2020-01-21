//Kyle Rosswick
//klrmt5
//Lab section: L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drinkMenu(void);
void displayMenu(void);
int errorCheck(int);
int calculateRandomDiscount(void);
float calculateTax(float);
void displayReceipt(void);

int main(void)
{
	int choice, choice2;
	float total = 0;

	drinkMenu();
	scanf("%d", &choice);
	while(errorCheck(choice) == 0){
		printf("\nError: Invalid Choice! Please select option 1, 2, 3, or 4: ");
		scanf("%d", &choice);
	}
	
	switch(choice){

	case 1: total += 0;
break;
	case 2: total += 1.00;
break;
	case 3: total += 1.50;
break;
	case 4: total += 1.75;
break;
	}

	displayMenu();
	scanf("%d", &choice2);
	while(errorCheck(choice2) == 0){
		printf("\nError: Invalid Choice! Please select option 1, 2, 3, or 4: ");
		scanf("%d", &choice2);
	}
	
	switch(choice2){

	case 1: total += 4.50;
break;
	case 2: total += 3.00;
break;
	case 3: total += 5.00;
break;
	case 4: total +=7.20;
break;
	}

	printf("\n\nThank you for your order! It will be made shortly!\n");
	printf("Subtotal: %.2f", total);

	float tax = calculateTax(total);
	printf("\nTaxes: %.2f", tax);

	float discount = calculateRandomDiscount();
	printf("\nYou get a random discount of %.0f percent on this meal!", discount);
	
	total -= total * (discount / 100);

	printf("\nTotal: %.2f", total);		

	displayReceipt();

	return 0;
}

void drinkMenu(void)
{
	printf("What would you like to drink?\n");
	printf("1. Water: free\n");
	printf("2. Coke: $1.00\n");
	printf("3. Lemonade: $1.50\n");
	printf("4. Chocolate Milk: $1.75\n");
	printf("Select Option:");
	
	return;
}

void displayMenu(void)
{
	printf("\n\n");
	printf("1. Cheese Burger: $4.50\n");
	printf("2. Hotdog: $3.00\n");
	printf("3. Chicken Strpis: $5.00\n");
	printf("4. Fries and Burger Combo: 7.20\n");
	printf("Select Option:");

	return;
}

int errorCheck(int choice)
{
	while(choice < 1 || choice > 4){
		return 0;
	}
	
	return 1;
	
}

int calculateRandomDiscount(void)
{
	int num;

	srand(time(NULL));
	num = (rand() % 25) + 1;
	
	return num; 

}

float calculateTax(float total)
{
	float base = .5;
	float tax;

	if(total >4){
		tax = total * .25 + base;
	}
	else{
		tax = total * .1 + base;
	}
	
	return tax;
}

void displayReceipt(void)
{
	int num;

	srand(time(NULL));
	num = (rand() %100000000);

	printf("\nYour receipt number is: #%d", num);

	return;
}
