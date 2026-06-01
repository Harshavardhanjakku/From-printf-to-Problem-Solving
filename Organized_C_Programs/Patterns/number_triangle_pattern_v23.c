#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int i,j;
    for(i=1; i<=2*n-1; i++)
    {
        for(j=1; j<=2*n-1; j++)
        {
            if(i==j||j==2*n-i)
            {
            printf("%d ",abs(i-n)+1);
            }
            else if(i<j && j<2*n-i)
            printf("%d ",abs(n-i)+1);
            else if(i<j && j>2*n-i)
            printf("%d ",abs(n-j)+1);
            else if(i>j && i<2*n-j)
            printf("%d ",abs(n-j)+1);
            else if(i>j && i>2*n-j)
            printf("%d ",abs(n-i)+1);
            else
            continue;
        }
        printf("\n");
    }
}