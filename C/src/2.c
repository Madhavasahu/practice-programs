#include<stdio.h>
int main(){
unsigned int n=64;
int out = 31;
int i=0;
for(i=31;i>0;--i)
{
    if((n & (1<<i))!=0){
        printf("%d\n",out);
        break;
    }
    printf("hello world\n");
    out--;
}
printf("%d\n",out);
return 0;
}
