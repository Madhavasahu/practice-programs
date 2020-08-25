/*
 ============================================================================
 Name        : InsertionSort.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void stringCopy(const char* src, char* dst);
void insertionSort(int array[], int len);
void printArray(int array[], int len);
int main(void) {
	const char *src = "Hello world";
	char dst[MAX] = {'\0'};
	int array[] = { 1,2,3,4,5};
	int length = (sizeof(array) / sizeof(array[0]));
	//insertionSort(array, length);
	//printArray(array,length);
	stringCopy(src,dst);
	printf("\n copied string is %s",dst);
	return EXIT_SUCCESS;
}
void stringCopy(const char *src,char* dst){
	int i=0;
	while(src[i] != '\0'){
		*dst++ =*src++;
		printf("%c",dst[i]);
	}
	dst[i] = '\0';
}
void insertionSort(int array[], int len) {
	int i = 0;
	int value = 0;
	int hole = 0;
	if(len == 1){
		printf("entered only one element\n");
		return;
	}
	for(i=1; i<len; i++){
		value = array[i];
		hole = i;
		while((hole > 0) && (array[hole-1] >value)){
			array[hole] = array[hole-1];
			hole = hole-1;
		}
		array[hole] = value;
	}
}
void printArray(int array[],int len) {
	int i=0;
	printf("Sorted array: ");
	for(i=0; i<len; i++)
		printf("%d ",array[i]);
	printf("\n");
}
