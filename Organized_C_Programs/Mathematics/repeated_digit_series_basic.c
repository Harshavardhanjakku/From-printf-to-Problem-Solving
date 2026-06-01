#include<stdio.h>
#include<math.h>
void main()
{
    float x;
    int num,temp,nd=0,ind,temp2,n,i,r,l,d,s, m;
printf("Enter the value of x:");
scanf("%f",&x);
printf("Enter the value of n:");
scanf("%d",&n);
num=x*pow(10,6);
temp=num;
temp2=x;
while(temp2>0)
{
    temp2=temp2/10;
    ind+=1;
}
while(temp>0)
{
    temp=temp/10;
    nd+=1;
}
   l= nd-ind-n;
    for(i=1; i<=l;i++) 
    {
    r=num%10;
    if(r>=5)
    s=num/10+1;
    else 
    s=num/10;
    num=num/10;
    }
    m=pow(10,n);
    printf("\nThe round off number is : %d.%d",s/m,s%m);
}