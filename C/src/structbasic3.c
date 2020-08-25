#include<stdio.h>
#include<stdlib.h>
//this is a program to show the differences between structures in C vs C++
typedef struct C{
    struct A{
        int a;
        int b;
        char c;
    }a;
    struct B{
        int a;
        int b;
    }b;
}c;

struct zz{
    int a;
    void func(void);

};
void zz::func(void){
    printf("Hello world\n");
}
int main(int argc, char* argv[]){
        
    zz d={2};
    d.func();
    printf("%d\n",d.a);
    c mixed={{2,3},{4,5}};
    //in case of excess elements like {{1,2,3},{3,4,5}} compiler gives warning but executes fine
    printf("size of the structures is %ld\n",sizeof(mixed));
    printf("%d\n",mixed.a.a);
    printf("%d\n",mixed.b.b);

	return 0;
}
