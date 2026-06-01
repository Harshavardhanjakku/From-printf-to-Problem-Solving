#include<stdio.h>
int main()
{
    long int a[10000],b[100000],n,j,i,sum=0,count=0,ue=0;
    scanf("%ld",&n);
    
    for(i=0; i<n; i++)
    {
        scanf("%ld",&a[i]);
    }
    for(i=0; i<n; i++)
    {count=0;
        for(j=0; j<n; j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
        }
        b[i]=count;
    }
    for (i=0;i<n;i++)
    { if(b[i]==1)
      ue=ue+1;
    }
    printf("%ld",ue);
}
