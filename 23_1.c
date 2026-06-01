#include<stdio.h>
void main()
{
    int n,i,count=0,temp;
    printf("Enter the value of n:");
    scanf("%d",&n);
    temp=n;
    for(i=1;i<n;i++)
    {
    if(n%i==0)
    count+=i;
    }
    if(count==temp)
    {
        printf("%d is a perfect number",n);
    }
    else 
    {
        printf("%d is not a perfect number",n);
    }
}