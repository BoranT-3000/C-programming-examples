//Definition: The program reads a series of items form a fileand displays the data in columns.The
//program obtains the file name from the command line.Each line of the file will have the following
//form : item, mm - dd - yyyy, price
//For example, suppose that the file contains the following lines :
//123, 12.00, 12 / k25 / 2006
//124, 18.30, 1 / 10 / 2020
//Expected output :
//Item Unit Purchase
//Price Date
//123 $ 12.00 12 / 25 / 2006
//124 $ 18.30 1 / 10 / 2020
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1000

int main(int argc, char* argv[])
{
	FILE* fptr;
	char buff[BUFSIZE];

	//if (argc != 2) {
	//	fprintf(stderr, "usage: TXT filename\n");
	//	exit(EXIT_FAILURE);
	//}

	//if ((fptr = fopen(argv[1], "r")) == NULL) {
	//	fprintf(stderr, "Can't open %s\n", argv[1]);
	//	exit(EXIT_FAILURE);
	//}


	//printf("content of this file are \n");

	//while (fgets(buff, BUFSIZE - 1, fptr) != NULL)
	//	printf("%s\n", buff); 

	//fclose(fptr);



	char* filename = "read_file.txt";
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Error: could not open file %s", filename);
		return 1;
	}

	// reading line by line, max 256 bytes
	const unsigned MAX_LENGTH = 256;
	char buffer[BUFSIZE];

	while (fgets(buffer, MAX_LENGTH, fp))
		printf("%s", buffer);

	// close the file
	fclose(fp);

	return 0;
}