#include<stdio.h>
int main(){
    {
        int x = 100;
    }
    printf("%d\n",x); //we will get error because it is declared outside of the block
    return 0;
}
