#include <stdio.h>

// Function to merge two halves
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];  // Temporary array

    // Compare and merge both halves
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Copy remaining elements of left half
    while (i <= mid)
        temp[k++] = a[i++];

    // Copy remaining elements of right half
    while (j <= high)
        temp[k++] = a[j++];

    // Copy back merged elements into original array
    for (i = low, j = 0; i <= high; i++, j++)
        a[i] = temp[j];
}

// Merge Sort function
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);       // Sort left half
        mergeSort(a, mid + 1, high);  // Sort right half
        merge(a, low, mid, high);     // Merge the two halves
    }
}

int main() {
    int n, i, a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
