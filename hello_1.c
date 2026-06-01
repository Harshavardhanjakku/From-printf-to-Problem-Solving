#include<stdio.h>
void main()
{
char nam[]="HELLO";
for(int i=0;i<=4;i++)
{
for(int j=0;j<=i;j++)
{
printf("%c ",nam[j]);
}
printf("\n");
}
}