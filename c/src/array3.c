#include<stdio.h>
void func(int (*ptr)[3]);
int main(){
    int i,j, arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int (*ptr)[3] = arr;
    printf("%ld\n",sizeof(*ptr));
    func(ptr);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
    }
    printf("\n");
    return 0;
}
void func(int (*ptr)[3]){
    int i = 0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            ptr[i][j]=ptr[i][j]*2;
        }
    }
}
