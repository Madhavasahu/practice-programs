#include <stdio.h>
struct Val{
int a;
int b;
}val[]={{1},{2}};
typedef struct{
    int a;
}MADHAVA;

MADHAVA m={ };
int main(){
    printf("%d %d %d %d\n",val[0].a,val[0].b,val[1].a,val[1].b);
    printf("%ld\n",sizeof(val));
    printf("%d\n",m.a);
    return 0;
}
