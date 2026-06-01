//14
#include<stdio.h>
void main()
{
int a,b,i,gn,hcf;
    printf("Enter the two numbers:");
    scanf("%d%d",&a,&b);
    if(a>b)
    gn=a;
    else
    gn=b;
    for(i=1;i<=gn;i++)
    {
    if(a%i==0&&b%i==0)
    hcf=i;
    }
    printf("%d",hcf);
}