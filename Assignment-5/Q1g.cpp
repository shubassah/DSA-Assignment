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


void searchNode(int value) {
    struct Node* temp = head;
    int position = 1;
    int found = 0;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    while (temp != NULL) {
        if (temp->data == value) {
            printf("\nNode with value %d found at position %d from head.\n", value, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
        printf("\nNode with value %d not found in the list.\n", value);
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Search for a Node\n");
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
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(value);
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
