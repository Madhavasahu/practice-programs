#include<stdio.h>
void fun(int arr[],int arr_size)
{
  int i;
  printf("%d\n",arr_size);
  for (i = 0; i < arr_size; i++)
      printf("%d ", arr[i]);
}
 
int main()
{
  int i;
  int arr[4] = {10, 20 ,30, 40};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  fun(arr,arr_size);
  return 0;
} 
