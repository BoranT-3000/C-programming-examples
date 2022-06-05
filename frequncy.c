#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 1000 


int char_frequncy(char cpy_str[], char cpy_ch);
void wowel_constant(char c);
void frequncy(char* str);
int read_line(char str[], int n);

int main()
{
	char str[MAX_SIZE];
	char reverse_str[MAX_SIZE];
	int len, i, index = 0, wordStart, wordEnd;
	char my_ch, answ;
	int choice;


	printf("Enter a sentence: ");
	fgets(str, sizeof(str), stdin);

	printf("-----------------------------------\n");
	printf("for one char frequncy     [->] (1)\n");
	printf("for all char frequncy	  [->] (2)\n");
	printf("reverse order of a string [->] (3)\n");
	printf("quit [->] (4)\n");
	printf("[--> ");scanf_s("%d", &choice);

	switch (choice)
	{
	case 1: {
		// ı want to find frequency of a given char.
		printf("\nEnter a char to find frequncy: ");
		scanf_s(" %c", &my_ch);

		int char_count = char_frequncy(str, my_ch);
		printf("Frequency of %c = %d", my_ch, char_count);
		printf("\nand also: ");

		wowel_constant(my_ch);
		break;
	}

	case 2: {

		frequncy(str);
		break;
	}

	case 3: {

		len = strlen(str);

		wordStart = len - 1;
		wordEnd = len - 1;

		while (wordStart > 0)
		{
			if (str[wordStart] == ' ')
			{
				i = wordStart + 1;
				while (i <= wordEnd)
				{
					reverse_str[index] = str[i];
					i++;
					index++;
				}
				reverse_str[index++] = ' ';

				wordEnd = wordStart - 1;
			}

			wordStart--;
		}


		if (index > 0) {

			for (i = 0; i <= wordEnd; i++)
			{
				reverse_str[index] = str[i];
				index++;
			}

			reverse_str[index] = '\0';

			printf("Original string \n%s\n\n", str);
			printf("Reversal of the sentence \n%s", reverse_str);
		}
		else {
			printf("You did not enter a sentence");
		}


	}
		  break;
	case 4:
		exit(1);
		break;
	default:
		printf("you need to select between [1-4]\n");
	}


	return 0;
}

// this is for one char in a string it only finds one of it 
int char_frequncy(char cpy_str[], char ch)
{
	char str[MAX_SIZE];
	int count = 0;

	strcpy(str, cpy_str);

	for (int i = 0; str[i] != '\0'; ++i)
		if (ch == str[i])
			++count;

	return count;
}

// this function for asking is it wovel or a constant 
void wowel_constant(char c)
{
	int lowercase_vowel, uppercase_vowel;

	lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

	uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

	if (lowercase_vowel || uppercase_vowel) {
		printf(" and %c is a vowel\n", c);
	}
	else {
		printf(" and %c is a consonant\n", c);
	}

}

// this function finds each char in a string 
void frequncy(char* str)
{
	int freq[256] = { 0 };

	for (int i = 0; str[i] != '\0'; i++)
	{
		freq[str[i]]++;
	}

	for (int j = 0; j < 256; j++)
	{
		if (freq[j] != 0)
		{
			printf("%c occurs %d Times ", j, freq[j]);
			wowel_constant(j);
		}
	}
}
