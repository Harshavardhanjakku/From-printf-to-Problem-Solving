#include<stdio.h>
void main()
{
    int i, j, k, n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=1; i<=4; i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");//space prints here
     
           }
        for(k=1; k<=i; k++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    
}
