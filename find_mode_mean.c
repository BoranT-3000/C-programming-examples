/**** find_mode_mean.c ****/
/****finds the mode of array and calculates both arithmetic and harmonic mean.****/

/**** header files ****/
#include <stdio.h> 
#define _CRT_SECURE_NO_WARNINGS


int find_mode(int array[], int size);
void calculate_arithmetic_mean(int array[], int size, float* a_mean);
void calculate_harmonic_mean(int array[], int size, float* h_mean);
void print_array(int array[], int size);


int main()
{
	int my_array[30] = { 32, 32, 32, 32, 32, 34, 32, 26, 28, 28, 29, 31, 24, 27, 25, 27, 28, 30, 29, 29, 29, 31, 32, 31, 29, 31, 31, 31, 35, 33 }; // one-dimensional array
	int my_2Darray[3][5] = { {4, 4, 82, 34, 56}, {5, 34, 76, 90, 76}, {2, 6, 1, 2, 45} }; // two-dimensional array
	float arithmetic_mean, harmonic_mean;

	printf("\n***One-dimensional array***\n");
	printArray(my_array, 30);
	printf("The mode of array is %d\n", find_mode(my_array, 30));

	calculate_arithmetic_mean(my_array, 30, &arithmetic_mean);
	printf("The arithmetic mean of array is %f \n", arithmetic_mean);

	calculate_harmonic_mean(my_array, 30, &harmonic_mean);
	printf("The harmonic mean of array is %f \n", harmonic_mean);

	printf("\n***Multidimensional array***\n");
	printArray(my_2Darray[0], 5); 
	printArray(my_2Darray[1], 5);
	printArray(my_2Darray[2], 5); 

	printf("The mode of the first row of the 2D array is %d\n", find_mode(my_2Darray[0], 5)); // the mode of the first row

	calculate_arithmetic_mean(my_2Darray[0], 5, &arithmetic_mean); // the arithmetic mean of the first row
	printf("The arithmetic mean of the first row of the 2D array is %f \n", arithmetic_mean);

	calculate_harmonic_mean(my_2Darray[0], 5, &harmonic_mean); // the harmonic mean of the first row
	printf("The harmonic mean of the first row of the 2D array is %f \n", harmonic_mean);

	return 0;
}

int find_mode(int array[], int size)
{
	int i, j, element_count = 0, max_count = 0, mode = 0;

	for (i = 0; i < size; i++)
	{
		element_count = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
				element_count++;
		}
		if (element_count > max_count)
		{
			max_count = element_count;
			mode = array[i];
		}
	}
	return mode;
}


void calculate_arithmetic_mean(int array[], int size, float* a_mean)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	*a_mean = sum / size;
}


void calculate_harmonic_mean(int array[], int size, float* h_mean)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += 1.0f / array[i];
	*h_mean = size / sum;
}


void print_array(int array[], int size)
{
	int* ptr;
	for (ptr = array; ptr< array + size; ptr++) 
		printf("%d\t", *ptr);
	printf("\n");
}