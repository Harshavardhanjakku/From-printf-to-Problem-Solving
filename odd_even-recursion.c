#include<stdio.h>
odd(int n);
even(int n);
main()
{
    odd(1);
}
odd(int n)
{
    if(n<=10)
    {
        printf("%d ",n);
        even(n+1);
    }
    else
        return 10;
}
even(int n)
{   if(n<=10)
    {
        printf("%d ",n);
        odd(n+1);
    }
}
