#include<stdio.h>
int main()
{
int n,a[50],index,ele;
printf("Enter the no.of elements:");
scanf("%d",&n);
printf("Enter the array elements:-");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the index and element:");
scanf("%d%d",&index,&ele);
n=n+1;
for(int i=n;i>index;i--)
{
a[i]=a[i-1];
}
a[index]=ele;
printf("The array after insertion\n");
for(int i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}
  