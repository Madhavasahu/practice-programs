#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    char a[] = "b";
    char aa = 'b';
    printf("size of ""\"b\" is %ld\n",sizeof(a));   //takes two bytes includig the null character
    printf("size of character \'b\' is %ld\n",sizeof(aa));//takes only one byte for the character itself. 
	return 0;
}
