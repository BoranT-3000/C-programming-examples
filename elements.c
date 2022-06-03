#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 118


typedef struct{
	char element_name[50];
	char element_symbol[50];
	int atomic_number;
	int mass_number;
	int ionic_weight;
} element_t;

void print(element_t chm_element[]);

int main() 
{
	element_t elements[MAX_ELEMENT];
	char command;
	int i = 0;
	do {

		printf("\nEnter element name :");
		scanf("%s",&elements[i].element_name);
		printf("\nEnter element symbol :");
		scanf("%s",&elements[i].element_symbol);
		printf("\nEnter the atomic number :");
		scanf("%d",&elements[i].atomic_number);
		printf("\nEnter the mass number :");
		scanf("%d", &elements[i].mass_number);
		printf("\nEnter the ionic weight :");
		scanf("%d", &elements[i].ionic_weight);

		printf("Do you want to continue ? (Y / N) ");
		scanf_s(" %c",&command);

		if (command == 'N' ||command == 'n') {
			print(elements, i+1);
			exit(1);
		}
	
		i++;

	} while (command =='y'||command=='Y' || i <= 118);


	
	return 0;
}

void print(element_t chm_element[], int len) {

	int neutron = 0, electron = 0;

	printf("******************************* \n* ***** Chemical Element List ****** *\n ******************************\n");

	printf("| Element name || Symbol ||  Atomic number || Mass number || Ionic weight || Neutron || Electron |\n");

	for (int i = 0;i < len;i++)
	{
		
		neutron = chm_element[i].mass_number - (chm_element[i].atomic_number);
		electron = chm_element[i].atomic_number - (chm_element[i].ionic_weight);
		printf("| %s \t\t|| %s \t\t|| %d \t\t|| %d \t|| %d \t\t|| %d \t|| %d \t\t|\n",chm_element[i].element_name,chm_element[i].element_symbol,chm_element[i].atomic_number,chm_element[i].mass_number,chm_element[i].ionic_weight, neutron, electron);
	
	}

}