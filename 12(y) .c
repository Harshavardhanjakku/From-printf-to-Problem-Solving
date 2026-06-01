#include<stdio.h>
#include<math.h>
void main()
{
    
    float n,i,sum=0;
    printf("Enter the value of n:");
    scanf("%f",&n);
  for(i=1;i<=n;i++)
    {
    sum=sum+1/pow(i,i);
    }
    printf("The sum of series is :%f",sum);
}