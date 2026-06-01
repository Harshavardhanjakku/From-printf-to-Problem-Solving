#include<stdio.h>
void main()
{
    int n,r,sum=0,temp;
    printf("Enter the value of n:");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        r=n%10;
        sum+=r*r*r;
        n=n/10;
    }
    if(sum==temp)
    {
        printf("%d is an Armstrong number",temp);
    }
    else 
    {
        printf("%d is not an Armstrong number",temp);
    }
}