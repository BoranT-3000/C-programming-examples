#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_NUMBER 100


void read_guesses(int secret_number);


int main(void)
{
	char my_choice; 
	int my_secret_love;
	printf("Guess the secret number between 1 and %d.\n", MAX_NUMBER); 
	srand((unsigned)time(NULL));
	do
	{
		my_secret_love = rand() % MAX_NUMBER + 1;
		printf("A new number has been chosen.\n"); 
		read_guesses(my_secret_love);
		printf("Do you want to play again? (Y/N) -> "); 
		scanf(" %c", &my_choice);
		printf("\n"); 
	} while (my_choice == 'y' || my_choice == 'Y');
	return 0;
}


void read_guesses(int secret_number)
{
	int guess, num_guesses = 0;
	for (;;) 
	{
		num_guesses++;
		printf("Enter guess: "); 
		scanf("%d", &guess); 
		if (guess == secret_number) 
		{
			printf("You won in %d quesses!\n\n", num_guesses); 
			return;
		}
		else if (guess < secret_number) 
			printf("Too low; try again.\n");
		else 
			printf("Too high; try again.\n");
	}
}