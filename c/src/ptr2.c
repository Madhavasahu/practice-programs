#include<stdio.h>
int main(){
 char *cities[] = {"UAE", "Spain", "America"};
 int **i = &cities[0]; //or int *i = cities[0] and access using *i
 int **j = &cities[1];
 int **k = &cities[2];
 printf("%c%c%c\n", **i,**j,**k);
 return 0;
}
