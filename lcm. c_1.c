#include<stdio.h>
int lcm(int,int,int) ;
int main()
{
    int a, b,ln;
    printf("Enter the two numbers:");
    scanf("%d%d",&a,&b);
    if(a<b)
        ln=a;
    else
        ln=b;
    printf("\nThe lcm of %d and %d is :%d",a,b,lcm(ln,a,b));
}
int lcm(int i,int a,int b)
{
    int gn;
    if(a<b)
        gn=a;
    else
        gn=b;
    if(i%a==0&&i%b==0)
        return i;
    else
    {
        return lcm(i+gn,a,b);
    }
}