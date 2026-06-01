#include <stdio.h>
int getMax(int arr[], int n) {
    int max = arr[0],i;
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int place) {
    int output[n],i;
    int count[10] = {0};
    // Count occurrences of each digit
    for (i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;
    // Update positions based on count
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // Build output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    // Copy output array to original array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n) {
    int max = getMax(arr, n),place;
    for (place = 1; max / place > 0; place *= 10)
        countingSort(arr, n, place);
}
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("After sorting: ");
    printArray(arr, n);

    return 0;
}
