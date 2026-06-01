#include<stdio.h>
main()
{
    int a[100],n,i,temp,gn,sln,temp2;
    printf("enter the no of valus u want to store");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(i==0)
            gn=a[i];
        else if(i==1)
        {
            if(a[i]<gn)
                sln=a[i];
        }
        else if(a[i]>gn&&a[i]>sln) 
        {
        temp=gn;
        gn=a[i];
        sln=temp;
        }
        else 
        {
        if(a[i]>sln)
        sln=a[i];
        }
    }
    printf("the second largest no is:%d",sln);
}