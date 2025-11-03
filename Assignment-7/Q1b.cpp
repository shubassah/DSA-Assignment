#include <stdio.h>

int main() {
    int n, i, j, temp;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i;
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = temp;
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
