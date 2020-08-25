#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    char *ptr[3] = {"aadhava","bahu","cagannadh"};
    char *temp;
    //Dont use character pointer for printing or for scanf()
    //It gives you undefined behaviour
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if((ptr[i] > ptr[j])){//comparing whether ascii values are equal or not. return > 0 if ptr[i] > ptr[j]. we can use strmp(ptr[i],ptr[j]) > 0 also.
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    for(int k=0;k<3;k++){
        printf("%s\n",ptr[k]);
    }
	return 0;
}
