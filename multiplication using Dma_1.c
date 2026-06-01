#include<stdio.h>
main()
{
    int *a,*b,*c,i,j,m,n,p,q,k;
    printf("Enter the no of Rows of Matrix A:");
    scanf("%d",&m);
    printf("Enter the no of Cols of Matrix A:");
    scanf("%d",&n);
    printf("Enter the no of Rows of Matrix B:");
    scanf("%d",&p);
    printf("Enter the no of Cols of Matrix B:");
    scanf("%d",&q);
    a=(int *)malloc((m*n)*sizeof(int));
    b=(int *)malloc((p*q)*sizeof(int));
    if(a==NULL||b==NULL)
    {
        printf("The memory is insufficient.So not allocated memory");
        exit(0);
    }
    else
    {
        printf("\nThe memory is successfully allocated");
        printf("\n\nEnter the elements of Matrix A:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",a+(i*n)+j);
            }
        }
        printf("\nEnter the elements of Matrix B:\n");
        for(i=0; i<p; i++)
        {
            for(j=0; j<q; j++)
            {
                scanf("%d",b+(i*q)+j);
            }
        }
        if(n==p)
        {
            printf("\nThe Matrix multiplication is possible");
            c=(int *)calloc((m,n),sizeof(int));
            for(i=0; i<m; i++)
            {
                for(j=0; j<q; j++)
                {
                    for(k=0; k<p; k++)
                    {
                        *(c+i*q+j)+=*(a+i*n+k)*(*(b+k*q+j));
                    }
                }
            }
            printf("\n\nElements of Matrix A:\n");
            for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",*(a+i*n+j));
            }
            printf("\n");
        }
        printf("\n\nElements of Matrix B:\n");
        for(i=0; i<p; i++)
        {
            for(j=0; j<q; j++)
            {
                printf("%d ",*(b+i*q+j));
            }
            printf("\n");
        }
            printf("\n\nThe Multiplication of two matrices is:\n");
            for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
            {
                printf("%d ",*(c+i*q+j));
            }
            printf("\n");
        }
        }
        else
            printf("The Matrix Multiplication is not possible");
    }

}