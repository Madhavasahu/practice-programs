#include<stdio.h>
#include<stdlib.h>
typedef struct basic{
    int a;
    int b;
    float d;
}str;
int main(int argc, char* argv[]){
    str one = {2,32};
    str *ptr = &one;
    ptr->d = 33.2;
    printf("%d\n",ptr->a);
    printf("%d\n",ptr->b);
    printf("%f\n",ptr->d);
    
	return 0;
}
