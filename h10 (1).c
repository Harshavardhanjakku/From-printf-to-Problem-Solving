#include<stdio.h>
#include<math.h>
void main()
{

    int xp,n,x,i,sign,j;
    float fact,sum=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter the value of x:");
    scanf("%d",&x);
    for(i=1; i<=n; i++)
    {
        sign=pow(-1,i+1);
        xp=pow(x,2*i-2);
        fact=1;
        for(j=2*i-2;j>0;j--)
        {
            fact=fact*j;
        }
     
        sum+=sign*(xp/fact);
    }
    printf("The sum of series is :%f",sum);
}