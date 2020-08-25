/*
 ============================================================================
 Name        : ArrayOfFunctionPointers.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float add(float,float);
float sub(float,float);
float (*fptr[2])(float,float)={add,sub};
typedef enum{
	ADD,
	SUB
}OP;
int main(void) {
	float a=0,b=0;
	int choice=0;
	printf("Enter the value of a and b\n");
	scanf("%f %f",&a,&b);
	printf("Choose the operation: 1->add, 2->sub\n");
	scanf("%d",&choice);
	switch(choice){
	case ADD:
		printf("%f\n",fptr[ADD-1](a,b));
		break;
	case SUB:
		printf("%f\n",fptr[SUB-1](a,b));
		break;
	default:
		printf("Enter the correct choice\n");
		break;
	}
}

float add(float a,float b){
	return a+b;
}
float sub(float a, float b){
	return a-b;
}
