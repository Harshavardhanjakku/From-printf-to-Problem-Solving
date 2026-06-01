#include<stdio.h>
main()
{
    int a[10],b[10],m,n,i,j,found=0;
    printf("Enter the size of A:");
    scanf("%d",&m);
    printf("\nEnter the %d elements:\n",m);
    for(i=0; i<m; i++)
        scanf("%d",&a[i]);
    printf("Enter the size of B:");
    scanf("%d",&n);
    printf("\nEnter the %d elements:\n",n);
    for(i=0; i<n; i++)
        scanf("%d",&b[i]);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i]=b[j])
            {
                found+=1;
                break;
            }
        }
    }
    if(found==m)
    printf("\nThe matrix A is Subset to matrix B");
    else
    printf("\nThe matrix A is not Subset to matrix B");
}
