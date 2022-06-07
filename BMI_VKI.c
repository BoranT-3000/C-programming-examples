#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>


float BMI_Meters(float weight, float height) {
	return weight / (height * height);
}

int main()
{
	char answ;
	float height, weight;
	const float KG = 0.453592;
	float pound, give_take;
	int bmi;

	do {

		printf("Enter height in meter (1.80) : ");
		scanf("%f", &height);

		printf("Enter weight in kg (70.00): ");
		scanf("%f", &weight);

		bmi = weight / (height * height);

		printf("Your Body Mass Index(BMI) is %d\n", bmi);

		if (bmi < 15)
		{
			printf("Your BMI category is: Starvation\n");
			//give_take = 18 * pow(height / 100, 2 - weight);
			//printf("You need to gain %f kilograms", give_take);
			printf("You need to gain weight");
		}
		else if (bmi >= 15 && bmi <= 17)
		{
			printf("Your BMI category is: Anorexic\n");
			//give_take = 18 * pow(height / 100, 2 - weight);
			//printf("You need to gain %f kilograms", give_take);
			printf("You need to gain weight");
		}
		else if (bmi >= 17 && bmi <= 18)
		{
			printf("Your BMI category is: Underweight\n");
			//give_take = 18 * pow(height / 100, 2 - weight);
			//printf("You need to gain %f kilograms", give_take);
			printf("You need to gain weight");

		}
		else if (bmi >= 18 && bmi <= 24)
		{
			printf("Your BMI category is: Ideal\n");
		}
		else if (bmi >= 25 && bmi <= 30)
		{
			printf("Your BMI category is: Overweight\n");
			//give_take = weight - 24 * pow(height / 100, 2);
			//printf("You need to lose %f kilograms\n", give_take);
			printf("You need to lose weight\n");
		}
		else if (bmi >= 30 && bmi <= 39)
		{
			printf("Your BMI category is: Obese\n");
			//give_take = weight - 24 * pow(height / 100, 2);
			//printf("You need to lose %f kilograms\n", give_take);
			printf("You need to lose weight\n");

		}
		else if (bmi >= 40)
		{
			printf("Your BMI category is: Morbidly Obese\n");
			give_take = weight - 24 * pow(height / 100, 2);
			printf("You need to lose weight\n");
		}
		else
		{
			printf("Wrong entry\n");
		}

		//http://u.arizona.edu/~mccann/develop_c.html 
		// for further progress 

		printf("\ncontinue ? (Y/N) \n-->");
		scanf_s(" %c", &answ); 
		printf("\n");

	} while (answ == 'y' || answ == 'Y');

	return 0;
}