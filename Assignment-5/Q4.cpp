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
    printf(" -> NULL\n");
}


void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse current node’s pointer
        prev = current;         // Move prev forward
        current = next;         // Move current forward
    }

    head = prev;  // Update head to new first node
    printf("\nLinked list reversed successfully!\n");
}


int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("\nOriginal Linked List:\n");
    displayList();

    reverseList();

    printf("\nReversed Linked List:\n");
    displayList();

    return 0;
}
