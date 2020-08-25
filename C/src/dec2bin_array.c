#include<stdio.h>
#define MAX 100
void dec2bin(int);
int main(){
    int dec = 0;
    printf("Enter the number in decimal: ");
    scanf("%d",&dec);
    dec2bin(dec);
    return 0;
}

void dec2bin(int decimal){
    int tempArray[MAX] = {0};
    int i=0;
    int j=0;
    while(decimal > 0){
        tempArray[i] = decimal%2;
        decimal /=2;
        i++;
    }
    printf("The number in binary is    : ");
    for(j=i-1;j>=0;j--){
        printf("%d",tempArray[j]);
    }
    printf("\n");
}
