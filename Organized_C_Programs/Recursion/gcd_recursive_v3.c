#include<stdio.h>
int gcd(int a,int b) 
{
if(a%b==0) 
{
return b;
}
else if(b%a==0)
{
return a;
}
else
{
if(a>b)
return(b,a%b);
else
return(a,b%a);
}
}

int main()
{
int a,b,gc;
printf("Enter the values of a and b:");
scanf("%d%d",&a,&b);
printf("The gcd of 2 numbers are:%d",gcd(a,b));
}