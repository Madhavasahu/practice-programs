#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int a;
    int b;
    int c;
}Basic;
int main(int argc, char* argv[]){
    Basic b[3];
    int i = 0;
    for(i=0;i<3;i++){
        printf("Enter a:");
        scanf("%d",&b[i].a);
        printf("Enter b:");
        scanf("%d",&b[i].b);
        printf("Enter c:");
        scanf("%d",&b[i].c);
    }
    for(i=0;i<3;i++){
        printf("\nBasic[%d]: %d\n",i,b[i].a);
        printf("Basic[%d]: %d\n",i,b[i].b);
        printf("Basic[%d]: %d\n",i,b[i].c);
        printf("\n");
    }
	return 0;
}
