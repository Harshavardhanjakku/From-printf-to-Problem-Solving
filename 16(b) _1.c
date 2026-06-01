#include<stdio.h>
#include<math.h>
void main()
{
    int n,i,sum=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
    sum+=i*i;
    }
    printf("The sum of series is :%d",sum);
}