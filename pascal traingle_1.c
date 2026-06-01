#include<stdio.h>
void main()
{

    int i,rows,j,space, coeff=0;
    printf("Enter the no of rows:");
    scanf("%d",&rows);
    for(i=0; i<rows; i++)
    {
        for(space=01; space<=rows-i; space++)
        {
            printf("  ");
        }

        for(j=0; j<=i; j++)
        {
            if(j==0||i==0) 
            
                coeff=1;
                else
                    coeff=coeff*(i-j+1)/j;
            printf("%d   ",coeff);     
        }
        printf("\n");
    }
}