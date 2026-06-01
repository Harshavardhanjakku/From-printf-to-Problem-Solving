// Quick Sort
#include <stdio.h>
void quicksort(int a[], int first, int last);
int main() {
    int a[10], size, i;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    if (size > 10) {
        printf("\nArray overflow");
    } else {
        printf("\nEnter elements: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }
        printf("\nArray before sorting: ");
        for (i = 0; i < size; i++) {
            printf("%d\t", a[i]);
        }
        quicksort(a, 0, size - 1);
        printf("\nArray after sorting: ");
        for (i = 0; i < size; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
    return 0;
}
void quicksort(int a[], int first, int last) {
    int i, j, temp, pivot;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (a[i] <= a[pivot] && i < last) {
                i++;
            }
            while (a[j] > a[pivot]) {
                j--;
            }
            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
