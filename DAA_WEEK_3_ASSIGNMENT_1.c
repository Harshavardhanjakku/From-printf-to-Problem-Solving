#include<stdio.h>
int main()
{
    int size,i,sele,mid,high,low,flag=0,a[20];
    char str[50];
    scanf("%s",str);
    scanf("%s",str);
    scanf("%s",str);
    scanf("%d",&size);
    scanf("%s",str);
    scanf("%s",str);
    scanf("%s",str);
    scanf("%s",str);
    for(i=0;i<size;i++)
    scanf("%d",&a[i]);
    scanf("%s",str);
    scanf("%s",str);
    scanf("%d",&sele);
    low=0;high=size;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==sele)
        {
            flag+=1;
            printf("Index %d",mid);
            break;
        }
        else if(a[mid]<sele)
        low=mid+1;
        else
        high=mid-1;
    }
    if(flag==0)
    printf("-1");
    return 0;
}