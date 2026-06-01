#include<stdio.h>
int odd(int n);
int even(int n);
int main()
{
    printf("The Odd numbers:\n");
    odd(1) ;
}
int odd(int n)
{
if(n<11)
{
printf("%d    ",n);
 odd(n+2) ;
}

else
{
printf("\nThe Even numbers:\n");
even(0) ;
}
}
int even(int n)
{
if(n<11)
{
printf("%d   ",n);
even(n+2) ;
}
}