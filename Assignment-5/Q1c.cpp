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
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert AFTER a node with a given value
void insertAfterValue(int target, int newValue) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nNode with value %d not found.\n", target);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("\nNode %d inserted after %d successfully!\n", newValue, target);
}

// Function to insert BEFORE a node with a given value
void insertBeforeValue(int target, int newValue) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If list is empty
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    // If the target is at the head
    if (head->data == target) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newValue;
        newNode->next = head;
        head = newNode;
        printf("\nNode %d inserted before %d successfully!\n", newValue, target);
        return;
    }

    // Traverse the list
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nNode with value %d not found.\n", target);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->next = temp;
    prev->next = newNode;

    printf("\nNode %d inserted before %d successfully!\n", newValue, target);
}


int main() {
    int choice, value, target;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 2:
                displayList();
                break;

            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &target);
                printf("Enter new value to insert: ");
                scanf("%d", &value);
                insertAfterValue(target, value);
                break;

            case 4:
                printf("Enter value before which to insert: ");
                scanf("%d", &target);
                printf("Enter new value to insert: ");
                scanf("%d", &value);
                insertBeforeValue(target, value);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
