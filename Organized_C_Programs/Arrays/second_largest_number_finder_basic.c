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

        else
        {
            if(a[i]>gn)
            {
                temp=gn;
                gn=a[i];
                a[i]=temp;
            } 
            else if(temp>sln)
            {
                temp2=sln;
                sln=temp;
                temp=temp2;
            }
            else (a[i]>sln)
            {
                temp2=sln;
                sln=a[i];
                a[i]=temp2;
            }
        }
    }
    printf("the second largest no is:%d",sln);
}