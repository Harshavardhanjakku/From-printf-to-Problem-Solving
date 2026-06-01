#include<stdio.h>
void main()
{
    int n,i,j,sum;
    printf("Enter the value of n:");
    scanf("%d",&n);
  for(i=1;i<=10;i++)
    {
    sum=0;
    for(j=1;j<=i;j++)
    {
    sum+=n;
    }
    printf("%d × %d = %d",n,i,sum);
    printf("\n");
    }
}