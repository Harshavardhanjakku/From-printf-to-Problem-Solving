#include<stdio.h>
int main()
{
    int a[4],i,j,temp;
    for(i=0;i<4;i++)
    {scanf("%d",&a[i]);}
    for(i=0;i<4;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]<temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(i=0;i<4;i++)
    {printf("%d",a[i]);
        if(i<3)
        printf("\n");
    }
}