#include<stdio.h>
int main(){

char          a = 'c';
int           b = 10;
float         c = 10.123456;
double        d = 1.23455678888;
short int     e = 10;
long int      f = 20;
long double   g = 1.234567891;
long long int h = 2323323223;  //same as long int which 8bytes
printf("size of char          %ld\n",sizeof(a));
printf("size of int           %ld\n",sizeof(b));
printf("size of float         %ld\n",sizeof(c));
printf("size of double        %ld\n",sizeof(d));
printf("size of short int     %ld\n",sizeof(e));
printf("size of long int      %ld\n",sizeof(f));
printf("size of long double   %ld\n",sizeof(g));
printf("size of long long int %ld\n",sizeof(h));
return 0;
}
