#include<stdio.h>
void main()
{
    int n,f0=0,f1=1,f2,i;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("%d\t%d",f0,f1);
    for(i=1;i<=n;i++)
    {
    f2=f0+f1;
    printf("\t%d",f2);
    f0=f1;
    f1=f2;
    }
}
   