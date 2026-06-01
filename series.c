#include<stdio.h>
void main()
{
    int i,j,n,k=1,sum;
    printf("Enter the n:");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        sum=0;
        for(j=1; j<=i; j++)
        {
            sum+=k;
            k++;
        }
        if(i==n)
            printf("The sum is :%d",sum);
    }
}