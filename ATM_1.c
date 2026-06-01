#include<stdio.h>
main()
{
    int i=0,ch,amount=100000,wamt;
    int rollno=1234,pw=1234,pin;
    printf("Enter the Roll no:");
    scanf("%d",&rollno);
    printf("\nEnter the Password:");
    scanf("%d",&pw);
    do
    {
        if(rollno==pw)
        {
            printf("\n\t\t   ATM");
            printf("\n_____________________________________________");
            printf("\n\nPlease go trough the choice given below");
            printf("\n\n1.Withdrawl");
            printf("\n2.Deposit");
            printf("\n3.Current Balance");
            printf("\n4.Help");
            printf("\nAny Other value to Exit");
            printf("\n\nPlease Enter the choice:");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("\nEnter the Amount:");
                scanf("%d",&wamt);
                if(wamt<=amount)
                {   printf("\nEnter the pin:");
                    scanf("%d",&pin);
                    if(pin==pw)
                    {
                        amount-=wamt;
                        printf("\nThe Transaction of Rs.%d is Successful",wamt);
                        printf("\nTake the money from dispensary slot");
                    }

                }
                else
                    printf("\nInsufficient Balance");
                break;
            case 2:
                printf("\nEnter the Amount:");
                scanf("%d",&wamt);
                if(wamt<=50000)
                {   printf("\nEnter the pin:");
                    scanf("%d",&pin);
                    if(pin==pw)
                    {
                        amount+=wamt;
                        printf("\nThe Deposit of Rs.%d is Successful",wamt);
                    }

                }
                else
                    printf("\nPlease Deposit low amount");
                break;
            case 3:
                printf("\nEnter the pin:");
                scanf("%d",&pin);
                if(pin==pw)
                {

                    printf("\nThe Current Balance is :%d",amount);
                }
                else
                    printf("\nInvalid pin");
                break;
            case 4:
                printf("\nDo you need any help call to 123456789");
                break;
            default:
                goto Exit;

            }
        }
    }
    while(i<=5);
Exit:
    printf("\nThank you for visiting");
}