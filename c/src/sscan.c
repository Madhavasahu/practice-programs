#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[10];
    int a;
    long double b;
}M;
int main(int argc, char* argv[]){
    char src[] = "madhava 23 23.23123123123131";
    M m;
    sscanf(src,"%s%d%Lf",m.name,&m.a,&m.b);
    //data type specifier for double is %lf and for long double %Lf
    printf("%s\n\n",m.name);
    printf("%d\n\n",m.a);
    printf("%Lf\n\n",m.b);
    int x   = 0;
    float y = 0.0;
    char str1[] = "12.122";
    char str2[] = "345";
    sscanf(str2,"%d",&x);//using sscanf we can convert strings into ints,floats
    sscanf(str1,"%f",&y);
    //printf("%d %f\n",x,y);
	return 0;
}
