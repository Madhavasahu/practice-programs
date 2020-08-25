/*
 ============================================================================
 Name        : ArrayOfPointers.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void func1(int array[3][3]); //Can write this as void func1(int (*array)[3]) also.
void func2(int *ptr[3]);
int main(void) {
	int arr[3][3] = { { 1 }, { 2 }, { 3 } };
	int *parr[3] = { 0 }; //parr is a array of 3 integer pointers. each pointer has a 1 1D array
	for (int i = 0; i < 3; i++)
		parr[i] = arr[i];
	//func1(arr);
	func2(parr);
}
void func2(int *ptr[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d\n", ptr[i][j]);
	}
}
void func1(int array[3][3]) { //Can write this as void func1(int (*array)[3]) also.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d\n", array[i][j]);
	}
}
