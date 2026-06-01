#include<stdio.h>
void main()
{
int n,a[]={5,2,9,13,7,4,6,21},key;
n=sizeof(a)/sizeof(a[0]);
int temp,j=0;
while(j<(n/2+1)) 
{
for(int i=1;i<n;i++)
{
if(a[i-1]>a[i])
{
temp=a[i-1];
a[i-1]=a[i];
a[i]=temp;
}
}
j=j+1;
}
for(int i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}
    