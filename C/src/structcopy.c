#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int a;
    int *ptr;
}B;
int main(int argc, char* argv[]){
    B b;
    int y = 89;
    b.a = 100;
    b.ptr = &y;
    printf("value of b.a is %d\n",b.a); 
    printf("value of b.ptr is %d\n",*(b.ptr)); 
    B c;
    //c=b; //copying the structures using = operator
    memcpy(&c,&b,sizeof(B));  //we can use memcpy also but = is more concise
    c.a = 323;
    printf("value of c.a after assigning is %d\n",c.a); 
    printf("value of c.ptr is %d\n",*(c.ptr));
	return 0;
}
