#include<stdio.h>
main()
{
    int a,b,*p,*q,i=0,ch;
    do
    {
        printf("\n\nARITHMETIC OPERATIONS");
        printf("\n___________________________________________");
        printf("\n\nPlease go through the options given below");
        printf("\n\nEnter the character for Arithmetic Operations");
        printf("\n\n 1.Addition");
        printf("\n 2.Subtraction");
        printf("\n 3.Multiplication");
        printf("\n 4.Division");
        printf("\n 5.Modulo(Remainder)");
        printf("\n\nAny other value for Exit");
        printf("\n\n\tEnter the choice:");
        scanf("%d",&ch);
        printf("\nEnter the two numbers:");
        scanf("%d%d",&a,&b);
        p=&a;
        q=&b;
        switch(ch)
        {
        case 1:
            printf("\nThe Addition is :%d",(*p)+(*q));
            break;
        case 2:
            printf("\nThe Subtraction is :%d",(*p)-(*q));
            break;
        case 3:
            printf("\nThe Multiplication is :%d",(*p)*(*q));
            break;
        case 4:
            printf("\nThe Division is :%d",(*p)/(*q));
            break;
        case 5:
            printf("The Remainder is :%d",*p%*q);
        default:
            goto Exit;
            break;
    }
}
while(i<=6);
Exit:
printf("\nThank You! ");
}