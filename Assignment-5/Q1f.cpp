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


void deleteSpecificNode(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If list is empty
    if (head == NULL) {
        printf("\nList is empty. No node to delete.\n");
        return;
    }

    // If head itself holds the value
    if (head->data == value) {
        head = head->next;
        printf("\nNode with value %d deleted successfully.\n", value);
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("\nNode with value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    printf("\nNode with value %d deleted successfully.\n", value);
    free(temp);
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Delete Specific Node (by value)\n");
        printf("4. Exit\n");
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
                printf("Enter value of node to delete: ");
                scanf("%d", &value);
                deleteSpecificNode(value);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
