
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insert(char* file_name);
void select(char* file_name);
int read_line(char str[], int n);
void is_file_empty(char* file_name);

int main()
{
	char table_name[50];
	char answ,choice;

	do {
		printf("--------------------------------\n");
		printf("\t      Notebook \n");
		printf("--------------------------------\n");
		printf("\tSelect   as [s] or [S]\n");
		printf("\tUpdate   as [u] or [U]\n");
		printf("\tInsert   as [i] or [I]\n");
		printf("\tDelete   as [d] or [D]\n");
		printf("\tTruncate as [t] or [T]\n");
		printf("\tQuit     as [q] or [Q]\n");
		printf("--------------------------------\n");
		printf("--> ");
		scanf_s(" %c", &choice);

		switch (choice) {
		
		case 's':case 'S': {
			printf("what is the name of asked table\n--> ");
			read_line(table_name, 50);
			select(strcat(table_name, ".txt"));
			break;
		}

		case 'u':case 'U':
			break;

		case 'd':case 'D': {
			printf("what is the name of asked table\n--> ");
			read_line(table_name, 50);
			printf("are you sure that you want to delete %s (y/n)\n--> ",table_name);
			scanf_s(" %c",&answ);
			if (answ == 'y' || answ == 'Y') {
				if (remove(strcat(table_name, ".txt")) == 0) {
					printf("The file is deleted successfully.\n");
				}
				else {
					printf("The file is not deleted.\n");
					perror("Following error occurred");
				}
			}
			else {
				printf("The file is not deleted.\n");
				printf("Unable to delete the file\n");
				perror("Error");
			}
			
			break;
		}
			
		case 'i':case 'I': {
			printf("what is the name of asked table\n--> ");
			read_line(table_name, 50);
			insert(strcat(table_name, ".txt"));
			break;
		}
		
		case 't':case 'T': {
			printf("what is the name of asked table\n--> ");
			read_line(table_name, 50);
			is_file_empty(table_name);
			printf("are you sure ? (y/n)");
			scanf(" %c", &answ);
			if (answ == 'y' || answ == 'Y')
			{
				FILE* file = fopen(strcat(table_name, ".txt"), "w");
				fclose(file);
			}	
			break;
		}

		case 'q':case 'Q': {
			printf("you are leaving the program !\n");
			exit(1);
			break;
		}
		
		default: {
			printf("[INFO] - invalid selection\n");
			break;
		}
			
		}

		printf("\ncontinue ? (Y/N) \n[-->");
		scanf_s(" %c",&answ);
	} while (answ=='y'||answ=='Y');


	return 0;
}

void is_file_empty(char * file_name){
	int size = 0;
	FILE* file = fopen(strcat(file_name, ".txt"), "r");
	
	if (file != NULL) {
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		fclose(file);
	}
	
	if (size == 0) {
		printf("[INFO] - file is empty\n");
	}
	else {
		printf("[INFO] - file is not empty");
	}
}

void insert(char* file_name)
{
	FILE* fptr;
	char ch;

	fptr = fopen(file_name, "w+");
	if (fptr == NULL)
	{
		printf("Can't open file. Make sure file exits.\n");
		//exit(1);
		goto end;
	}

	printf("Start typing something....\n\n");
	do
	{
		ch = getche();
		fputc(ch, fptr);
	} while (ch != '\r');

	/*
	rewind(fptr);
	printf("\n\nWritten content in file is:\n");
	do
	{
		ch = fgetc(fptr);
		putchar(ch);
	} while (ch != EOF);
	*/


	fclose(fptr);
	end:
	printf("\n\nProgram completed. Press any key to continue...");



}

void select(char *file_name)
{
	FILE* fptr;
	char ch;
	int count = 0;

	fptr = fopen(file_name,"r");

	if (fptr == NULL) {
		printf("Can't open file. Make sure file exits.\n");
		goto end;
		//exit(1);
	}

	do
	{
		ch = fgetc(fptr);

		putchar(ch);
		count++;

	} while (ch != EOF);

	fclose(fptr);
	printf("\n\nNumber of characters = %d", count);
	end:
	printf("\n\nProgram completed. Press any key to continue...");
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;

    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}


//for further improvments
//https://idiotdeveloper.com/file-transfer-using-tcp-socket-in-c/
//https://www.w3schools.in/c-programming/examples/replace-a-specific-line-in-a-text-file
//https://www.w3schools.in/c-programming/examples/find-the-number-of-lines-in-a-text-file
//https://www.w3schools.in/c-programming/examples/delete-a-specific-line-from-a-text-file
//https://github.com/psp316r/File-Transfer-Using-TCP-Socket-in-C-Socket-Programming
