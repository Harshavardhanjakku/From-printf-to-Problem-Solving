#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter the value of n:");
    scanf("%d",&n);
  for(i=1,j=n;i<=n,j>0;i++,j--)
    {
    printf("%d\t%d",i,j);
    printf("\n");
    }
}