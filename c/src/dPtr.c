#include<stdio.h>
int main(){
    int a=10, b = 7;
    int *ptr;
    ptr = &b;
    printf(" %d ",a**ptr); //indirection is first computed then multiplication
    return 0;
}
