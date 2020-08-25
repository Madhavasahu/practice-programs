#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int a;
    char c;
    char str[100];
    float b;
    }BASIC;

int main(int argc, char* argv[]){
    BASIC bb;
    for(int i=0;i<2;i++)
    printf("Enter a integer\n");
    scanf("%d",&bb.a);
    printf("Enter a string\n");
    scanf("%s",bb.str);
    printf("Enter a float\n");
    scanf("%f",&bb.b);
    printf("Integer is %d, float is %f, string is %s\n",bb.a,bb.b,bb.str);
    printf("%ld %ld %ld %ld",sizeof(bb.a),sizeof(bb.str),sizeof(bb.b),sizeof(bb.c));
    printf("\n%ld",sizeof(bb));
    return 0;
}
