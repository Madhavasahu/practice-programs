#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int a;
    char str[100];
}basic;
basic* func(void);
basic* display(basic* strct);
int main(int argc, char* argv[]){
    basic st = {.str="madhava",.a=1};
    basic *pst = &st;
    pst = display(pst);
    printf("After the func : %d\n",pst->a);
	basic *var = func();
    printf("%s\n",var->str);
    //strcpy(var.str,"Now the string is ramayanam");
    //above we need to use strcpy to copy or other loop technique to modify
    //the string which was already initialized.
    //printf("%s\n",var.str);
    free(var);
    return 0;
}
basic* func(void){
    basic *vptr = (basic*)malloc(sizeof(basic));
    vptr->a = 100;
    strcpy(vptr->str,"madhavasadfasf");
    return vptr;
} 
basic* display(basic *strct){
    printf("%d\n",strct->a);
    printf("%s\n",strct->str);
    strct->a *= 2;
    return strct;
}
