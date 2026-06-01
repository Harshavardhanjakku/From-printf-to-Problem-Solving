#include<stdio.h>

int main()
{
    int a[10][10],i,j,k,m,n,temp;
    printf("Enter the number of rows:");
    scanf("%d",&m);
    printf("\nEnter the number of rows:");
    scanf("%d",&n);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix elements are:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(k=0; k<m; k++)
    {
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if (a[k][i]>a[k][j])
                {
                    temp=a[k][i];
                    a[k][i]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
    }
    printf("The matrix elements after sorting are:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}