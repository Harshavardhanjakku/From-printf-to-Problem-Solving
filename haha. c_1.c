#include <stdio.h>
int sort(int no,int x[20]);
int comp(int no,int x[20],int z[20]);
void print(int no,int x[20]);
void main()
{
    int n,i,j,temp,a[20],b[20],g[20],h[20],sum,f[20],t[20],c=0,k=0;
    printf("Enter a number of persons:");
    scanf("%d",&n);
    printf("\nEnter the marks of %d students:\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
       b[i]=a[i];
    }
    a[i]=sort(n,a);
   for(i=0; i<n; i++)
    {
            if(a[i]<35)
            {
                f[k]=a[i];
                k+=1;
            }
            if(i>=n-3)
            {
                t[c]=a[i];
                c+=1;
            }
    }
    g[i]=comp(n,f,b);
    h[i]=comp(n,t,b);
    printf("\nThe detained list are:");
   f[i]=sort(k,f);
    print(k,f);
    printf("\nThe toppers list are:");
   t[i]=sort(c,t);
    print(c,t);
}
int sort(int no,int x[20])
{
int i,j,temp,t[20];
for(i=0; i<no-1; i++)
    {
        for(j=i+1; j<no; j++)
        {
            if(x[i]>x[j])
            {
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
            }
        }
    }
return t[i];
}
int comp(int no,int x[20],int z[20])
{
int i,j,y[20],k=0;
for(i=0; i<no; i++)
    {
        for(j=0; j<no; j++)
        {
            if(x[i]==z[j]){y[k]=j+1;
            k+=1;
            }
            
        }
    }
    return y[i];
}
void print(int no,int x[20])
{
int i;
for(i=0;i<no;i++)
{
printf("%d ",x[i]);
}
}