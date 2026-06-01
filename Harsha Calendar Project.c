#include<stdio.h>
#include<conio.h>
#include<string.h>
int monthcode(int m);
int centurycode(int c);
int leapyearcode(int l);
int daycode(int d);
int ndinmon(int m,int y);
int main()
{
calendar: 
        {
        clrscr() ;
        printf("WELCOME TO THE CALENDAR PROGRAM");
        printf("\n\n\nPlease go through the choice given below:\n");
                printf("\n1.JANUARY");
                printf("\n2.FEBRUARY");
                printf("\n3.MARCH");
                printf("\n4.APRIL");
                printf("\n5.MAY");
                printf("\n6.JUNE");
                printf("\n7.JULY");
                printf("\n8.AUGUST");
                printf("\n9.SEPTEMBER");
                printf("\n10.OCTOBER");
                printf("\n11.NOVEMBER");
                printf("\n12.DECEMBER");
            
        printf("\n---------------------------------------------");
        int month,year;
        printf("\n\nEnter the month:");
        scanf("%d",&month);
        printf("Enter the year:");
        scanf("%d",&year);
        clrscr() ;
option: {
            int r,i,j,sp,p,gap,date=1,mc,cc,lyc,sum,yc,cent,dc,k;
            char ch[3],y[]="yes",opt,end[]="exit";

            printf("________________________________________");
            printf("\n\n~~The calendar of ");

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
            printf(" %d~~",year);
            printf("\n________________________________________\n\n\n");
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
                        if((year%4==0&&month==2)||(month==1&&year%4==0))               
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
                                goto next;
                        }
                }
                printf("\n");
            }
next:
            {
                printf("\n________________________________________");
                printf("\n________________________________________");
                printf("\n\nDo you want check another month");
                printf("\nIf yes input YES");
                printf("\nEnter Exit to Exit");
                printf("\nAny other value for adjacent calendar");
                printf("\nPlease Enter the choice:");
                scanf("%s",&ch);
                  r=strcasecmp(ch,end);
            if(r==0)
                {clrscr() ;
                    goto last;
                }
                r=strcasecmp(ch,y);
                if(r==0)
                {clrscr() ;
                    goto calendar;
                }
                else
                {
                    printf("\nDo you want to know beside calender");
                    printf("\nInput > for forward and < for Backward");
                    printf("\nEnter the choice:");
                    scanf("%s",&opt);
                    if(opt=='>')
                    {
                        if(month<=11)
                            month+=1;
                        else if(month==12)
                        {
                            month=1;
                            year+=1;

                        }
                        goto option;
                    }
                    else if(ch)
                    {
                        if(month>1)
                            month-=1;
                        else if(month==1)
                               {
            month=12;
                            year-=1;
            }
                            goto option;
                    }
                }
            }
        }
    }
last:
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
        else if(y%100!=0&&f==0)
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
        nd=30;
    else
        nd=31;
    return nd;
}
