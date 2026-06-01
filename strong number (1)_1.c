#include<stdio.h>
#include<conio.h>
void main() 
{
int n,i=1,r,sum=0,temp,fact;
clrscr();
printf("Enter the value of n:");
scanf("%d",&n);
temp=n;
    while(n>0)
    {
    r=n%10;
        if(r>0)
        {    
            fact=1;
            i=1;
            while(i<=r)
            {
            fact=fact*i;
            i++;
            }
        }
        else
        {
        fact=1;
        }
    sum=sum+fact;
    n=n/10;
    }
if(sum==temp)
{
printf("\n%d is a strong number",temp);
}
else
{
printf("\n%d is not a strong number",temp);
}
getch();
}