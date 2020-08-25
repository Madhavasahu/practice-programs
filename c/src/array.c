#include<stdio.h>
#include<stdlib.h>

void printArray(int *ptr,int size);
void squareArray(int *ptr,int size);
int main(){
    int *ptr       = 0;
    int i          = 0;
    int numOfElems = 0;    
    printf("Enter the number of elements:");
    scanf("%d",&numOfElems);
    ptr =(int*)malloc(numOfElems);
    for(i=0;i<numOfElems;i++){
        printf("Enter the element %d:",i);
        scanf("%d",&ptr[i]);
    }
    printf("The no.of elements :%d\n",numOfElems);
    squareArray(ptr,numOfElems);
    printArray(ptr,numOfElems);
    return 0;
}

void squareArray(int *ptr,int size){
    int i    = 0;
    for(i=0;i<size;i++){
        ptr[i] *= ptr[i];
    }
}

void printArray(int *ptr,int size){
    int i = 0;
    printf("Elements after squaring : ");
    for(i=0;i<size;i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");
}
