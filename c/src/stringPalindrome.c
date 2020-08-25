#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main(int argc, char* argv[]){
    char array[MAX] = {"\0"};
    int i=0;
    int j=0;
    int flag = 0;
    scanf("%s",array);
    j = strlen(array)-1;
    while(i<=j){
        if(array[i] == array[j]){
            flag = 1;
        }else{
            flag =0;
            break;
        }
        i++;
        j--;
    }
    if(flag){
        printf("Its palindrome\n");
    }
    else{
        printf("Its not palindrome\n");
    }
	return 0;
}
