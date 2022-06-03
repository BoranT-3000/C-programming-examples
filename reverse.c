#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MSG_LEN 80
#define N 10

bool polindrome_number(int number);
int reverse_number(int* number);
void reverseSentence();
void reverse_char();

//taskkill /F /IM hello_world.exe

int main(void)
{
	/*int num;
	printf("enter the numbers to reversed: ");
	scanf_s("%d", &num);
	printf("Your reversed number is %d", reverse_number(&num));


	bool is_it = polindrome_number(num);
	if (is_it==true)
		printf("woww polindrome %d", num);
	else
		printf("it is not");*/



	int arr[N];
	int* p;
	printf("Enter %d numbers: ", N);
	for (p = arr; p < arr + N; p++)
		scanf_s("%d", p);
	printf("In a reverse order : ");
	for (p = arr + N - 1; p >= arr; p--)
	{
		printf("%d, ", *p);
	}
	printf("\n");




	return 0;
}

int reverse_number(int* number)
{
	int reverse = 0, reaminder;

	while (*number != 0) {
		reaminder = *number % 10;
		reverse = reverse * 10 + reaminder;
		*number = *number / 10;
	}

	return reverse;
}

bool polindrome_number(int number)
{
	bool is_it_polindrome = false;
	int reversed = 0, remainder, original;

	original = number;

	while (number != 0)
	{
		remainder = number % 10;
		reversed = reversed * 10 + remainder;
		number = number / 10;
	}

	if (original == number)
		is_it_polindrome = true;

	return is_it_polindrome;
}

void reverse_char() {
	char msg[MSG_LEN];
	char* p;
	printf("Enter a message");
	for (p = &msg[0]; p < &msg[MSG_LEN]; p++)
	{
		*p = getchar();
		if (*p == "\n")
			break;
	}

	printf("Reversal is:");
	for (p--;p >= &msg[0];p--)
		putchar(*p);
	putchar("\n");
}


void reverseSentence() {
	char c;
	scanf(" %c", &c);
	if (c != '\n') {
		reverseSentence();
		printf("%c", c);
	}
}