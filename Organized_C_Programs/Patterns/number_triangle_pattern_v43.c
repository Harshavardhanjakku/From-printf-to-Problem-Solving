#include<stdio.h>

int main()
{
for(int i=5;i>=1;i--)
{
for(int sp=1;sp<=i-1;sp++)
{
printf("  ");
}
for(int k=i;k<=5;k++)
{
printf("%d ",i);
}
printf("\n");
}
}