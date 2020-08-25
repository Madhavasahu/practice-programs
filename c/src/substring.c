#include<stdio.h>
#include<string.h>
#define MAXLEN 100

void copytoinput(char argv[], char dest[]);
int search_substring(char source[], char sub[]);
int main(int argc, char* argv[]){
    char input_string[MAXLEN] = ""; 
    char sub_string[MAXLEN]   = "";
    int  i                    = 0;
    copytoinput(argv[1],input_string);
    copytoinput(argv[2],  sub_string);
    printf("input string is %s\n",input_string);
    printf("sub string is %s\n",    sub_string);
    if(search_substring(input_string, sub_string)==1){
        printf("found it\n");
    }
    else{
        printf("not found\n");
    }
    return 0;
}

int search_substring(char source[], char sub[]){
    int  i           = 0;
    int  j           = 0;
    int  sub_size    = strlen(sub);
    int  source_size = strlen(source);

    for(i=0;i<=source_size-sub_size;i++){
        for(j=0;j<sub_size;j++){
            if(source[i+j] == sub[j]){
                 //printf("%c\n",sub[j]);
            }else{
                break;
            }
        }    
    if(j==sub_size)
        return 1;
    }
    return 0;
}


void copytoinput(char argv[],char dest[]){
    while (*argv !='\0'){
        *dest = *argv;
        dest++;
        argv++;
    }
}
