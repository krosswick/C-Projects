//Kyle Rosswick
//Nicolle Lenzmeier
//PawPrint: klrmt5

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 13

void display_menu();
int error_check(int);
void shuffle(int[]);
//void printarray(int[]);
int draw_card(int[]);
int lucky_seven(int);
int high_card(int, int);
double calculate_winnings(int, int, double);

int main(void)
{
	srand(time(NULL));
	
	int choice, bet;
	int deck[SIZE];
	int userCard = 0;
	int compCard = 0;
	int win = 1;
	int lose = 0;
	int wallet = 100;

	printf("\n\nWelcome to the Guilliams Casino!\n\n");

	do{
	display_menu();
	printf("\nSelect and option:");
	scanf("%d", &choice);

	error_check(choice);
	while(error_check(choice) == 0){
		printf("\nError: Invalid selection. Please choose option 1, 2, or 3.\n");
		printf("Please Select an option:");
		scanf("%d", &choice);
	}

	shuffle(deck);

	userCard = draw_card(deck);

	
	if(choice == 1){
		printf("\n\n***Lucky Seven***");
		printf("\n\nHow much do you want to bet? $");
		scanf("%d", &bet);
		while(bet > wallet){
			printf("\nYou only have $%d. How much do you want to bet? $", wallet);
			scanf("%d", &bet);
		}
		printf("\n\nYou drew %d", userCard);

			if(lucky_seven(userCard) == 1){
				printf("\n\nNice job, you win!");
				printf("\n\nYou now have $%.2f\n\n", wallet + calculate_winnings(choice, win, bet));
				wallet += calculate_winnings(choice, win, bet);
			}

			else{
				printf("\n\nSorry, you lost your bet");
				printf("\n\nYou now have $%.2f\n\n", wallet - calculate_winnings(choice, lose, bet));
				wallet -= calculate_winnings(choice, lose, bet);
		}	
	}
	
	shuffle(deck);

	compCard = draw_card(deck);

	if(choice == 2){
		printf("\n\n***High Card***");
		printf("\n\nHow much do you want to bet? $");
		scanf("%d", &bet);
		while(bet > wallet){
			printf("You only have $%d. How much do you want to bet? $", wallet);
			scanf("%d", &bet);
		}
		printf("\n\nYou drew %d, the Dealer drew %d.", userCard, compCard);
	
			if(high_card(userCard, compCard) == win){
				printf("\n\nNice job, you win!");
				printf("\n\nYou now have $%.2f\n\n", wallet + calculate_winnings(choice, win, bet));
				wallet += calculate_winnings(choice, win, bet);
			}
	
			else{
				printf("\n\nSorry, you lost your bet.");
				printf("\n\nYou now have $%.2f\n\n", wallet - calculate_winnings(choice, lose, bet));
				wallet -= calculate_winnings(choice, lose, bet);
			}
	}

	if(choice == 3){
		printf("\n\nThanks for coming to the Guilliams Casino! Have a good day.");
	}

	if(wallet == 0){
		printf("\n\nYou're out of money and have been kicked out of the casino.\nBe more careful with your money next time.");
	}
	}
	while(choice != 3 && wallet != 0);

	
	//printarray(deck);

	return 0;
}

void display_menu()
{
	printf("\nWhich game do you want to play?\n");
	printf("1) Lucky Seven\n");
	printf("2) High Card\n");
	printf("3) Exit\n");
}

int error_check(int check)
{
	while(check < 1 || check > 3){
		return 0;
	}
	
	return 1;

}

void shuffle(int arr[])
{
	int i;

	for(i=1; i<13; i++){
		arr[i] = (rand() % 13) + 1;
	}

	return;

}

/*void printarray(int arr[])
{
	int i;
	
	printf("\n");

	for(i=0; i<13; i++){
		printf("%d ", arr[i]);
	}
	return;
}*/

int draw_card(int arr[])
{
	int i;
	int card = 0;

	for(i=0; i<13; i++){
	
		if(arr[i] != -1){
			card = arr[i];
			arr[i] = -1;
			return card;
		}	
	}	
	
	return 0;	

}
int lucky_seven(int card)
{
	int total = 0;
	int bet = 0;

	while(card == 7){
		total = total + bet * 7;
		return 1;
	}

	while(card != 7){
		total = total - bet;
		return 0;
	}

	return total;
} 


int high_card(int userCard, int compCard)
{
	int total = 0;
	int bet = 0;

	while(userCard > compCard){
		total = total + bet;
		return 1;
	}

	while(userCard < compCard){
		total = total - bet;
		return 0;
	}

	return total;
}

double calculate_winnings(int choice, int wol, double bet)
{

	double total;

	if(choice == 1){
		if(wol ==1){

			total = bet * 7;
		}
		else{
			total = bet;
		}
	}

	if(choice == 2){
		if(wol == 1){
			total = bet;
		}
		else{
			total = bet;
		}
	}
	
	return total;
}
