#include<stdio.h>
int main()
{
    int no=4,i,j,temp,min,ind;
    char s[100];
    scanf("%s",s);
    int a[5]={20,15,30,42};
    for (i=0;i<no;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<no-1;i++)
    {
        min=a[i];
        ind=i;
        for(j=i+1;j<no;j++)
        {
            if (a[j]<min)
            {
                ind=j;
                min=a[j];
            }
        }
        if (ind!=i)
        {
            temp=a[i];
            a[i]=a[ind];
            a[ind]=temp;
        }
    }
    for(i=0;i<no;i++)
    {
        printf("%d\n",a[i]);
    }
}