#include <stdio.h>
#include <conio.h>
void main()
{
int n,i=0,sum=0;
clrscr();
printf("Enter a Number to Find sum of even nos between 1 to n: ");
    scanf("%d",&n);
    while(i<n)
    {
     if(n%i==0)
    {
    sum=sum+i;
    }
    i++;
    }
if(sum==n)
    {
 printf("It is a perfect number");
    }
    else
    {
 printf("It is not a perfect number");
    }
    
getch();
}
    