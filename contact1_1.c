#include<stdio.h>
struct contact 
{
long int cno;
char name[30],e[30];
};
main()
{
struct contact c[100];
int i,n;
printf("Enter the number of persons:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&c[i].cno);
scanf("%s",&c[i].name);
scanf("%s",&c[i].e);
}
long int phno;
printf("Enter the phone number want to search:");
scanf("%ld",&phno);
for(i=0;i<n;i++)
{
if(c[i].cno==phno)
{
printf("%d\n%s\n%s",c[i].cno,c[i].name,c[i].e);
break;
}
}
}