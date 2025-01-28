#include <stdio.h>
#include <stdlib.h>
void Swap(int *a,int*b)
{
   int *c=0;
   *c=*a;
   *a=*b;
   *b=*c;
}
int QuickSort (int arr[],int f,int l)
{
    if (arr[0]=='\0')
    {
    return -1;
    }
    int fix=arr[f]; 
    int dn=f+1,up=l;
    else  
    {
      while(fix>arr[dn])
      dn++;
      while(fix<arr[up])
      up++;
    if(dn>up)
    {
      Swap(&arr[dn],&arr[up]);
      while(fix>arr[dn])
      dn++;
      while(fix<arr[up])
      up++;
    }
    if(f!=up)
    Swap(&arr[f],&arr[up]);
    else if(f<up-1)
    QuickSort(arr,f,up-1);
    else
    QuickSort(arr,up+1,l); 
    }
    
}
int main()
{
  int count;
  int arr[100];
  printf("\nenter the length of the array\n");
  scanf("%d",&count);
  printf("enter the elements");
  for(int i=0;i<count;i++){
  scanf("%d",&arr[i]);
}
   int f=0;
  printf("\nThe sorted array is: ");
  QuickSort(arr,f,count-1);
  for(int i=0;i<count;i++)
  {
  printf("%d, ",arr[i]);
  }
  return 0;
}