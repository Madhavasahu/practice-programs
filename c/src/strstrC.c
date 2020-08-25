#include <stdio.h>
#include <string.h>
#define MAX1 100
#define MAX2 100

/*Limitations:
 * Applicable only for Case sensitive search
 */
int findSubString(char srcStr[], char subStr[]);
int main(void) {
	char srcStr[MAX1]={"\0"};
	char subStr[MAX2]={"\0"};
	printf("Enter the source string\n");
	scanf("%[^\n]s",srcStr);
	printf("Enter the sub string\n");
	scanf("%s",subStr);
	if (findSubString(srcStr, subStr) == 1) {
		printf("Found\n");
	} else {
		printf("Not found\n");
	}
}
int findSubString(char srcStr[], char subStr[]) {
	int srcLen = strlen(srcStr);
	int subStrLen = strlen(subStr);
	int i = 0;
	int j = 0;
	if ((subStrLen > srcLen) || (subStrLen == 0) || (subStrLen == 0)) {
		printf("not a valid sub string\n");
		return 0;
	}
	for (i = 0, j = 0; i < srcLen && j < subStrLen; i++) {
		if (srcStr[i] == subStr[j]) {
			j++;
		} else {
			j = 0;
		}
	}
	if (j == subStrLen) {
		return 1;
	} else {
		return 0;
	}

}
