#include<stdio.h>
#include<math.h>
int factorial(int f);
void armsno(int n);
void palindrome(int p);
int fibanocci(int n);
void rangeofprimes(int m, int n);
extern int sum=0,count=0;
int main()
{
    int i=1,ch,m, n,r,res;
    do
    {
        printf("\n_____________________________________________\n");
        printf("\nPOINTERS");
        printf("\n_____________________________________________\n");
        printf("\nPlease go through the options given below");
        printf("\n\n1.Factorial of a number");
        printf("\n2.Armstrong Number");
        printf("\n3.Palindrome Number");
        printf("\n4.Fibonacci series");
        printf("\n5.Range of Prime numbers");
        printf("\nAny other integer value to EXIT");
        printf("\n\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the number:");
            scanf("%d",&n);
            res=factorial(n);
            printf("The Factorial of %d is:%d",n,res);
            break;
        case 2:
            printf("\nEnter the number:");
            scanf("%d",&n);
            armsno(n);
            break;   
        case 3:
            printf("\nEnter the number:");
            scanf("%d",&n);
            palindrome(n);
            break;
        
        case 4:
            printf("\nEnter the number:");
            scanf("%d",&n);
           fibanocci(n);
            break;
        case 5:
           printf("\nEnter the first and last number:");
            scanf("%d%d",&m,&n);
             rangeofprimes(m,n);
            break;
        
        default:
            goto exit;
        }
        i++;
    }
    while(i<=6);
exit:
    printf("\Thank you!");
}
int factorial(int f)
{
    int fact=1,i=1,*p;
p=&f;
    while(i<=*p)
    {
        fact*=i;
        i++;
    }
    return fact;
}
void rangeofprimes(int m, int n)
{
   int i,found,*p, *q, j;
p=&m;
q=&n;
        for(i=*p; i<=*q; i++)
        {
        found=0;
            for(j=1;j<=i;j++)
            {
            if(i%j==0)
                found=found+1;
            }
        if(found==2)
           printf("%d ",i);
        }
       
        
}
void armsno(int n)
{
    int r,sum=0,temp,*p;
    p=&n;
    temp=*p;
    while(*p>0)
    {
        r=*p%10;
        sum+=r*r*r;
        *p=*p/10;
    }
    if(sum==temp)
        printf("%d is an Armstrong number",temp);
    else
        printf("%d is not an Armstrong number",temp);
}
void palindrome(int p)
{
    int temp,r,rev=0,*q;
    q=&p;
    temp=*q;
    while(*q>0)
    {
        r=*q%10;
        rev=rev*10+r;
        *q=*q/10;
    }
    if(rev==temp)
        printf("%d is Palindrome",temp);
    else
        printf("%d is not a Palindrome",temp);
}
int fibanocci(int n)
{
    int i,f0=0,f1=1,f2, *p;
    p=&n;
    printf("\n%d\t%d",f0,f1);
    for(i=1; i<=*p; i++)
    {
        f2=f0+f1;
        f0=f1;
        f1=f2;
        printf("\t%d",f2);
    }
}