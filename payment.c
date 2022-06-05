#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void pay_amout(int dollars, int* twenties, int* hundreds,int * fiftys,int * tens,int *fives,int *ones);
void ask_for_amount(int* amount);

int main() 
{

	char answ;
	do {
		int amount;
		printf("Enter a dollar amount:");
		scanf_s("%d", &amount);
		ask_for_amount(&amount);
		printf("do you want to continue (Y/N)\n");
		printf("--> ");
		scanf_s(" %c", &answ);
	} while (answ == 'Y'|| answ == 'y');
	

	return 0;
}


void ask_for_amount(int*amount)
{
	int  hundreds,fiftys,twenties, tens, fives, ones;
	
	pay_amout(*amount, &hundreds,&fiftys,&twenties, &tens, &fives, &ones);
	printf("\n");

	printf("$100 bills: %d\n", hundreds);
	printf("$50 bills: %d\n", fiftys);
	printf("$20 bills: %d\n", twenties);
	printf("$10 bills: %d\n", tens);
	printf("$5 bills: %d\n", fives);
	printf("$1 bills: %d\n", ones);
}

void pay_amout(int dollars, int* hundreds, int* fiftys, int* twenties, int* tens, int* fives, int* ones)
{
	*hundreds = dollars / 100;
	dollars = dollars - *hundreds * 100;

	*fiftys = dollars / 50;
	dollars = dollars - *fiftys * 50;

	*twenties = dollars / 20;
	dollars = dollars - *twenties * 20;

	*tens = dollars / 10;
	dollars = dollars - *tens * 10;

	*fives = dollars / 5;
	*ones = dollars % 5;
}