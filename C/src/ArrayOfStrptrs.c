#include<stdio.h>
#include<stdlib.h>
void size(char* arrp[],int size);
int main(int argc, char* argv[]){
    char* arrp[] ={"Madhava","Sahu","Jagannadh"};
    int s = (sizeof(arrp)/sizeof(arrp[0]));
    printf("%d\n",s);
	size(arrp,s);
    return 0;
}

void size(char* arrp[],int sizee){
    for(int i=0;i<sizee;i++){
        for(int j=0;*(*(arrp+i)+j) != '\0';j++)
            printf("%c\n",*(*(arrp+i)+j));
        }
}
