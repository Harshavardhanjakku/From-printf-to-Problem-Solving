#include<stdio.h>
#include<conio.h>
void main()
{
    int m,n,p,q;
    printf("Enter the number of rows of Matrix A:");
    scanf("%d",&m);
    printf("Enter the number of rows of Matrix A:");
    scanf("%d",&n);
    printf("Enter the number of rows of Matrix B:");
    scanf("%d",&p);
    printf("Enter the number of rows of Matrix B:");
    scanf("%d",&q);
    clrscr();

    if (m==p && n==q)
    {
        int a[m][n], b[p][q], c[m][n];
        printf("Enter the Elements of Matrix A:\n");
        for (int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Enter the Elements of Matrix B:\n");
        for (int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        for (int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                c[i][j]=a[i][j]+b[i][j];
            }
        }
        printf("The sum of Matrix A and Matrix B is ");
        for (int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }

    }
}