#include<stdio.h>
#include<stdlib.h>
#include"file2.c"
void auto_function();
void static_function();
void register_function();
void extern_function();
main()
{
int a,b,ch;
do {
    printf("\t\t\t----\n");
    printf("\t\t\t1.auto\n");
    printf("\t\t\t2.static\n");
    printf("\t\t\t3.register\n");
    printf("\t\t\t4.extern\n");
    printf("\t\t\t5.exit\n");
    printf("\t\t\t----\n");
    printf("\t\t enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        auto_function();
        break;
    case 2:
        static_function();
        break;
    case 3:
        register_function();
        break;
    case 4:extern_function();
            break;        
    case 5:
        exit(0);
        break;
    default:
        printf("invalid choice");
    }
    }
    while(ch!=5);
}
void auto_function()
{
    auto int a=20,i;
    printf("a=%d\n",a);
    for(i=0; i<3; i++)
    {
        a++;
        printf("%3d",a);
    }
}
void static_function()
{
    static int b,i,x;
    printf("b=%d\n",b);
    for(i=1; i<=3; i++)
    {
        b++;
        printf("%3d",b);
    }
    printf("x=%d\n",x);
}
void register_function()
{
    register int a, i, x;
    printf("a=%d",a);
    for(i=1; i<3; i++)
    {
        a++;
        printf("%3d",a);
    }
    printf("x=%d\n",x);
}
void extern_function()
{
    extern int x=100;
    printf("x=%d",x);
    display();
    printf("\n after display=%d\n",x);
}