#include<stdio.h>
int size=4;
void merge(int a[],int low,int mid,int high)
{
   int temp[size],i=low,k=low,j=mid+1;
   while((i<=mid)&&(j<=high))
   {
    if(a[i]<=a[j])
    temp[k++]=a[j++];
    else
    temp[k++]=a[i++];
   }
   while(i<=mid)
   temp[k++]=a[i++];
   while(j<=high)
   temp[k++]=a[j++];
   for(i=low;i<=high;i++)
   a[i]=temp[i];

}
void msort(int a[],int low,int high)
{  
   if(low<high)
   {
    int mid;
    mid=(low+high)/2;
    msort(a,low,mid);
    msort(a,mid+1,high);
    merge(a,low,mid,high);
   }
}
int main()
{
   int i;
   int a[size];
   for(i=0;i<size;i++)
   scanf("%d",&a[i]);
   
   msort(a,0,size-1);
   for(i=0;i<size;i++)
   printf("%d\n",a[i]);
   return 0;
}