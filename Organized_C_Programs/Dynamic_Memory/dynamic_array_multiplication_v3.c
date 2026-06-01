#include<stdio.h>
main()
{
    int *a,*c,i,j,n,n2;
    printf("Enter the no of elements :");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("The memory is insufficient.So not allocated memory");
        exit(0);
    }
    else
    {
        printf("\nThe memory is successfully allocated");
        printf("\n\nEnter the elements of Matrix A:\n");

        for(i=0; i<n; i++)
        {
            scanf("%d",a+i);
        }
        printf("\n\nElements of Matrix A:\n");
        for(i=0; i<n; i++)
        {
            printf("%d ",*(a+i));
            printf("\n");
        }
        printf("Enter the New no of elements:");
        scanf("%d",&n2);

        a=(int *)realloc(a,n*sizeof(int));
        printf("Enter %d elements:\n",n2-n);
        for(i=n; i<n2; i++)
        {
            scanf("%d",a+i);
        }
         printf("\n\nTotal Elements of Matrix A:\n");
        for(i=0; i<n2; i++)
        {
            printf("%d ",*(a+i));
            printf("\n");
        }
    }

}