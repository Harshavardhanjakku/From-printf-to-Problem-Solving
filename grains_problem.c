#include<stdio.h>
#include<math.h>
main()
{
    int i=0;
    unsigned long long int grain;
    unsigned long long int tot=0;
    int box=1;
    while(box<=64)
    {
    grain=pow(2,i);
    tot+=grain;
    printf("\nBox %d :%llu grains",box,grain);
    i++;
    box++;
    }
    printf("\n\nTHE TOTAL NO OF GRAINS:%llu",tot);
}