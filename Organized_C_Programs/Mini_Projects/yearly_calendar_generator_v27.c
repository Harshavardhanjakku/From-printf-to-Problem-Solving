#include<stdio.h>
int monthcode(int m);
int centurycode(int c);
int leapyearcode(int l);
int daycode(int d);
int ndinmon(int m,int y);
int main()
{
    int i,j,sp,p,gap,date=1,month,year,mc,cc,lyc,sum,yc,cent,dc,k;
    printf("Enter the month:");
    scanf("%d",&month);
    printf("Enter the year:");
    scanf("%d",&year);
    printf("\n\nThe calendar of ");
    switch(month) 
    {
    case 1:
        printf("JANUARY");
        break;
    case 2:
        printf("FEBRUARY");
        break;
    case 3:
        printf("MARCH");
        break;
    case 4:
        printf("APRIL");
        break;
    case 5:
       printf("MAY");
        break;
    case 6:
        printf("JUNE");
        break;
    case 7:
        printf("JULY");
        break;
    case 8:
        printf("AUGUST");
        break;
    case 9:
     printf("SEPTEMBER");
        break;
    case 10:
        printf("OCTOBER");
        break;
    case 11:
        printf("NOVEMBER");
        break;
    case 12:
        printf("DECEMBER");
        break;
    }
    printf(" %d\n\n\n",year);
    k=ndinmon(month,year);
    for(i=0; i<=6; i++)
    {
        if(i==1)
        {
            yc=year%100;
            cent=year/100;
            mc=monthcode(month);
            cc=centurycode(cent);
            lyc=leapyearcode(yc);
            if(date==1)
            {
                sum=1+mc+cc+yc+lyc;
                dc=daycode(sum);
                sp=dc;
            if(year%4==0&&month==2)
            p=sp-1;
            else
            p=sp;
                for(gap=0; gap<p; gap++)
                    printf("      ");
                for(j=p; j<=6; j++)
                {
                    if(date<10)
                        printf("%d     ",date++);
                    else
                        printf(" %d    ",date++);
                }
            }
        }
        else
        {
            for(j=0; j<=6; j++)
                if(i==0)
                {
                    switch(j)
                    {
                    case 0:
                        printf("Sat   ");
                        break;
                    case 1:
                        printf("Sun   ");
                        break;
                    case 2:
                        printf("Mon   ");
                        break;
                    case 3:
                        printf("Tue   ");
                        break;
                    case 4:
                        printf("Wed   ");
                        break;
                    case 5:
                        printf("Thr   ");
                        break;
                    case 6:
                        printf("Fri   ");
                        break;
                    }
                }
                else
                {
                    yc=year%100;
                    cent=year/100;
                    mc=monthcode(month);
                    cc=centurycode(cent);
                    lyc=leapyearcode(yc);
                    sum=date+mc+cc+yc+lyc;
                    dc=daycode(sum);
                    if(date<10)
                        printf("%d     ",date++);
                    else
                        printf("%d    ",date++);
                    if(date==k+1)
                        goto exit;
                }
        }
        printf("\n");
    }
exit:
    printf("\n\nThank You!");
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
int centurycode(int c)
{
    int r,rcc;//required century code
    r=c%4;
    switch(r)
    {
    case 0:
        rcc=6;
        break;
    case 1:
        rcc=4;
        break;
    case 2:
        rcc=2;
        break;
    case 3:
        rcc=0;
        break;
    }
    return rcc;
}
int leapyearcode(int l)
{
    int nl;
    nl=l/4;
    return nl;
}
int daycode(int d)
{
    d=d%7;
    return d;
}
int ndinmon(int m,int y)
{
    int nd,f,cy;//no do days
    if(m==1)
        nd=31;
    else if(m==2)
    {
        cy=y%400;
        f=y%4;
        if(cy==0)
            nd=29;
        else if(cy!=0&&f==0)
            nd=29;
        else
            nd=28;
    }
    else if(m==3)
        nd=31;
    else if(m==4)
        nd=30;
    else if(m==5)
        nd=31;
    else if(m==6)
        nd=30;
    else if(m==7)
        nd=31;
    else if(m==8)
        nd=31;
    else if(m==9)
        nd=30;
    else if(m==10)
        nd=31;
    else if(m==11)
        nd=3;
    else
        nd=31;
    return nd;
}