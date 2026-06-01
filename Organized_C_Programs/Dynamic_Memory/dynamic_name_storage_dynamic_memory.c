#include <stdio.h>
#include <stdlib.h>

int main() {
    int no, i;
    char **names;

    printf("Enter the number of names: ");
    scanf("%d", &no);
    names = (char **)malloc(no* sizeof(char *));
    printf("Enter the names:\n");
    for (i = 0; i < no; i++) {
        char n[100];
        scanf("%s", n);
        names[i] = (char *)malloc((strlen(n)+1) * sizeof(char));
        strcpy(names[i], n);
    }
    printf("\nNames:\n");
    for (i = 0; i < no; i++) {
        printf("%s\n", names[i]);
    }
}
    