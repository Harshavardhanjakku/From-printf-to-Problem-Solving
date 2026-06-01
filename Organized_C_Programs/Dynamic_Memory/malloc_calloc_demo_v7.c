#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *multiply(char *num1,char *num2)
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    int *result = (int *)calloc(len1+len2,sizeof(int));
    char *finalResult=(char*) malloc((len1+len2+1)*sizeof(char));
    int i,j,carry,sum;
    for(i=len1-1;i>=0;i--)
    {
        carry=0;
        for(j=len2-1;j>=0;j--)
        {
            sum=(num1[i]-'0')*(num2[j]-'0')+result[i+j+1]+carry;
            carry=sum/10;
            result[i+j+1]=sum%10;
        }
        result[i+j+1]+=carry;
    }
    i=0;
    while(i<len1+len2&&result[i]==0)
    {
        i++;
    }
    for(j=0;i<len1+len2;i++,j++)
    {
        finalResult[j]=result[i]+'0';
    }
    finalResult[j]='\0';
    free(result);
    if(j==0)
    {
        finalResult[0]='0';
        finalResult[1]='\0';
    }
    return finalResult;
}
int main()
{
    char x[]="314159";
    char y[]="271828";
    char * product=multiply(x,y);
    printf("%s\n",product);
    free(product);
    return 0;
}