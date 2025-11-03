#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}


void countAndDeleteKey(int key) {
    int count = 0;

    // Step 1: Delete key nodes at the beginning
    while (head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        count++;
    }

    // Step 2: Delete key nodes from the rest of the list
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            count++;
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    printf("\nCount: %d\n", count);
    printf("Updated Linked List: ");
    displayList();
}

// Main function
int main() {
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    printf("\nOriginal Linked List: ");
    displayList();

    countAndDeleteKey(key);

    return 0;
}
