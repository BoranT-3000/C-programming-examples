#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

bool is_palindrome(const char* message);

int main(void) {

	char str[100];
	printf("enter a sentence: ");
	scanf("%s",str);

	if (is_palindrome(str))
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");

	return 0;
}


bool is_palindrome(const char* message)
{
	char* p = message + strlen(message) - 1;

	while (p > message)
	{
		while (message < p && !isalpha(*message))message++;
		while (p > message && !isalpha(*p))p--;
		if (toupper(*message++) != toupper(*p--))
			return false;
	}

	return true;
}