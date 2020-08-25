#include<stdio.h>
void func(int *ptr,int size);
int main(){
    int i, arr[3]={1,2,3};
    int *ptr = arr;
    func(ptr,3);
    for(i=0;i<3;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
void func(int *ptr,int size){
    int i = 0;
    for(i=0;i<size;i++){
        ptr[i] = ptr[i]*3;
    }
}
