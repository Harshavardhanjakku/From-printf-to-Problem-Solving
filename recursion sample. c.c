#include<stdio.h>
#include<math.h>
int factorial(int n);
int hcf(int a,int b);
odd(int n);
even(int n);
int nd(int n);
int sd(int n);
int fib(int n);
int d(int n);
extern int sum=0,count=0;
main()
{
    int i=1,ch,n,m,res;
    do
    {
        printf("\n_____________________________________________");
        printf("Please go through the choice as shown below:\n");
        printf("\n1.Factorial of a Number");
        printf("\n2.HCF");
        printf("\n3.Printing odd and even numbers b/w 1 to 10");
        printf("\n4.Number of digits in a number");
        printf("\n5.Sum of digits in a umber");
        printf("\n6.Fibonacci series");
        printf("\n7.Converting Binary to decimal");
        printf("\n\n Enter any other value to Exit");
        printf("\n\nPlease enter the integer :\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the value of n:");
            scanf("%d",&n);
            res=factorial(n);
            printf("The factorial of %d iis:%d",n,res);
            break;
        case 2:
           printf("enter the value of p and q");
           	scanf("%d%d",&m,&n);
        	res=hcf(m,n);
        	printf("The hcf of %d and %d is :%d",m,n,res);
            break;
        case 3:
      printf("\nOdd numbers are:\n");
    odd(1);
            break;
        case 4:
           printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Number of digits in %d is :%d",n,nd(n));
            break;
        case 5:
        printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Sum of digits in %d is :%d",n,sd(n));
                 break;
        case 6:
            printf("Enter the value:");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
{
printf("%d   ",fib(i));
	}	
break;
        case 7:
           printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Decimal of %d is :%d",n,d(n));
            break;
            default:
            goto Exit;
        }
        i++;
    }
    while(i<=7);
    Exit:
 {
printf("Thank you! ");
}
    
}
int factorial(int n)
{
int fact=1;
if(n==1)
return 1;
else
{
fact=n*factorial(n-1);
return fact;
}
}
int hcf(int a,int b)
{
int r;
	if(a==1)
	{
	return a;
}
    else
 {
 	r=b%a;
 	if(r==0)
 	return a;
 	else
 	  return hcf(b%a,a);
 }
}
odd(int n)
{
if(n<=10)
    {
        printf("%d ",n);
        odd(n+2);
    }
    else
{
printf("\nEven numbers are:\n");
 even(2);
}
}
even(int n)
{
if(n<=10)
    {
        printf("%d ",n );      
        even(n+2);
    }
}
int nd(int n)
{
if(n==0)
        return 0;
    else
    {
return 1+nd(n/10);
    }
}
int sd(int n)
{
if(n==0)
        return 0;
    else
    {
    int r;
    r=n%10;
return r+nd(n/10);
    }
}
int fib(int n)
{
if(n==0)
		{
			return 0;
		}
		else if(n==1)
		{
			return 1;
		}
		else
		{
			return fib(n-1)+fib(n-2);
		}
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


    