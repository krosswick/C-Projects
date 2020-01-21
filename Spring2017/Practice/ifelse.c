#include <stdio.h>

	int main(void)
{
	char name[20];
	int age;

	printf("Hello, my name is Kyle. What is your name?\n");
	scanf("%s", name);	
	
	printf("\nGreat to meet you %s! How old are you?\n", name);
	scanf("%d", &age);

		if(age < 21)
		{
			printf("Sorry no beer for you! =[");
		}	
	
		if(age >= 21)
		{
			printf("Alright!! Youre old enough to drink, lets get sloshed!");
		}

	return 0;
}
