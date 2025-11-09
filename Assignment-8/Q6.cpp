#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into max heap (push)
void insert(int value) {
    if (size == MAX) {
        printf("Overflow: Queue is full\n");
        return;
    }

    size++;
    int i = size - 1;
    heap[i] = value;

    // Fix heap by moving up
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify for deletion
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Remove and return highest priority (extract max)
int extractMax() {
    if (size <= 0) {
        printf("Underflow: Queue is empty\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapify(0);
    return max;
}

// Return highest priority element
int getMax() {
    if (size == 0) {
        printf("Queue empty\n");
        return -1;
    }
    return heap[0];
}

// Display queue
void display() {
    if (size == 0) {
        printf("Queue empty\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Insert\n2.Extract Max\n3.Get Max\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                printf("Extracted max: %d\n", extractMax());
                break;

            case 3:
                printf("Max element: %d\n", getMax());
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
