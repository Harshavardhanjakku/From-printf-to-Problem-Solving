#include<stdio.h>
int factorial(int n);
main()
{
int a;
printf("Enter the value of n:");
scanf("%d",&a);
int res=factorial(a);
printf("%d is the factorial",res);
}
factorial(int n)
{
int fact=1;
if(n==1)
return 1;
else
{
fact=n*factorial(n-1);
return fact;
}
}