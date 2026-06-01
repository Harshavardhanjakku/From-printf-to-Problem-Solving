#include<stdio.h>
void main()
{
    int i,sq;
    for(i=1; i<=500; i++)
    {
        sq=i*i;
        if(sq<=500)
        {   printf("%d",sq);
            printf("\n");
        }
    }
}
