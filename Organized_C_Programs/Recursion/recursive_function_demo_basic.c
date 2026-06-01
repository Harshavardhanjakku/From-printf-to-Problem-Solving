#include<stdio.h>
#include<math.h>
int d(int n);
extern int sum=0,count=0;
main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Decimal of %d is :%d",n,d(n));
}
int d(int n)
{
int power,r;
    if(n==0)
        return 0;
    else
    {
    power=pow(2,count);
    count+=1;
    r=n%10;
    sum=r*power;
    return sum+d(n/10);
    }
    
}