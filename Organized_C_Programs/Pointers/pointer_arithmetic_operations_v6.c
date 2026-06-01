#include<stdio.h>
main()
{
    int a,b,i=0,*x;
    char ch;
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
        scanf("%c",&ch);
        x=&ch;
        printf("\nEnter the two numbers:");
        scanf("%d%d",&a,&b);
        switch(ch)
        {
        case '+':
            printf("\nThe Addition is :%d",(a )*x (b) );
            break;
        case '-':
            printf("\nThe Subtraction is :%d",(a) *x( b));
            break;
        case '*':
            printf("\nThe Multiplication is :%d",(a )*x( b) );
            break;
        case '/':
            printf("\nThe Division is :%d",(a) *x (b));
            break;
        case '%':
            printf("The Remainder is :%d",(a )*x (b));
        default:
            goto Exit;
            break;
        }
    }
    while(i<=6);
Exit:
    printf("\nThank You! ");
}