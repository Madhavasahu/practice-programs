#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int main(int argc, char* argv[]){
	char name[MAX] = {'\0'};
    printf("Enter your name:");
    gets(name);
    printf("Your name is:");
    puts(name);
    return 0;
}
