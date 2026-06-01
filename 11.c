#include<stdio.h>
void main()
{
    int i;
    printf("The numbers are:\n");
    for(i=7;i<=100;i++)
    {
        if(i%4==0&&i%5==4&&i%6==4)
        printf("%d\n",i);
    }
    
}