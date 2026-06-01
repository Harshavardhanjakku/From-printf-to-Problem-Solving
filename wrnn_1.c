#include <stdio.h>
#include <stdlib.h>
#include<string.h>
main()
{
    int n, i;
    char *ptr;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    ptr= (char *)malloc(n*sizeof(char));
    if(ptr==NULL)
    {
        printf("Memory not allocated.Try again later");
    }
    else
    {
        printf("Enter the names:\n");
        for (i = 0; i < n; i++) {
            char a[100];
            scanf("%s",a);
            strcpy(*(ptr+i),a);
        }
        printf("\nNames:\n");
        for (i = 0; i < n; i++) {
            printf("%s\n",*(p