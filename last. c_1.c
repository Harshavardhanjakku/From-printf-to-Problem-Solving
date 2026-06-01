#include<stdio.h>
int monthcode(int m);
int centurycode(int c);
int leapyearcode(int l);
int daycode(int d);
int main()
{
    int date,month,year,mc,cc,lyc,sum,yc,cent,dc;
    printf("Enter the date:");
    scanf("%d",&date);
    printf("Enter the month:");
    scanf("%d",&month);
    printf("Enter the year:");
    scanf("%d",year);
    yc=year%100;
    cent=year/100;
    mc=monthcode(month);
    cc=centurycode(cent);
    lyc=leapyearcode(yc);
    sum=date+mc+cc+yc+lyc;
    dc=daycode(sum);
}
int monthcode(int m)
{
    switch(m)
    {
    case 1:
        m=1;
        break;
    case 2:
        m=4;
        break;
    case 3:
        m=4;
        break;
    case 4:
        m=0;
        break;
    case 5:
        m=2;
        break;
    case 6:
        m=5;
        break;
    case 7:
        m=0;
        break;
    case 8:
        m=3;
        break;
    case 9:
        m=6;
        break;
    case 10:
        m=1;
        break;
    case 11:
        m=4;
        break;
    case 12:
        m=6;
        break;
    }
    return m;
}