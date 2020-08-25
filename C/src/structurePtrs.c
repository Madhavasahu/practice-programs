/*
 ============================================================================
 Name        : structurePtrs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int roll_no;
	char name[100];
}STUDENT;
void display(STUDENT* ptr);
int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
	STUDENT *ptr;
	ptr = (STUDENT*)malloc(sizeof(STUDENT));
	printf("Enter the student roll no\n");
	scanf("%d",&(ptr->roll_no));   //in other words &ptr->roll_no
	printf("Enter the student name\n");
	scanf("%s",ptr->name);
	display(ptr);
	return EXIT_SUCCESS;
}

void display(STUDENT *ptr){
	printf("the details are:\n");
	printf("ROLL NUMBER: %d\n",ptr->roll_no);
	printf("NAME : %s\n",ptr->name);
}
