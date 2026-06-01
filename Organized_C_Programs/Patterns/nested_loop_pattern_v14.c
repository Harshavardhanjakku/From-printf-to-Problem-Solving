#include<stdio.h>
int main()
{
    int ans=0,t=0,n=5;
    int s[n],e[n],temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e[i]);
    }
    for(int k=0;k<5;k++)
    {
        for(int i=0;i<4;i++)
        {
            if(e[i]>=e[i+1])
            {
                temp=e[i];
                e[i]=e[i+1];
                e[i+1]=temp;
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        if(s[i]>=t)
        {
            t=e[i];
            ans+=1;
        }
    }
    printf("%d",ans);
    return 0;
}