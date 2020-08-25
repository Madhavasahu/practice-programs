#include <stdio.h>
#include <string.h>
int main(){
    char p[20];
    char *ptr = "string";
    int i;
    int len = strlen(ptr);
    printf("%d\n",len);
    for (i=0;i<len;++i)
        p[i]=ptr[len-i];
    printf("%s",p);
    return 0;

}

