#include<stdio.h>
void main()
{
int n;
float sum=0;
printf("Enter the value of n:");
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
if(i%2==0)
sum=sum-(float)1/i;
else
sum=sum+(float)1/i;

}
printf("the sum:%f",sum);
}

