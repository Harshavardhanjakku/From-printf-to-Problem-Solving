//MERGE SORT

#include <stdio.h>
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int a[10], size, i;

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    if (size > 10) {
        printf("\nArray overflow\n");
    } else {
        printf("\nEnter elements:\n");
        for (i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }

        // Array before sorting
        printf("\nArray before sorting:\n");
        for (i = 0; i < size; i++) {
            printf("%d\t", a[i]);
        }

        // Array after sorting
        mergesort(a, 0, size - 1);

        printf("\nArray after sorting:\n");
        for (i = 0; i < size; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }

    return 0;
}
