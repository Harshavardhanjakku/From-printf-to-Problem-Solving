#include<stdio.h>
void main()
{
int a[]={1,2,4,6,7,2,4};
int n,lar;
n=sizeof(a)/sizeof(a[0]);
for(int i=0;i<n;i++)
{
if(lar<=a[i])
{
lar=a[i];
}
}
printf("%d",lar);
int sc;
for(int i=0;i<n;i++)
{
if(a[i]<lar&&a[i]>sc)
{
sc=a[i];
}

}
printf("sc:%d",sc);

}