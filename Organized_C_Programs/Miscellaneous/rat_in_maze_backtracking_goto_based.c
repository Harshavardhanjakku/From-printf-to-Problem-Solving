#include<stdio.h>

int main()
{
    int n,i,j,a[10][10],s[10][10];
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
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            s[i][j]=0;
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
    s[0][0]=a[0][0];
    s[n-1][n-1]=a[n-1][n-1];
    i=0;
    j=0;
res:
    {
        if(a[i+1][j]==1)
        {
            s[i+1][j]=1;
            i++;
        }
        else if (a[i][j+1]==1)
        {
            s[i][j+1]=1;
            i++;
        }
    }
if(i<3&&j<3)
goto res;
 printf("\n\nThe maze is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
}