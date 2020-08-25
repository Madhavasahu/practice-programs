#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    /*char *ptr1 = "bad";
    char *ptr2 = "bad";*/
    char a1[] = "bad";
    char a2[] = "bad";
    if (strcmp(a1,a2)==0){  //or we can use (strcmp(ptr1,ptr2) == 0) 
        printf("They are same\n");
    }
    else{
        printf("They are not same\n");
    }
        return 0;
}
