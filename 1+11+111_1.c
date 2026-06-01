#include<stdio.h>
#include<math.h>
int power(int i)
{
int sum=0;
for(int j=0;j<i;j++)
{
sum=sum+pow(10,j);
}
return sum;
}
void main()
{
int n,sum=0;
printf("Enter a number:");
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
sum=sum+power(i);
}
printf("%d",sum);
}