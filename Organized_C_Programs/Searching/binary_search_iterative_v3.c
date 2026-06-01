#include<stdio.h>
void main()
{
int n,a[]={2,5,8,9,13,23,35,46},key;
n=sizeof(a)/sizeof(a[0]);
printf("Enter the value to be searched:");
scanf("%d",&key);
int low=0,high=n-1,mid;
while(low<=high) 
{
mid=(low+high)/2;
if(key<a[mid])
{
high=mid-1;
}
else if(key==a[mid]) 
{
printf("Element found at position %d",mid+1);
break;
}
else
{
low=mid+1;
}
}
}
    