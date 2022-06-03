#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10 


void selection_sort(int array[], char s_order);
void swap(int* first, int* second);
void display_array(int array[]);

int main()
{
	int my_array[LENGTH] = { 12, 36, 27, 8, 77, 43, 22, 58, 60, 85 };
	char sorting_order; 

	printf("The array before sort:\n");
	display_array(my_array); 

	printf("Choose the sorting order (either ascending or descending) (A/D) : "); 
	scanf(" %c", &sorting_order);
	selection_sort(my_array, sorting_order);

	printf("The array after selection sort:\n"); 
	display_array(my_array); 
	return 0;
}


void selection_sort(int array[], char s_order)
{
	int i, j, minormax_id;

	for (i = 0; i < LENGTH - 1; i++) 
	{
		minormax_id = i;
		for (j = i + 1; j < LENGTH; j++) 
			switch (s_order)
			{
			case 'A':
				if (array[j] < array[minormax_id])
					minormax_id = j;
				break;
			case 'D': 
				if (array[j] > array[minormax_id]) 
					minormax_id = j; 
				break;
			}
		swap(&array[minormax_id], &array[i]);
	}
}

void swap(int* first, int* second)
{
	int temp;
	temp = *first;
	*first = *second; 
	*second = temp; 
}

void display_array(int array[])
{
	int i;
	for (i = 0; i < LENGTH; i++) 
		printf("%d\t", array[i]); 
	printf("\n"); 
}