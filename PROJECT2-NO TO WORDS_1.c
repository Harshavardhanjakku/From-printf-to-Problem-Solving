#include<stdio.h>
#include<conio.h>
void main()
{
    int n,r,rev=0,count=0,nd;
    clrscr();
    printf("Enter the value of n:");
    scanf("%d",&n);
    while(n>0)
    {
        r=n%10;
        rev=rev*10+r;
        n=n/10;
        count+=1;
    }
    nd=count;
    for(nd=count; nd>0; nd--)
    {
        r=rev%10;
        if(nd==4||nd==1)
        {
            switch(r)
            {
            case 1:
                printf("One");
                break;
            case 2:
                printf("Two");
                break;
            case 3:
                printf("Three");
                break;
            case 4:
                printf("Four");
                break;
            case 5:
                printf("Five");
                break;
            case 6:
                printf("Six");
                break;
            case 7:
                printf("Seven");
                break;
            case 8:
                printf("Eight");
                break;
            case 9:
                printf("Nine");
                break;
            }
        }
        if(nd==5||nd==2)
        {
            if(r==1) {
                nd-=1;
                rev=rev/10;
                r=rev%10;
                if(nd==4||nd==1)
                {
                    switch(r)
                    {
                    case 1:
                        printf("eleven");
                        break;
                    case 2:
                        printf("Twelve");
                        break;
                    case 3:
                        printf("Thirteen");
                        break;
                    case 4:
                        printf("Fourteen");
                        break;
                    case 5:
                        printf("Fiveteen");
                        break;
                    case 6:
                        printf("Sixteen");
                        break;
                    case 7:
                        printf("Seventeen");
                        break;
                    case 8:
                        printf("Eighteen");
                        break;
                    case 9:
                        printf("Nineteen");
                        break;
                    }
                }
            }

        }

        if(nd==4)
        {
            printf("Thousand");
        }


        if(nd==5||nd==2)
        {
            switch(r)
            {

            case 2:
                printf("Twenty");
                break;
            case 3:
                printf("Thirty");
                break;
            case 4:
                printf("Forty");
                break;
            case 5:
                printf("Fifty");
                break;
            case 6:
                printf("Sixty");
                break;
            case 7:
                printf("Seventy");
                break;
            case 8:
                printf("Eighty");
                break;
            case 9:
                printf("Ninety");
                break;
            }
            nd-=1;
            rev=rev/10;
            r=rev%10;
            if(nd==4||nd==3||nd==1)
            {
                switch(r)
                {
                case 1:
                    printf("One");
                    break;
                case 2:
                    printf("Two");
                    break;
                case 3:
                    printf("Three");
                    break;
                case 4:
                    printf("Four");
                    break;
                case 5:
                    printf("Five");
                    break;
                case 6:
                    printf("Six");
                    break;
                case 7:
                    printf("Seven");
                    break;
                case 8:
                    printf("Eight");
                    break;
                case 9:
                    printf("Nine");
                    break;
                }
            }
            if(nd==4||nd==5)
            {
                printf("Thousand");
            }
        }
        if(nd==3)
        {
            switch(r)
            {
            case 1:
                printf("One");
                break;
            case 2:
                printf("Two");
                break;
            case 3:
                printf("Three");
                break;
            case 4:
                printf("Four");
                break;
            case 5:
                printf("Five");
                break;
            case 6:
                printf("Six");
                break;
            case 7:
                printf("Seven");
                break;
            case 8:
                printf("Eight");
                break;
            case 9:
                printf("Nine");
                break;
            }
        }
        if(nd==3)
        {
            printf("Hundred");
        }
        rev=rev/10;
    }
    getch();
}