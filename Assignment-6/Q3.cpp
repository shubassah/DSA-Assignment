#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *next;
    struct DNode *prev;
};

struct DNode *head = NULL;

void insertEndDLL(int data) {
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct DNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


int sizeOfDLL() {
    struct DNode *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


struct CNode {
    int data;
    struct CNode *next;
};

struct CNode *chead = NULL;


void insertEndCLL(int data) {
    struct CNode *newNode = (struct CNode *)malloc(sizeof(struct CNode));
    newNode->data = data;

    if (chead == NULL) {
        chead = newNode;
        newNode->next = chead;
        return;
    }

    struct CNode *temp = chead;
    while (temp->next != chead)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = chead;
}


int sizeOfCLL() {
    if (chead == NULL)
        return 0;

    struct CNode *temp = chead;
    int count = 0;

    do {
        count++;
        temp = temp->next;
    } while (temp != chead);

    return count;
}


int main() {
    int choice, data;

    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Doubly Linked List\n");
        printf("2. Circular Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        switch (choice) {
            case 1:
                printf("\n--- Doubly Linked List ---\n");
                insertEndDLL(10);
                insertEndDLL(20);
                insertEndDLL(30);
                insertEndDLL(40);
                printf("Size of Doubly Linked List = %d\n", sizeOfDLL());
                break;

            case 2:
                printf("\n--- Circular Linked List ---\n");
                insertEndCLL(5);
                insertEndCLL(15);
                insertEndCLL(25);
                insertEndCLL(35);
                insertEndCLL(45);
                printf("Size of Circular Linked List = %d\n", sizeOfCLL());
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
