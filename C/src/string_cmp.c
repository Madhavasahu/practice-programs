#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int string_cmp(char*,char*);
void copyString(char*,char*);
int main(int argc, char* argv[]){
    char first[MAXSIZE];
    char second[MAXSIZE];
    int result = 0;
    if (argc < 3){
        printf("usage: firstString secondString\n"); 
        exit(1);
    }
    copyString(argv[1],first);
    copyString(argv[2],second);
    printf("first is %s\n",first);
    printf("second is %s\n",second);
    result = string_cmp(first,second); 
    if(result)
        printf("They are same\n");
    else
        printf("They are not same\n");
	
    return 0;
}
void copyString(char* src,char* dst){
    while(*src != '\0')
    {
        *dst = *src;
        src++;
        dst++;
    }
}
int string_cmp(char* first, char* second){
    while(*first == *second){
        if(*first =='\0' || *second =='\0')
            break;
        first++;
        second++;
    }
    if(*first =='\0' && *second =='\0')
        return 1;
    else
        return 0;
}
