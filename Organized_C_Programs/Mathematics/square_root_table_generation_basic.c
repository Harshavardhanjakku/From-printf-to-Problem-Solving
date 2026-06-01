#include<stdio.h>
#include<math.h>
void main()
{
    int i;
    float j;
  for(i=1,j=i;i<=9,j<=9;i++,j++)
    {
    printf("%d\t%f",i,sqrt(j));
    printf("\n");
    }
}