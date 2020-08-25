#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int a;
    int b;
}A;


int main(int argc, char* argv[]){
    A var;
    printf("enter the value of a:");
    scanf("%d",&var.a);
    printf("%d\n",var.a);


	return 0;
}
