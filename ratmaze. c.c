#include<stdio.h>

int main()
{
    int n,i,j,a[10][10];
    printf("Enter the order of maze:");
    scanf("%d",&n);
    printf("\nEnter the maze elements:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\nThe maze is:\n");
     for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Rat can move in the cells as given below:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
        if(a[i][j]==1||i==0&&j==0||i==n-1||i==n-1&&j==n-1)
        printf("🐀");
        else
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }
   
}