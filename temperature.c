#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define DAY  7
#define TIME 3
// order to strore total days in arr
#define TOTAL_CELLS (DAY*TIME)

//this is provide by school
void calculate_avg(int temperatures[], int* average);

int main(void)
{
	//this is provide by school
	int temperatures[DAY][TIME] = { { 7, 9, 7},
									{ 11, 12, 7 },
									{ 11, 13, 9 },
									{ 12, 15, 10 },
									{ 13, 16, 12 },
									{ 14, 16, 12 },
									{ 14, 16, 12} };
	
	//declearing variables
	int total_average=0, day_weather_count=0;
	int (*ptr_arr);
	//pointer decleration
	ptr_arr = &temperatures[0][0];

	for (int i = 0; i < TOTAL_CELLS; i++) {
		day_weather_count = day_weather_count + *(ptr_arr + i);
	}

	total_average = day_weather_count / (DAY * TIME);

	printf("The average temperature in April is %d\n",total_average);

	printf("**********************************************\n\n");

	int week = 0;

	for (int i = 0; i < DAY; i++)
	{
		week=i+1;
		calculate_avg(temperatures[i], &week);
	}


	return 0;
}




void calculate_avg(int temperatures[], int* average)
{
	int day = *average;
	*average = 0;
	for (int i = 0; i < TIME; i++)
	{
		*average = *average + temperatures[i];
	}

	printf("The average temperature on the %dst of April is %d\n", day,*average/TIME);
	*average = 0;
}