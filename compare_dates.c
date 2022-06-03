#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>



typedef struct Years {
	int year;
	int month;
	int day;
}Year[2];

int compare_dates(Year year1, Year year2);

void month_names(int month);

const char* month_name(int month);

const char* day_of_week(int year, int month, int day);

int main(void)
{
	Year year1;
	Year year2;
	
	char month1[50], month2[50];
	char day1[20], day2[20];
	int my_choice;

	printf("choose how you use time\n 1-(dd/mm/yy)\n 2-(mm/dd/yy)\n\t|-->");
	scanf("%d",&my_choice);

	if (my_choice<1 || my_choice>2)
		my_choice == 1;

	if (my_choice==1)
	{
		printf("Enter first date (dd/mm/yy) : ");
		scanf("%d/%d/%d", &year1[0].day, &year1[0].month, &year1[0].year);


		printf("Enter second date (dd/mm/yy) : ");
		scanf("%d/%d/%d", &year2[0].day, &year2[0].month, &year2[0].year);


		//to get month name
		strcpy(month1, month_name(year1[0].month));
		//to get week of the day name
		strcpy(day1, day_of_week(year1[0].day, year1[0].month, year1[0].year));

		printf("first date:  %02d/%02d/%d\n", year1[0].day, year1[0].month, year1[0].year);
		printf("first date:  %02d/%s/%d\n", year1[0].day, month1, year1[0].year);
		printf("first date:  %s/%s/%d\n", day1, month1, year1[0].year);


		//to get month name
		strcpy(month2, month_name(year2[0].month));
		//to get week of the day name
		strcpy(day2, day_of_week(year2[0].day, year2[0].month, year2[0].year));

		printf("second date: %02d/%02d/%d\n", year2[0].day, year2[0].month, year2[0].year);
		printf("second date: %02d/%s/%d\n", year2[0].day, month2, year2[0].year);
		printf("second date: %s/%s/%d\n", day2, month2, year2[0].year);



	}
	else if (my_choice == 1) {

		printf("Enter first date (mm/dd/yy) :");
		scanf("%d/%d/%d", &year1[0].month, &year1[0].day, &year1[0].year);


		printf("Enter second date (mm/dd/yy) : ");
		scanf("%d/%d/%d", &year2[0].month, &year2[0].day, &year2[0].year);



		printf("first date:  %02d/%02d/%d\n", year1[0].month, year1[0].day, year1[0].year);

		printf("second date: %02d/%02d/%d\n", year2[0].month, year2[0].day, year2[0].year);

	}


	int compare_years = compare_dates(year1,year2);
	
	if (compare_years == -1) {
		printf("d1 is an earlier date than d2\n");
		printf("%02d/%02d/%d is an earlier date than %02d/%02d/%d", year1[0].day, year1[0].month, year1[0].year
			, year2[0].day, year2[0].month, year2[0].year);
	
	}
	else if (compare_years==1) {
		printf("d1 is later date than d2\n");
		printf("%02d/%02d/%d is later date than %02d/%02d/%d", year1[0].day, year1[0].month, year1[0].year
			, year2[0].day, year2[0].month, year2[0].year);
	}
	else {
		printf("d1 and d2 are the same\n");
		printf("%02d/%02d/%d and %02d/%02d/%d are the same", year1[0].day, year1[0].month, year1[0].year
		, year2[0].day, year2[0].month, year2[0].year);
	}
	

	return 0;
}


int compare_dates(Year year1, Year year2)
{
	int return_item;
	if (year1->year > year2->year) {
		printf("second  year is bigger\n");
		return_item = 1;
	}
	else if (year1->year < year2->year) {
		printf("first year is bigger\n");
		return_item = -1;
	}
	else {
		printf("same years\n");
		if (year1->month > year2->month) {
			printf("second  year is bigger\n");
			return_item = 1;
		}
		else if (year1->month < year2->month) {
			printf("first year is bigger\n");
			return_item = -1;
		}
		else {
			printf("same month\n");
			if (year1->day > year2->day) {
				printf("second  year is bigger\n");
				return_item = 1;
			}
			else if (year1->day < year2->day) {
				printf("first year is bigger\n");
				return_item = -1;
			}
			else {
				printf("same day\nAre you sure that you are not twins ?");
				return_item =  0;
			}
		}
	}
	return return_item;
}

const char* day_of_week(int day, int month, int year) {
	/* using C99 compound literals in a single line: notice the splicing */
	return ((const char* [])                                         \
	{"Monday", "Tuesday", "Wednesday", \
		"Thursday", "Friday", "Saturday", "Sunday"})[\
		(\
			day                                                      \
			+ ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) \
			+ (365 * (year + 4800 - ((14 - month) / 12)))              \
			+ ((year + 4800 - ((14 - month) / 12)) / 4)                \
			- ((year + 4800 - ((14 - month) / 12)) / 100)              \
			+ ((year + 4800 - ((14 - month) / 12)) / 400)              \
			- 32045                                                    \
			) % 7];
}

void month_names(int month)
{
	switch (month)
	{
	case 1:
		printf("January");
		break;
	case 2:
		printf("February");
		break;
	case 3:
		printf("March");
		break;
	case 4:
		printf("April");
		break;
	case 5:
		printf("May");
		break;
	case 6:
		printf("June");
		break;
	case 7:
		printf("July");
		break;
	case 8:
		printf("Augugst");
		break;
	case 9:
		printf("September");
		break;
	case 10:
		printf("October");
		break;
	case 11:
		printf("November");
		break;
	case 12:
		printf("December");
		break;
	default:
		printf("you entered out of the bound\n it should be 1-12");
		break;
	}
}

const char* month_name(int month)
{
	char ch_month[30];
	switch (month)
	{
	case 1:
		strcpy(ch_month, "January");
		break;
	case 2:
		strcpy(ch_month, "February");
		break;
	case 3:
		strcpy(ch_month, "March");
		break;
	case 4:
		strcpy(ch_month, "April");
		break;
	case 5:
		strcpy(ch_month, "May");
		break;
	case 6:
		strcpy(ch_month, "June");
		break;
	case 7:
		strcpy(ch_month, "July");
		break;
	case 8:
		strcpy(ch_month, "August");
		break;
	case 9:
		strcpy(ch_month, "September");
		break;
	case 10:
		strcpy(ch_month, "October");
		break;
	case 11:
		strcpy(ch_month, "November");
		break;
	case 12:
		strcpy(ch_month, "December");
		break;
	default:
		strcpy(ch_month, "there is no such a month");
		break;
	}

	return ch_month;
}