#include<stdio.h>
void swap();
void hcf();
void palindrome(int p);
void armstrong(int a);
void strong(int s);
int sumofprimes(int sp);
int fibanocci();
int factorial(int f);
int duplicate(int no,int b[20]);
int deleting(int num,int d[20]);
int sorting(int ns,int s[20]);
int trace(int nt,int t[10][10]);
int uppertriangle(int nb,int u[10][10]);
int matrixpro(int nm,int x[10][10],int y[10][10]);//pro means product
main()
{
    int i=1,ch,n,j,res,a[20],mul[10][10],b[10][10],d[10][10];
    do {
        printf("\n_____________________________________________");
        printf("Please go through the choice as shown below:\n");
        printf("\n1.Swapping of two numbers");
        printf("\n2.HCF");
        printf("\n3.Plaindrome");
        printf("\n4.Armstrong");
        printf("\n5.Strong");
        printf("\n6.Sum of Primes b/w 1 to 10");
        printf("\n7.Fibonacci series");
        printf("\n8.Factorial of a Number");
        printf("\n9.Duplicate of a Number");
        printf("\n10.Deleting a Number");
        printf("\n11.Sorting");
        printf("\n12.Trace of a Matrix");
        printf("\n13.Upper triangular");
        printf("\n14.Matrix Multiplication");
        printf("\n15.Exit");
        printf("\n\nPlease enter the integer :\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            swap();
            break;
        case 2:
            hcf();
            break;
        case 3:
            printf("\nEnter the number:");
            scanf("%d",&n);
            palindrome(n);
            break;
        case 4:
            printf("\nEnter the number:");
            scanf("%d",&n);
            armstrong(n);
            break;
        case 5:
            printf("\nEnter the number:");
            scanf("%d",&n);
            strong(n);
            break;
        case 6:
            for(j=1; j<=10; j++)
            {
                n=sumofprimes(j);
            }
            printf("\n%d is the Sum of Primes b/w 1-10",n);
            break;
        case 7:
            fibanocci();
            break;
        case 8:
            printf("\nEnter the value of n:");
            scanf("%d",&n);
            res=factorial(n);
            printf("\nThe factorial of %d is:%d",n,res);
            break;
        case 9:
            printf("How many values u want to store:");
            scanf("%d",&n);
            for(j=0; j<n; j++)
                scanf("%d",&a[j]);
            printf("\nThe duplicate number is:%d",duplicate(n,a));
            break;
        case 10:
            printf("\nHow many values u want to store:");
            scanf("%d",&n);
            printf("\nEnter the values:\n");
            for(j=0; j<n; j++)
            {
                scanf("%d",&a[j]);
            }
            a[j]=deleting(n,a);
            printf("\nThe new array elements are:\n");
            for(j=0; j<n-1; j++)
            {
                printf("%d  ",a[j]);
            }

            break;
        case 11:
            printf("\nHow many values u want to store:");
            scanf("%d",&n);
            printf("\nEnter the values:\n");
            for(j=0; j<n; j++)
            {
                scanf("%d",&a[j]);
            }
            a[j]=sorting(n,a);
            printf("\nThe new array elements are:\n");
            for(j=0; j<n; j++)
            {
                printf("%d  ",a[j]);
            }

            break;
        case 12:
            printf("\nEnter the order of matrix:");
            scanf("%d",&n);
            printf("\nEnter matrix elements:\n");
            for(i=0; i<n; i++)
            {
            for(j=0; j<n; j++)
                {
            scanf("%d",&b[i][j]);
            }
            }
            res=trace(n,b);
            printf("\nThe Trace of the matrix is:%d",res);
            break;
        case 13:
            printf("\nEnter the order of matrix:");
            scanf("%d",&n);
            printf("\nEnter matrix elements:\n");
            for(i=0; i<n; i++)
            {
            for(j=0; j<n; j++)
                {
            scanf("%d",&b[i][j]);
                }
            }
           res=uppertriangle(n,b);
        if(res==0)
        printf("The matrix is Upper triangular");
        else
        printf("The matrix is not Upper triangular");
             break;
        case 14:
            printf("\nEnter the order of matrix:");
            scanf("%d",&n);
            printf("\nEnter X-Matrix elements:\n");
            for(i=0; i<n; i++)
            {
            for(j=0; j<n; j++)
                {
            scanf("%d",&b[i][j]);
                }
            }
            printf("\nEnter Y-Matrix elements:\n");
            for(i=0; i<n; i++)
            {
            for(j=0; j<n; j++)
                {
            scanf("%d",&d[i][j]);
                }
            }
            mul[i][j]=matrixpro(n,b,d);
            printf("\nEnter XY-Matrixpro elements:\n");
            for(i=0; i<n; i++)
            {
            for(j=0; j<n; j++)
                {
            printf("%d  ",b[i][j]);
                }
            printf("\n");
            }
            break;
        case 15:
            break;
        }
        i++;
    }
    while(i<=14);
}
//function definition or called function
void swap()
{
    int a,b;
    printf("\nEnter the value of a and b:");
    scanf("%d%d",&a,&b);
    printf("\nBefore swapping a=%d b=%d",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nAfter swapping a=%d b=%d",a,b);
}
void hcf()
{
    int a,b,gn,hcf,i;//gn=greater number
    printf("\nEnter the value of a and b:");
    scanf("%d%d",&a,&b);
    if(a>b)
        gn=a;
    else
        gn=b;
    for(i=1; i<=gn; i++)
    {
        if(a%i==0&&b%i==0)
            hcf=i;
    }
    printf("The hcf of two numbers %d and %d is:%d",a,b,hcf);
}
void palindrome(int p)
{
    int temp,r,rev=0;
    temp=p;
    while(p>0)
    {
        r=p%10;
        rev=rev*10+r;
        p=p/10;
    }
    if(rev==temp)
        printf("%d is Palindrome",temp);
    else
        printf("%d is not a Palindrome",temp);
}
void armstrong(int a)
{
    int temp,r,rev=0;
    temp=a;
    while(a>0)
    {
        r=a%10;
        rev+=r*r*r;
        a=a/10;
    }
    if(rev==temp)
        printf("%d is Armstrong",temp);
    else
        printf("%d is not an Armstrong",temp);

}
void strong(int s)
{
    int temp,r,sum=0,fact,i,t;
    temp=s;
    while(s>0)
    {
        r=s%10;
        t=r;
        i=1;
        fact=1;
        while(i<=t)
        {
            fact*=i;
            i++;
        }
        sum+=fact;
        s=s/10;
    }
    if(sum==temp)
        printf("\n%d is a Strong Number",temp);
    else
        printf("\n%d is not a Strong Number",temp);
}
int sumofprimes(int sp)
{
    int i=1,count=0,sum;
    if(sp==1)
        sum=0;
    for(i=1; i<=sp; i++)
    {
        if(sp%i==0)
            count+=1;
    }
    if(count==2)
        sum+=sp;
    return sum;
}
int fibanocci()
{
    int n,i,f0=0,f1=1,f2;
    printf("\nEnter the number:");
    scanf("%d",&n);
    printf("\n%d\t%d",f0,f1);
    for(i=1; i<=n; i++)
    {
        f2=f0+f1;
        f0=f1;
        f1=f2;
        printf("\t%d",f2);
    }
}
int factorial(int f)
{
    int fact=1,i=1;

    while(i<=f)
    {
        fact*=i;
        i++;
    }
    return fact;
}
int duplicate(int no,int b[20])
{
    int i,j;
    for(i=0; i<no-1; i++)
        for(j=i+1; j<no; j++)
            if(b[i]==b[j])
                return b[i];
}
int deleting(int num,int d[20])
{
    int i,del;
    printf("\nEnter the number u want to delete:");
    scanf("%d",&del);
    for(i=0; i<num-1; i++)
    {
        if(d[i]==del)
            d[i]=d[i+1];
    }
    return d[i];
}
int sorting(int ns,int s[20])
{
    int i,j,temp;
    for(i=0; i<ns; i++)
    {
        for(j=i+1; j<ns; j++)
            if(s[i]>s[j])
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
    }
    return s[i];
}
int trace(int nt,int t[10][10])
{
    int i,j,sum=0;
    for(i=0; i<nt; i++)
    {
        for(j=0; j<nt; j++)
        {
            if(i==j)
            sum+=t[i][j];
        }

    }
    return sum;
}
int uppertriangle(int nb,int u[10][10])
{
int i,j,flag=0;
for(i=0; i<nb; i++)
    {
        for(j=0; j<nb; j++)
        { if(i<j)
        {
        if(u[i][j]!=0)
            flag+=1;
        }
             }
    }
    return flag;
}
int matrixpro(int nm,int x[10][10],int y[10][10])
{
int i,j,k,c[10][10];
for(i=0; i<nm; i++)
            {
            for(j=0; j<nm; j++)
                {
           c[i][j]=0;
        for(k=0;k<nm;k++)
        c[i][j]+=x[i][k]*y[k][j];
                }
            }
return c[i][j];
}