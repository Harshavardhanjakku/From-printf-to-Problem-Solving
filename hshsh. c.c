#include<stdio.h>
#include<math.h>
void primeno(int n);
void armsno(int n);
void perfectno(int n);
void strongno(int n);
int series1(int n);
void rtap(int n);//right triangle asterisk pattern
void rtnp(int n);//right triangle number pattern
void rtinp(int n);//right t'le increasing no pattern
void etinp(int n);//equi t'le increasing no pattern
void etnp(int n);//equi triangle no pattern
int series(int n);
int series9(int n);
void floydt(int n);
int nd9();
int hcf(int a,int b);
int b2d(int n);
extern int sum=0,count=0;
int main()
{
    int i,ch,n,m,r;
    do
    {
        printf("\n_____________________________________________\n");
        printf("\nPOINTERS");
        printf("\n_____________________________________________\n");
        printf("\nPlease go through the options given below");
        printf("\n\n1.Prime number");
        printf("\n2.Armstrong Number");
        printf("\n3.Perfect Number");
        printf("\n4.Strong Number");
        printf("\n5.Sum of series 1 +11 + 111 + 1111 + .. n");
        printf("\n6.Right angle triangle using asterisk");
        printf("\n7.Right angle triangle repeat a number in a row");
        printf("\n8.Right angle triangle with number increased by 1");
        printf("\n9.Pyramid with numbers increased by 1");
        printf("\n10.Pyramid with a number repeat  in the same row");
        printf("\n11.Sum of the series [ 1-X^2/2!+X^4/4!- .........]");
        printf("\n12.Sum of the series [ 9 + 99 + 999 + 9999 ...]");
        printf("\n13.Floyd's Triangle");
        printf("\n14.Sum of all integer between 100 and 200 which are divisible by 9");
        printf("\n15.HCF (Highest Common Factor)");
        printf("\n16.Binary number to Decimal");
        printf("\nAny other value to EXIT");
        printf("\n\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the number:");
            scanf("%d",&n);
            primeno(n);
            break;
        case 2:
            printf("\nEnter the number:");
            scanf("%d",&n);
            armsno(n);
            break;
        case 3:
            printf("\nEnter the number:");
            scanf("%d",&n);
            perfectno(n);
            break;
        case 4:
            printf("\nEnter the number:");
            scanf("%d",&n);
            strongno(n);
            break;
        case 5:
            printf("\nEnter the number:");
            scanf("%d",&n);
            series1(n);
            break;
        case 6:
            printf("\nEnter the number of rows:");
            scanf("%d",&n);
            rtap(n);
            break;
        case 7:
            printf("\nEnter the number of rows:");
            scanf("%d",&n);
            rtnp(n);
            break;
        case 8:
            printf("\nEnter the number of rows:");
            scanf("%d",&n);
            rtinp(n);
            break;
        case 9:
            printf("\nEnter the number of rows:");
            scanf("%d",&n);
            etinp(n);
            break;
        case 10:
            printf("\nEnter the number of rows:");
            scanf("%d",&n);
            etnp(n);
            break;
        case 11:
            printf("\nEnter the number:");
            scanf("%d",&n);
            series(n);
            break;
        case 12:
            printf("\nEnter the number:");
            scanf("%d",&n);
            series9(n);
            break;
        case 13:
            printf("\nEnter the number of rows:");
            scanf("%d",&n);
            floydt(n);
            break;
        case 14:
            nd9();
            break;
        case 15:
            printf("\nEnter the numbers:");
            scanf("%d%d",&m,&n);
            if(m<n)
            {
            hcf(m,n);
            r=hcf(m,n);
            }
             else
            {
            hcf(n,m);
            r=hcf(n,m);
            }
            
            printf("\nHCF of %d and %d is :%d",m,n,r);
            break;
        case 16:
            printf("\nEnter the binary number:");
            scanf("%d",&n);
            printf("Decimal of %d is :%d",n,b2d(n));
            break;
        default:
            goto exit;
        }
        i++;
    }
    while(i<=17);
exit:
    printf("\Thank you!");
}
void primeno(int n)
{
    {
        int i,found=0;
        for(i=1; i<=n; i++)
        {
            if(n%i==0)
            {
                found=found+1;
            }
        }
        if(found==2)
        {
            printf("\n%d is a Prime number",n);
        }
        else if(found==1)
        {
            printf("\n%d is neither prime or composite",n);
        }
        else
        {
            printf("\n%d composite number",n);
        }

    }
}
void armsno(int n)
{
    int r,sum=0,temp;
    temp=n;
    while(n>0)
    {
        r=n%10;
        sum+=r*r*r;
        n=n/10;
    }
    if(sum==temp)
        printf("%d is an Armstrong number",temp);
    else
        printf("%d is not an Armstrong number",temp);
}
void perfectno(int n)
{

    int i,count=0,temp;
    temp=n;
    for(i=1; i<n; i++)
    {
        if(n%i==0)
            count+=i;
    }
    if(count==temp)
    {
        printf("%d is a perfect number",n);
    }
    else
    {
        printf("%d is not a perfect number",n);
    }

}
void strongno(int n)
{
    int r,i,sum=0,fact=1,temp;
    temp=n;
    while(n>0)
    {
        r=n%10;
        fact=1;
        for(i=1; i<=r; i++)
        {
            fact=fact*i;
        }
        sum=sum+fact;
        n=n/10;
    }
    if(sum==temp)
        printf("%d is a Strong number",temp);
    else
        printf("%d is not a Strong number");

}
int series1(int n)
{

}
void rtap(int n)
{
    int i,k;
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void rtnp(int n)
{
    int i,k;
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=i; k++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
}
void rtinp(int n)
{
    int i, j, k=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%d ",k++);
        }
        printf("\n");
    }
}
void etinp(int n)
{
    int i, j,sp,k=1;
    for(i=1; i<=n; i++)
    {
        for(sp=1; sp<=n-i; sp++)
        {
            printf(" ");//space prints here

        }
        for(j=1; j<=i; j++)
        {
            printf("%d ",k++);
        }
        printf("\n");
    }
}
void etnp(int n)
{
    int i, j, k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");//space prints here

        }
        for(k=1; k<=i; k++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }

}
int series(int n)
{
    int xp,x,i,sign,j;
    float fact,sum=0;
    printf("Enter the value of x:");
    scanf("%d",&x);
    for(i=1; i<=n; i++)
    {
        sign=pow(-1,i+1);
        xp=pow(x,2*i-2);
        fact=1;
        for(j=2*i-2; j>0; j--)
        {
            fact=fact*j;
        }

        sum+=sign*(xp/fact);
    }
    printf("The sum of series is :%f",sum);

}
int series9(int n)
{
}
void floydt(int n)
{
    int i,k;
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=i; k++)
        {
            if((i+k)%2==0)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int nd9()
{

    int i,sum=0;
    printf("\nNumbers between 100 and 200, divisible by 9:\n");
    for(i=100; i<=200; i++)
    {
        if(i%9==0)
        {
            printf("%d   ",i);
            sum+=i;
        }

    }
    printf("\nThe Sum:%d",sum);

}
int hcf(int a,int b)
{
int i,hcf;
for(i=1;i<=b;i++)
{
if(a%i==0&&b%i==0)
hcf=i;
}
return hcf;
}
int b2d(int n)
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
        return sum+b2d(n/10);
    }
}