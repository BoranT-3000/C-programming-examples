#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pay_amount(int dollars, int * hundereds,int * fiftys,int* twenties, int* tens, int* fives, int* ones);
void foo();

int main(void)
{
	char my_choice;

	do {
		eyyy_dolar_sen_kimsin_ya();
		printf("Do you want to play again? (Y/N) -> ");
		scanf(" %c", &my_choice);
		printf("\n");
	} while (my_choice == 'y' || my_choice == 'Y');

	return 0;
}

void eyyy_dolar_sen_kimsin_ya() {
	int amount, hundereds, fiftys, twenties, tens, fives, ones;

	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	pay_amount(amount, &hundereds, &fiftys, &twenties, &tens, &fives, &ones);

	printf("\n");   /* blank line */
	printf(" \t---------------------------------\n");
	printf(" \t\t$100 bills: %d\n", hundereds);
	printf(" \t\t$50 bills: %d\n", fiftys);
	printf(" \t\t$20 bills: %d\n", twenties);
	printf(" \t\t$10 bills: %d\n", tens);
	printf(" \t\t$5 bills: %d\n", fives);
	printf(" \t\t$1 bills: %d\n", ones);
	printf(" \t---------------------------------\n\n");
}


void pay_amount(int dollars, int* hundereds, int* fiftys, int* twenties, int* tens, int* fives, int* ones)
{
	*hundereds = dollars / 100;
	dollars -= *hundereds * 100;

	*fiftys = dollars / 50;
	dollars -= *fiftys * 50;

	*twenties = dollars / 20;
	dollars -= *twenties * 20;

	*tens = dollars / 10;
	dollars -= *tens * 10;

	*fives = dollars / 5;
	*ones = dollars % 5;
}