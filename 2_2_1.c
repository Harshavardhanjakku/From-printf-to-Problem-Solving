#include<stdio.h>
int main()
{
    int n=4,i;
    int a[n],exp=1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    while((max / exp) > 0)
    {
        int op[n],c[10]={0};
        for(i=0;i<n;i++)
        {
            c[(a[i]/exp)%10]++;
        }
        for(i=1;i<10;i++)
        {
            c[i]+=c[i-1];
        }
        for(i=n-1;i>=0;i--)
        {   
            op[c[(a[i]/exp)%10]-1]=a[i];
            c[(a[i]/exp)%10]--;
        }
        for(i=0;i<n;i++)
        {
            a[i]=op[i];
        }
        exp*=10;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}