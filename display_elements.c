///Boran Toktay 1900001749
//Write a program(main) that reads list of chemical elementsand then separates the elements.The
//program displays how many elements are there in the given listand lists each element in a line.
//Expected output of the program :
//Enter a list of chemical elements : Hydrogen, Helium, Carbon, Oxygen, Neon, Sodium,
//Magnesium, Calcium
//**********************************************
//There are 8 chemical elements in the list.
//1. chemical element is : Hydrogen
//2. chemical element is : Helium
//3. chemical element is : Carbon
//4. chemical element is : Oxygen
//5. chemical element is : Neon
//6. chemical element is : Sodium
//7. chemical element is : Magnesium
//8. chemical element is : Calcium
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char str[500] = { 0 };
	printf("Enter a list of chemical elements:");
	//inorder to get full char ı used gets func.
	gets(str);
	printf("%s", str);

	printf("\n**********************************************\n");
	//to keep track of the items 
	int index = 1;
	//ı used strtok function which is decleared under stdio.h
	//which is capable of breaking strings into series of parts and splits them with 
	//given parameter such as ","
	char* splitter = strtok(str, ",");
	
	//a null pointer is returned if there are no parameter left to retrieve.
	while (splitter != NULL)
	{
		printf("%d. chemical element is: %s\n", index, splitter);
		splitter = strtok(NULL, ",");
		index = index + 1;
	}


	return 0;
}



