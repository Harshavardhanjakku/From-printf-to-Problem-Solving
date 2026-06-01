#include<stdio.h>
int matmul(int *x,int*y,int*z);
int main()
{
    int a[10][10],b[10][10];
    int c[10][10];
    int m,n,p,q,i,j,k;
    printf("Enter the number of rows of matrix A:");
    scanf("%d",&m);
    printf("Enter the number of cols of matrix A:");
    scanf("%d",&n);
    printf("Enter the number of rows of matrix B:");
    scanf("%d",&p);
    printf("Enter the number of cols of matrix B:");
    scanf("%d",&q);
      if(n==p){
          printf("\nThe matrix multiplication of Matrix A and Matrix B is possible");
        printf("\nEnter the %d elements of matrix A:\n",m*n);
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("\nEnter the %d elements of matrix A:\n",p*q);
        for (i=0; i<p; i++)
        {
            for (j=0; j<q; j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        matmul(&a,&b,&c);
        printf("\nThe matrix pro in main function:\n");
          for (i=0; i<m; i++)
        {
            for (j=0; j<q; j++)
            {
                printf("%d",c[i][j]);
            }
            printf("\n");
        } }
    else
        printf("\nThe matrix multiplication of Matrix A and Matrix B is not possible");
}
int matmul(int *x,int*y,int*z)
{
int m,n,p,q,i,j,k;
for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                printf("%d",*(x+(i*n)+j));
            }
            printf("\n");
        }

for (i=0; i<p; i++)
        {
            for (j=0; j<q; j++)
            {
                printf("%d",*(y+(i*q)+j));
            }
            printf("\n");
        }

    for(i=0; i<m; i++)
    {
        for(j=0; j<q; j++)
        {  
         for(k=0; k<n; k++)
            {
                *(z+(i*q)+j)+=*(x+(i*n)+k)+*(y+(i*k)+j);            }
        }

    }
    printf("\nThe matrix pro in sub function:\n");
    for (i=0; i<m; i++)
        {
            for (j=0; j<q; j++)
            {
                printf("%d",*(z+(i*q)+j));
            }
            printf("\n");
        }
}