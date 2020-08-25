#include <stdio.h>
int main(){
int val=5;
int val2=23;
int* const ptr= &val;
printf("%d\n",*ptr);
*ptr = 10;
printf("%d\n",*ptr);
//ptr  = &val2;
printf("%d\n",*ptr);

return 0;
}
