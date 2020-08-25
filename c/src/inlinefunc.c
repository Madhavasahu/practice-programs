#include <stdio.h>
static inline int square(int x){
    return x*x;
}
int main(int argc, char* argv[]){
    printf("%d\n",25/square(5)); 
    return 0;
}
