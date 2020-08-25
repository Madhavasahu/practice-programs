#include<stdio.h>
#define SQUARE(x) x*x
int main(int argc, char* argv[]){
    printf("%d\n",25/SQUARE(5)); //prints 25 as the output instead of 1because there is no type checking in #define statements.
    return 0;
}
