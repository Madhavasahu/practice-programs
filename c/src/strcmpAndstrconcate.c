#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* myStrcat(char* str1,char* str2);
/* String concatenation of two strings str1 and str2
 * Here, the null character from the first string is removed
 * And the second string is added at the end of first string.
 * The second string remain uneffected.
 */
int main(int argc, char* argv[]){
    char s1[20] = "Madhava";
    char s2[10] = "Sahu";
    char* ptr = "Jagannadh";
    char* ptr2 = '\0';
    printf("size of string is %ld, size of ptr is %ld\n",sizeof(s1),sizeof(ptr));
    ptr2 = ptr;
    s2[0] = 's';
    printf("%s\n",s2);
    /*if((strcmp(s1,s2==0)){
        printf("They are equal\n");
    }
    else{
        printf("They are not equal\n");
    }
    strcat(s1,s2);
    myStrcat(s1,s2); 
    printf("%s\n",s1);*/
	return 0;
}
char* myStrcat(char* str1,char* str2){
    while(*str1 != '\0'){
        str1++;
    }
    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return str1;
}
