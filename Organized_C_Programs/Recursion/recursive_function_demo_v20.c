#include<stdio.h>
void rev(char *p,int l);
main()
{
    char str[30];
    int i,len=0;
    printf("Enter the String:");
    scanf("%s",&str);
    i=0;
    while(str[i]!='\0')
    {
        len++;
        i++;
    }
    printf("\nThe String is :%s",str);
    rev(&str,len);
}
void rev(char *p,int n)
{
    int i=0;
    char temp;
    while(i<(n/2+1))
    {
        temp=*(p+i);
        *(p+i)=*(p+(n-i-1));
        *(p+(n-i-1))=temp;
        i++;
    }
    printf("\nThe reverse of string is :");
    for(i=0; i<n; i++)
    {
        printf("%c",*(p+i));
    }
}