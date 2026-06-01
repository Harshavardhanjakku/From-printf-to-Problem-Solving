#include<stdio.h>
void main()
{
    int n,r,rev;
    printf("Enter the value of n:");
    scanf("%d",&n);
    rev=0;
    while(n>0)  
    {
    r=n%10;
    rev=rev*10+r;
    n=n/10;
    }
    printf("The reverse of number is :%d",rev);
}