#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ch;
    while(1)
    {
    printf("\n\n\n1.Create");
    printf("\n2.Display");
    printf("\n3.Insert Student");
    printf("\n4.Search Stuednt");
    printf("\n5.Display All");
    printf("\n6.Exit");
    printf("\n\nEnter the choice :");
    scanf("%d",ch);
    switch(ch)
    {
    case 1:
    create();
    break;
    case 2:
    disp();
    break;
    case 3:
    insert();
    break;
    case 4:
    search();
    break;
    case 5:
    display();
    break;
    case 6:
    exit(0);
    break;
    }
    }
}
void create()