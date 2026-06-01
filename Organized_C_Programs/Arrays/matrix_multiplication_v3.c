#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10],m, n, p, q,i,j,k,*x,*y,*z;
    x=&a[0][0];
    y=&b[0][0];
    z=&c[0][0];
    printf("Enter the no of rows of Matrix A:");
    scanf("%d",&m);
    printf("\nEnter the no of rows of Matrix A:");
    scanf("%d",&n);
    printf("\nEnter the no of rows of Matrix B:");
    scanf("%d",&p);
    printf("\nEnter the no of rows of Matrix B:");
    scanf("%d",&q);
    if(n==p)
    {
        printf("\nMatrix Multiplication is possible ");
        printf("\nEnter the %d elements of Matrix A:\n",m*n);
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",x+(i*n)+j);
            }
        }
        printf("\nEnter the %d elements of Matrix A:\n",p*q);
        for(i=0; i<p; i++)
        {
            for(j=0; j<q; j++)
            {
                scanf("%d",y+(i*q)+j);
            }
        }
        printf("\nThe elements of Matrix A:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",*(x+(i*n)+j));
            }
            printf("\n");
        }
        printf("\nThe elements of Matrix B:\n");
        for(i=0; i<p; i++)
        {
            for(j=0; j<q; j++)
            {
                printf("%d ",*(y+(i*q)+j));
            }
            printf("\n");
        }
        printf("\nThe elements of Matrix C:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
            {
                *(z+(i*q)+j)=0;
                for(k=0; k<p; k++)
                {
                    *(z+(i*q)+j)+=*(x+(i*n)+k)*(*(y+(k*q)+j));
                }
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
            {
                printf("%d ",*(z+(i*q)+j));
            }
            printf("\n");
        }
    }
    else
        printf("\nMatrix Multiplication is not possible");
}