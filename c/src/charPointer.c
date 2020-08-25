#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void func(char** str_ref){
    str_ref++; //this wont reflect back because it is local
}
int main(){
    char *str = (char*)malloc(100*sizeof(char));
    strcpy(str,"madhava");
    func(&str);
    puts(str);
    free(str);
    return 0;
}
