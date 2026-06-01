#include<stdio.h>
int mul(int x, int y);
int main()
{
int n,i;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
    printf("\n%dx%d=%d",n,i,mul(i,n));
}
int mul(int x, int y)
{
return x*y;
}