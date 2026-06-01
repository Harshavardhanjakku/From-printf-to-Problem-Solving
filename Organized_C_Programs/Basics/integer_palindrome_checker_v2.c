#include<stdio.h>
void main()
{
    int n,r,rev=0,temp;
    printf("Enter the value of n:");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if(rev==temp)
    {
        printf("%d is a palindrome",temp);
    }
    else 
    {
        printf("%d is not a palindrome",temp);
    }
}