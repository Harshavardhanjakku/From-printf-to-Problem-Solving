#include<stdio.h>
int main()
{
int a[]={2,8,5,3,9,4,1},n,temp,j;
n=sizeof(a)/sizeof(a[0]);
for(int i=0;i<n;i++)
{
j=i;
    while(j<n)
    {
        if(a[i]>a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    j=j+1;
    }
}
printf("Elements after sorting:");
for(int i=0;i<n;i++)
{
printf("%d\n",a[i]);
}    
}
