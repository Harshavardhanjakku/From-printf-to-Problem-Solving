#include<stdio.h>
int main( ){
    FILE *fp;
    int i,n;
    fp = fopen ("num.txt", "w");
    for (i =1; i<= 10; i++){
        putw (i, fp);
    }
    fclose (fp);
    fp =fopen ("num.txt", "r");
    printf ("file content is\n");
    for (i =1; i<= 10; i++){
        n= getw(fp);
        printf ("%d",n);
        printf("\n");
    }
    fclose (fp);
    return 0;
}