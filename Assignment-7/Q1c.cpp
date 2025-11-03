#include <stdio.h>

int main() {
    int n, i, j, temp, flag;
    int A[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Bubble Sort
    for (i = 1; i < n; i++) {
        flag = 1;  

        for (j = 0; j < n - i; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 0; 
            }
        }

        if (flag == 1)
            break; 
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
