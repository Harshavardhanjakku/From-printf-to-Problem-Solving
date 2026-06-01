#include<stdio.h>
void main()
{
    int n,r,i,sum=0,fact=1,temp;
    printf("Enter the value of n:");
    scanf("%d",&n);
    temp=n;
    while(n>0)  
    {
    r=n%10;
    fact=1;
    for(i=1;i<=r;i++)
    {
        fact=fact*i;
    }
    sum=sum+fact;
    n=n/10;
    }
 if(sum==temp) 
printf("It is a Strong number");
else
printf("It is not a Strong number");
}