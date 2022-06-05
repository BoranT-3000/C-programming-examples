#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

#define PI 3.14159
#define MESSAGE "The value must be greater than ZERO."
#define MSG "The value must be greater than ZERO or Width and height must not equal to each other."


HANDLE  hConsoleOut;                 // Handle to the console
COORD   consoleSize;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // Console information

void WriteTitle();    // Display title bar information
void ClearScreen(void); // Screen clear

typedef struct {
	double area;
	double	circumference;
	double	radius;
}circle_t;

typedef struct {
	double area;
	double	perimeter;
	double	width;
	double	height;
}rectangle_t;

typedef struct {
	double area;
	double perimeter;
	double side;
}square_t;

typedef union {
	circle_t circle;
	rectangle_t rectangle;
	square_t square;
}figure_data_t;

typedef struct {
	char shape;
	figure_data_t figure;
}figure_t;

figure_t get_figure_dimensions();
figure_t compute_area(figure_t object);
figure_t compute_perim(figure_t object);
void print_figure(figure_t object);

int main()
{

	// Get display screen information & clear the screen.
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	consoleSize.X = csbiInfo.srWindow.Right;
	consoleSize.Y = csbiInfo.srWindow.Bottom;
	ClearScreen();
	WriteTitle(0);


	figure_t onefig;
	printf("Area and Perimeter Computation Program\n");
	for (onefig = get_figure_dimensions();
		onefig.shape != 'Q';
		onefig = get_figure_dimensions()) {

		onefig = compute_area(onefig);
		onefig = compute_perim(onefig);
		print_figure(onefig);
	
	}
	return 0;
}


figure_t get_figure_dimensions()
{
	figure_t object;
	printf("\nEnter a letter to indicate the object shape or Q to quit and x for clear screen\n");
	printf("C(circle), R(rectangle) or S(square)> ");
	scanf(" %c", &object.shape);
	switch (object.shape)
	{
	case 'C':
	case 'c':
		printf("Enter radius> ");
		scanf("%lf", &object.figure.circle.radius);
		while (object.figure.circle.radius <= 0) {
			printf("\t%s\n", MESSAGE);
			printf("Enter radius> ");
			scanf("%lf", &object.figure.circle.radius);
		}
		break;
	case 'R':
	case 'r':
		printf("Enter height> ");
		scanf("%lf", &object.figure.rectangle.height);
		while (object.figure.rectangle.height <= 0) {
			printf("\t%s\n", MESSAGE);
			printf("Enter height> ");
			scanf("%lf", &object.figure.rectangle.height);
		}
		printf("Enter width> ");
		scanf("%lf", &object.figure.rectangle.width);
		while (object.figure.rectangle.width <= 0 || object.figure.rectangle.height == object.figure.rectangle.width) {
			printf("\t%s\n", MSG);
			printf("Enter width> ");
			scanf("%lf", &object.figure.rectangle.width);
		}
		break;
	case 'S':
	case 's':
		printf("Enter length of a side> ");
		scanf("%lf", &object.figure.square.side);
		while (object.figure.square.side <= 0) {
			printf("\t%s\n", MESSAGE);
			printf("Enter length of a side> ");
			scanf("%lf", &object.figure.square.side);
		}
		break;
	case 'x':case 'X':
		system("cls");
		break;
	default:
		object.shape = 'Q';
	}
	return object;
}


figure_t compute_area(figure_t object)
{
	switch (object.shape)
	{
	case 'C':
	case 'c':
		object.figure.circle.area = PI * object.figure.circle.radius * object.figure.circle.radius;
		break;
	case 'R':
	case 'r':object.figure.rectangle.area = object.figure.rectangle.height * object.figure.rectangle.width;
		break;
	case 'S':
	case 's':
		object.figure.square.area = object.figure.square.side * object.figure.square.side;
		break;
	default:
		printf("Error in shape code detected in compute_area\n");
	}
	return object;
}


figure_t compute_perim(figure_t object)
{
	switch (object.shape)
	{
	case 'C':
	case 'c':
		object.figure.circle.circumference = 2 * PI * object.figure.circle.radius;
		break;
	case 'R':
	case 'r':
		object.figure.rectangle.perimeter = 2 * (object.figure.rectangle.height + object.figure.rectangle.width);
		break;
	case 'S':
	case 's':
		object.figure.square.perimeter = 4 * object.figure.square.side;
		break;
	}
	return object;
}



void print_figure(figure_t object)
{
	switch (object.shape)
	{
	case 'C': case 'c': {
		printf("Object is a circle whose members:\n");
		printf("\tArea:%.2lf\n\tCircumference:%.2lf\n\tRadius:%.2lf\n", object.figure.circle.area, object.figure.circle.circumference, object.figure.circle.radius);
		break;
	}
	case 'R':case 'r': {
		printf("Object is a rectangle whose members:\n");
		printf("\tArea:%.2lf\n\tPerimeter:%.2lf\n\tWidth:%.2lf\n\tHeight:%.2lf\n", object.figure.rectangle.area, object.figure.rectangle.perimeter, object.figure.rectangle.width, object.figure.rectangle.height);
		break;
	}
	case 'S': case 's': {
		printf("Object is a square whose members:\n");
		printf("\tArea:%.2lf\n\tPerimeter:%.2lf\n\tSide:%.2lf\n", object.figure.square.area, object
			.figure.square.perimeter, object.figure.square.side);
		break;
	}

	case 'x':case 'X':
		system("cls");
		break;

	default:
		printf("wrong selection choose between s,r,s or q to quit\n");
		break;
	}
}


void WriteTitle()
{
	enum
	{
		sizeOfNThreadMsg = 120
	};
	wchar_t    NThreadMsg[sizeOfNThreadMsg] = { L"" };

	swprintf_s(NThreadMsg, sizeOfNThreadMsg,
		L"Compute figures pressing (C,R,S),"
		L"Clear screen press 'X', "
		L"'Q' to quit.");
	SetConsoleTitleW(NThreadMsg);
}

void ClearScreen(void)
{
	DWORD    dummy = 0;
	COORD    Home = { 0, 0 };
	FillConsoleOutputCharacterW(hConsoleOut, L' ',
		consoleSize.X * consoleSize.Y,
		Home, &dummy);
}






