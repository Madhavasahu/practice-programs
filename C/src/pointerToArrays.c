/*
 ============================================================================
 Name        : pointerToArrays.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void printArray(int (*ptr)[]);
void func1(int (*ptr)[]);
int main(void) {
	int arr[3][3] = {{1,2,10},{2,3,4},{3,4,5}};
	int (*ptr)[3] = arr;
	printf("In Main function\n");
	printArray(ptr);
	func1(ptr);
	printf("\nIn func1 function\n");
	printArray(ptr);
}
void printArray(int (*ptr)[3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			printf("%d\n",*(*(ptr+i)+j));
	}
}
void func1(int (*ptr)[3]){
	for(int j=0;j<3;j++){
		for(int i=0;i<3;i++)
			*(*(ptr+j)+i) = *(*(ptr+j)+i)*10;
	}

}
