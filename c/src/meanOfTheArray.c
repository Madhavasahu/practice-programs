/*
 ============================================================================
 Name        : meanOfTheArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[5] = {0};
	int len = sizeof(arr)/sizeof(arr[0]);
	int sum = 0;
	int mean = 0;
	int i = 0,j=0;
	int temp1 = 0;
	int temp2 = 0;
    for(i=0;i<5;i++){
        printf("enter element %d: ",i);
        scanf("%d",&arr[i]);
    }
    
    printf("Array elements are ");
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
	for(i=0;i<len;i++){
		sum = sum+arr[i];
	}
	mean = (int)(sum/len);
    printf("Mean of the elements in the array is %d\n",mean);
	temp2 = sum;
	for(i=0;i<len;i++){
		if(arr[i] >= mean){
			temp1 = arr[i] - mean;
		}else{
			temp1 = mean - arr[i];
		}
		if (temp1 < temp2){
			temp2 = temp1;
			j=i;
		}
	}
	printf("Element that is close to mean is %d\n",arr[j]);
	return EXIT_SUCCESS;
}
