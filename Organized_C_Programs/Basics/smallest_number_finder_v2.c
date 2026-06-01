#include<stdio.h>
void main()
{
    int n,i,j,gn;
    printf("Enter the value of n:");
    scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
    scanf("%d",&j);
    if(i==1)
    gn=j;
    if(gn>j)
    gn=j;
    }
    printf("Smallest of numbers is:%d",gn);
}