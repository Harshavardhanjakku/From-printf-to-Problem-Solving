#include<stdio.h>
int nd(int n);
main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Number of digits in %d is :%d",n,nd(n));
}
int nd(int n)
{
    if(n==0)
        return 0;
    else
    {
return 1+nd(n/10);
    }
    
}