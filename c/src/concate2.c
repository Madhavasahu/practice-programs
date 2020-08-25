#include<stdio.h>
#define print(i,limit) while (i < limit) \
{                                        \
    printf("hello world\n");             \
    i++;                                 \
}
int  main(int argc, char* argv){
    int i=0;
    print(i,10);
    return 0;
}
