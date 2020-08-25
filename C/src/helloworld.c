#include<stdio.h>
int main(int argc, char* argv[]){
    int a = 23;
    int i = 0;
    printf("a value is %d\n",a);
    printf("the name of the program is %s\n",argv[0]);
    for(i=1;i<argc;i++)
    {
        printf("the %d argument is %s\n",i,argv[i]);
    }
return 0;
}
