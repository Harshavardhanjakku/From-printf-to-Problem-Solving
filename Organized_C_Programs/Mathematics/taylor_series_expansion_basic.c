#include<stdio.h>
#include<math.h>
void main()
{
    
    float n,x,i,sum=0,sign,xp,fact=1;
    printf("Enter the value of n:");
    scanf("%f",&n);
     printf("Enter the value of x:");
    scanf("%f",&x);
  for(i=1;i<=n;i++)
    {
    sign=pow(-1,n+1);
    xp=pow(x,2*n-2);
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    sum+=sign*(xp/fact);
    }
    printf("The sum of series is :%f",sum);
}