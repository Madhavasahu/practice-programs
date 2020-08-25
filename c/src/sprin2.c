#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    char s1[10] = "Madhava";
    char s2[100] = "Sahu";
    char s3[100] = {'\0'};
    //size allocation should be precise otherwise output is undefined
    sprintf(s3,"My name is %s %s\n",s1,s2);
    printf("%s\n",s3);
    int a = 112;
    float aa = 12.22;
    sprintf(s1,"a is %d\n",a);
    sprintf(s2,"aa is %f\n",aa);
    printf("%s\n",s1);
    printf("%s\n",s2);
 printf("s3 is %s\n",s3);
   
	return 0;
}
