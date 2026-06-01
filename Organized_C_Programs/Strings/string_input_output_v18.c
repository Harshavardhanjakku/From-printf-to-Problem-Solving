//4th program
#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,k;
	char a[15],c,b[2][3]={"E1","E2"};
	printf("Enter %s's word :\t",b[0]);
	gets(a);
	n=strlen(a);
	c=a[n-1];
	k=1;
	while(1)
	{
		printf("Enter %s's word :\t",b[k]);
		if(k==0)
		k=1;
		else
		k=0;
		gets(a);
		if(a[0]!=c)
		break;
		else
		{
			n=strlen(a);
			c=a[n-1];	
		}
	}
	printf("\n %s won",b[k]);
}