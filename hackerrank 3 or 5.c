#include<stdio.h>
void main()
{
int n,sum=0;
int i;
printf("Enter a number:");
scanf("%d",&n);
i=(n-1)/3;
sum=sum+3*(i*(i+1)/2);
i=(n-1)/5;
sum=sum+5*(i*(i+1)/2);
i=(n-1)/15;
sum=sum-15*(i*(i+1)/2);
printf("%d",sum);
}