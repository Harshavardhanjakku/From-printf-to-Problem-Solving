#include<stdio.h>
int main()
{
	int arr[]= {87,67,21,59,99,46,84,32,43,12,90,23};
	int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	quicksort(arr,0,n-1);
	for(i=0; i<n-1; i++)
	{
		printf("%d\n",arr[i]);
	}
	printf("%d",arr[i]);
	return 0;
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[low];
	int i=low;
	int j=high;
	while(i<j)
	{
		while(arr[i]<=pivot&&i<=high-1)
		{
			i++;
		}
		while(arr[j]>pivot && j>=low+1)
		{
			j--;
		}
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[low],&arr[j]);
	return j;
}
void quicksort(int arr[],int low,int high)
{
	if (low<high)
	{
		int pI=partition(arr,low,high);
		quicksort(arr,low,pI-1);
		quicksort(arr,pI+1,high);
	}
}