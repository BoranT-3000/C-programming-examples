// this program was first program that ı wrote in c as a homework
// A university wants to use a student ID system that shows:
//- The year student registered the university
//- Faculty of student
//- Department of student
//- An extra number to make each student ID unique
//So, the designed number of the system is following example : 1701020049


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, faculty_number, department_number, student_number;
	char answer;
	do{

		printf("enter your student number:");
		scanf_s("%2d%2d%2d%4d", &year, &faculty_number, &department_number, &student_number);
		printf("year :20%d\n", year);
		printf("faculty: ");
		
		switch (faculty_number)
		{

		case 1:
			printf("faculty of engineering\n");
			switch (department_number)
			{
			case 1:
				printf("department: ındusturial engineering \n");
				break;

			case 2:
				printf("department : computer engineering \n");
				break;

			case 3:
				printf("department: civil engineering(turkish)\n");
				break;

			case 4:
				printf("department: civil engineering(english)\n");
				break;

			case 5:
				printf("department: electirical-electronic engineering\n");
				break;
			}
			break;

		case 2:
			printf("Faculty of Science and Letters\n");
			switch (department_number)
			{
			case 1:
				printf("mathemeticks and computer science\n");
				break;

			case 2:
				printf("english langueage and literature\n ");
				break;

			case 3:
				printf("turkish language and literature\n");
				break;

			case 4:
				printf("physics\n");
				break;

			case 5:
				printf("molecular biology and genetics\n");
				break;

			case 6:
				printf("psychology\n");

			}
			break;

		case 3:
			printf("Faculty of Law\n");
			switch (department_number)
			{
			case 1:
				printf("private law \n");
				break;

			case 2:
				printf("public law\n");
				break;

			}
			break;

		case 4:
			printf("Faculty of Education\n");
			switch (department_number)
			{
			case 1:
				printf("department of educational Sciences\n");
				break;

			case 2:
				printf("department of foreign language education\n");
				break;

			case 3:
				printf("department of elemantry education\n");
				break;

			}
			break;

		case 5:
			printf("Faculty of Economic and Administrative\n");
			switch (department_number)
			{
			case 1:
				printf("economics\n");
				break;

			case 2:
				printf("business Administration (turkish)\n");
				break;

			case 3:
				printf("business Administration(english)\n");
				break;

			case 4:
				printf("international relations\n");
				break;

			case 5:
				printf("international trade(turkish)\n");
				break;

			case 6:
				printf("international trade(english)\n");
				break;

			case 7:
				printf("entrepreneurship\n");
				break;

			}
			break;

		case 6:
			printf("Faculty of Art and Design\n");
			switch (department_number)
			{
			case 1:
				printf("communacation design\n");
				break;

			case 2:
				printf("art management\n");
				break;

			case 3:
				printf("communacation art \n");
				break;

			case 4:
				printf("film and television\n");
				break;

			case 5:
				printf("gastronomy and culinary arts \n");
				break;

			case 6:
				printf("new media and communacation\n");
				break;

			case 7:
				printf("cartoon and animation\n");
				break;


			}
			break;

		case 7:
			printf("Faculty of Architecture\n");
			switch (department_number)
			{
			case 1:
				printf("Architecture(turkish)\n");
				break;

			case 2:
				printf("Architecture(english)\n");
				break;

			case 3:
				printf("ınterior Architecture & enviromental design(turkish)\n");
				break;

			case 4:
				printf("Interior Architecture & enviromental design (english)\n");
				break;




			}
			break;

		case 8:
			printf("Faculty of Health Sciences\n");
			switch (department_number)
			{
			case 1:
				printf("Nutrition and dieteticks\n");
				break;

			case 2:
				printf("Physiotherapy and rehabilation\n");
				break;

			}
			break;

		default:
			printf("Faculty's is between [1-8] try them ");
			break;

		}

		
		printf("student number: %d\n", student_number);

		printf("continue ? (yes or no)\n");
		printf("--> ");
		scanf_s(" %c", &answer);
		if(answer == 'N'|| answer == 'N')
			break;
	
	}while (answer == 'y' || answer == 'Y');


	return 0;
}