/*
 ============================================================================
 Name        : StringAPI's.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int myBinarySearch(int arr[5], int size, int num) {
	int low = 0, mid = 0, up = 0;
	up = size - 1;
	while (low <= up && num != arr[mid]) {
		mid = (low +up)/2;
		if (num > arr[mid]) {
			low = mid + 1;
		}
		else if (num < arr[mid]) {
			up = mid - 1;
		}
		if (num == arr[mid]) {
			return 1;
		}
	}
	return 0;
}
int main(void) {
	int arr[5] = { 0 };
	int i = 0;
	int num = 0;
	int retValue = 0;
	for (i = 0; i < 5; i++) {
		printf("Enter element %d: ", i);
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nenter the num to be found\n");
	scanf("%d", &num);
	retValue = myBinarySearch(arr, sizeof(arr) / sizeof(arr[0]), num);
	if (retValue) {
		printf("found");
	} else {
		printf("not found");
	}

}
