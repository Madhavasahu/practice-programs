#include<stdio.h>
int main()
{
char *cities[] = {"Delhi", "London", "Sydney"};
int **i = &cities[0]; //gives warning but okay to assign to integer dpointer
printf("%c\n", **i);
return 0;
}
