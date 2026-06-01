#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,k,m,r,c;
    char str[100];
    printf("Enter the relation in a word:");
    scanf("%s",&str);
    n=strlen(str)/2;
    int a[n][n];//static
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            a[i][j]=0;
        }
    }
    i=0;
    while(str[i]!='\0')
    {
        r=str[i]-97;
        i=i+1;
        c=str[i]-97;
        i=i+1;
        a[r][c]=1;
    }
    printf("\n\n the array is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nThe process is:\n");
    for(k=0; k<3; k++)
    {
        for(i=0; i<3; i++)
        {
            if(a[k][i]==1)
            {
                printf("bef for k=%d,i=%d,j=%d the a[%d][%d]=%d\n",k,i,j,i,j,a[i][j]);
                for(j=0; j<=2; j++)
                {

                    if(a[j][k]==1)
                    {
                    printf("aft for k=%d,i=%d,j=%d the a[%d][%d]=1\n",k,i,j,i,j);
                        a[i][j]=1;
                        
                    }
                }
            }


        }
        printf("\n\n For k=%d the array is:\n",k);
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n\n the array is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}