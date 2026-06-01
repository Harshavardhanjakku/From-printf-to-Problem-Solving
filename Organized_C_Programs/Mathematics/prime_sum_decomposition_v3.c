//Expressing a number into sum of primes
#include <stdio.h>
#include <conio.h>
void main()
{
    int n,i=1,j,count=0,k, p;
    clrscr();
    printf("Enter a Number:");
    scanf("%d",&n);
    for(i=1; i<n-1; i++)
    {
    count=0;
        p=i;
        for(k=1; k<=p; k++)
        {
            if(p%k==0)
                count+=1;
        }
        if(count==2)
        {
            j=n-i;
            count=0;
        for(k=1; k<=j; k++)
        {
            if(j%k==0)
                count+=1;
        }
        
        }
        if(count==2)
            printf("%d  %d\n",i,j);
        
    }
    getch();
}
