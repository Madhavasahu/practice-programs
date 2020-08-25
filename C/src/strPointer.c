#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char *str = "His";
	int i;
    printf("%lu\n",strlen(str));
	for(i = 0; i < strlen(str); i++)
	    printf("%d %s\n",i, ++str);
	return 0;
}
