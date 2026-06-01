// binary search with bubble sort
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10],size,se,low,high,mid,i,flag=0,j,temp;
	printf("\n enter the size of array:");
	scanf("%d",&size);
	if(size>10)
	{
	printf("\n array overflow");
	}
	else
	{
		printf("\n enter array elements:");
		for(i=0;i<size;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("\n array before sorting:");
		for(i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		for(i=0;i<size-1;i++)
		{
			for(j=0;j<size-1-i;j++)
			{
				if(a[j]>a[j+1])
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
	
		printf("\n enter search element:");
		scanf("%d",&se);
		low=0,high=size-1;
		// binary search logic
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[mid]==se)
			{
				printf("\n element %d found at location a[%d]",se,mid);
				flag=1;
				break;
			}
			else if(se<a[mid])
			{
				high=mid-1;
			}
			else if(se>a[mid])
			{
				low=mid+1;
			}
		}
		if(flag==0)
		{
			printf("\n element not found");
		}
	}
}
