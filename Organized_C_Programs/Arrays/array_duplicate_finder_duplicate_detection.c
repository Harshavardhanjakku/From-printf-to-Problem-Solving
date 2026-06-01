#include<stdio.h>
void main()
{

    int i,n,j, a[15];
    printf("Enter the no of values u want to store:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[j]==a[i]) 
           printf(" %d is the duplicate number",a[i]);     
        }
    }
}