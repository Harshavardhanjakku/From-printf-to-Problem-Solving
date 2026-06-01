#include<stdio.h>
void main()
{
    int n,i,j,sum=0,sumSq=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
    scanf("%d",&j);
    sum+=j;
    sumSq+=j*j;
    }
    printf("Sum of numbers is:%d",sum);
    printf("\nSum of square of numbers is:%d",sumSq);
}