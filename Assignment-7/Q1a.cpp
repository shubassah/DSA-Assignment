#include <stdio.h>

int main() {
    int n, i, j, min, temp;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Selection Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
