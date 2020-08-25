/*
 ============================================================================
 Name        : Unions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Usage of unions
 * We can use unions for saving space
 * Depending on the choice input given by the user/any other HW we can use only one field at a time in union
 */
typedef union ex{
	char name[100];
	int roll_no;
}EX;
typedef struct unionInsideStruct {
	int marks;
	EX example;
	/*union ut{  //We can use plain union without tag and variable.In this case, we simple call this union
		//by one.name.
		char name[100];
		int roll_no;
	}EX;*/
} EXAMPLE;
int main(void) {
	EXAMPLE one;
	char choice;
	printf("Enter name or roll_no\n");
	fflush(stdout);
	printf("Enter Y for name\n");
	fflush(stdout);
	scanf("%c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("Enter the name:");
		scanf("%s", one.example.name);  //if the union is defined inside the structure itself
									    //then we will use one.EX.name.
	} else {
		printf("Enter the roll_no\n");
		scanf("%d", &one.example.roll_no);
	}
	printf("Enter the marks");
	fflush(stdout);
	scanf("%d", &(one.marks));
	if (choice == 'y' || choice == 'Y') {
		printf("Name: %s\n", one.example.name);
	} else {
		printf("Roll_no: %d\n", one.example.roll_no);
	}
	fflush(stdout);
	printf("Marks: %d\n", one.marks);
	fflush(stdout);
	return EXIT_SUCCESS;
}
