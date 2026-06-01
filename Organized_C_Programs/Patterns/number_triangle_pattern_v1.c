#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,k,m,r,c;
    char str[100];
    printf("Enter the relation in a word:");
    scanf("%s",&str);
    printf("Enter the value of n:");
    scanf("%d",&n);
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
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            if(a[i][k]==1)
            {
                for(j=0; j<n; j++)
                {

                    if(a[k][j]==1)
                    {
                        a[i][j]=1;
                    }
                }
            }
        }
    }
printf("\n\nThe array is:\n");
for(i=0; i<n; i++)
{
    for(j=0; j<n; j++)
    {
        printf("%d ",a[i][j]);
    }
    printf("\n");
}
}