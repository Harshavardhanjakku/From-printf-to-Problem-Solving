#include<stdio.h>
void main ()
{
    int a[10][10],b[10][10],i,j,r,c,count=0;
    printf("Enter the no of rows and columns:");
    scanf("%d%d",&r,&c);
    printf("Enter matrix A:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("Enter matrix B:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&b[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    
}