#include<stdio.h>
#include<string.h>
void palindrome(char string[30]);
main()
{
    char word[30];
    printf("Enter the word :");
    gets(word);
    palindrome(word);
}
void palindrome(char string[30])
{
    int i=0,l=0,count=0,flag=0;
    char rev[30],temp[30];
    i=0;
    count=0;
    while(string[i]!='\0')
    {
    
        temp[count]=string[i];//copying the string
        count+=1;//length of the string
        i++;
    }
    l=count;//assigning the length
    i=l-1;
    count=0;
    while(i>=0)
    {
    rev[count]=string[i];//copying reverse
    count+=1;
    i--;
    }
    count=0;
    while(count<l)
    {
        if(temp[count]!=rev[count])
        {
            flag+=1;
            break;
        }
        count++;
    }
if(flag==0)
printf("\nIt is palindrome");
else
printf("\nIt is not a palindrome");
}