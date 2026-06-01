#include<stdio.h>
int monthcode(int m);
int centurycode(int c);
int leapyearcode(int l);
int daycode(int d);
int main()
{
int date,month,year,mc,cc,lc,sum;
printf("Enter the date:");
scanf("%d",&date);
printf("Enter the month:");
scanf("%d",&month);
printf("Enter the year:");
scanf("%d",year);
mc=monthcode(month);
sum=date+mc+cc+lc;
sum=add(num1,num2); //function call
printf("sum=%d",sum);
}
int add(int a,int b) //function declarator
{
/* Start of function definition. */
int add;
add=a+b;
return add; //return statement of function 
/* End of function 
definition. */ }