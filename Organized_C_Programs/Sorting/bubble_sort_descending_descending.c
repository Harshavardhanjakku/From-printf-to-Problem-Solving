//bubble sort descending
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,j,a[10],size,temp;
	printf("\n enter the size of array:");
	scanf("%d",&size);
	if (size>10)
	{
		printf("\n overflow");
	}
	else
	{
		printf("\n enter the elements of array:");
		for(i=0;i<size;i++)
		{
			scanf("%d",&a[i]);
		}		
		// array before sorting
		printf("\n array before sorting:");
		for(i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		for(i=0;i<size-1;i++)
		{
			for(j=0;j<size-1-i;j++)
			{
				if(a[j]<a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		// array after sorting
		printf("\n array after sorting:");
		for(i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
	
	}
}
