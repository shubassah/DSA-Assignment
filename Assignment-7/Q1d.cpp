#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);
    return j;
}


void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int main() {
    int n, i;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
