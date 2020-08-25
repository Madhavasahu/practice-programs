#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    char *p1 = "Madhava";
    char a1[] = "MADAHVA";
    char a2[]  = "SAHU";
    char a3[20]="\0";
    char *p2 = "Sahu";
    /* We cant use a uninitiliazed character pointer
     * i.e using using p3 directly will cause seg fault
     * We cant overwrite the already initilized character pointer becoz
     * they are stored somewhere but read only memory
     * we need to dynamically allocate the memory for character pointers
     * to copy any data to it.
     * */
    char *p3 = (char*)malloc(strlen(p1)+strlen(p2)+1);
    int n = strlen(p1)+strlen(p2); 
    sprintf(p3,"Hello %d",n);
    sprintf(a3,"Hello %s %s",a1,a2);
    printf("%s\n",a3);
    printf("%s\n",p3);
	return 0;
}
