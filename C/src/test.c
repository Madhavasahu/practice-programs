#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void seperateFileNames(char baseFilename[105]) {
	FILE *fptr;
	FILE *cptr;
	FILE *cppptr;
	FILE *csptr;
	char temp[105];
	char *ext[3] ={".c",".cs",".cpp"};
	char *ptr;
	int i = 0;
	fptr = fopen(baseFilename, "r");
	cptr = fopen("C.txt", "w");
	cppptr = fopen("CPP.txt", "w");
	csptr = fopen("CS.txt", "w");

	for (i = 0; (!feof(fptr)); i++) {
		if (feof(fptr)){
			break;
		}else{
			fscanf(fptr, "%s", temp);
			ptr = strchr(temp,'.');
			if (!(strcmp(ptr, ext[0]))){
				printf("%s and  %s\n",ptr,temp);
				fprintf(cptr,"%s\n",temp);
			}else if(!(strcmp(ptr,ext[1]))){
				fprintf(csptr,"%s\n",temp);
			}else if (!(strcmp(ptr,ext[2]))) {
				fprintf(cppptr,"%s\n",temp);
			}
		}
	}
	fclose(fptr);
	fclose(cptr);
	fclose(cppptr);
	fclose(csptr);
}
int main() {
	char *c ={"asdfas"};
	printf("%d",sizeof(c));
	return 0;
}
