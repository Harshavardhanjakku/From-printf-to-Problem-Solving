#include <stdio.h>
int main()
{
    int m,n,p,q;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&p);
    scanf("%d",&q);
    if (n!=p)
    {
        printf("It is not possible");
    }
    else
    {
        int a[m][n],b[p][q];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<q; j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        int c[2][2];
        int p,q,r,s,t,u,v;
        p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
        q=b[0][0]*(a[1][0]+a[1][1]);
        r=a[0][0]*(b[0][1]-b[1][1]);
        s=a[1][1]*(b[1][0]-b[0][0]);
        t=b[1][1]*(a[0][0]+a[0][1]);
        u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
        v=(b[1][0]+b[1][1])*(a[0][1]-a[1][1]);
        c[0][0]=p+s-t+v;
        c[0][1]=r+t;
        c[1][0]=q+s;
        c[1][1]=p+r-q+u;
        for(int i=0;i<2;i++)
        {
               for(int j=0;j<2;j++)
        {
        printf("%d ",c[i][j]);
        }
        printf("\n");
        }
    }
}