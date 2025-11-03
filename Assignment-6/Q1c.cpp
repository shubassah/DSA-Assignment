#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


struct CNode {
    int data;
    struct CNode *next;
};

struct Node *head = NULL;       
struct CNode *chead = NULL;    


void insertDLL(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void searchDLL(int key) {
    struct Node *temp = head;
    int pos = 1, found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node %d found at position %d in Doubly Linked List.\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Node %d not found in Doubly Linked List.\n", key);
}

void displayDLL() {
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertCLL(int data) {
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

void searchCLL(int key) {
    if (chead == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct CNode *temp = chead;
    int pos = 1, found = 0;

    do {
        if (temp->data == key) {
            printf("Node %d found at position %d in Circular Linked List.\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != chead);

    if (!found)
        printf("Node %d not found in Circular Linked List.\n", key);
}

void displayCLL() {
    if (chead == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct CNode *temp = chead;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != chead);
    printf("(Back to head)\n");
}


int main() {
    int choice, listType, data, key;

    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Doubly Linked List\n");
        printf("2. Circular Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &listType);

        if (listType == 3)
            break;

        while (1) {
            printf("\n--- Operations Menu ---\n");
            printf("1. Insert Node\n");
            printf("2. Search Node\n");
            printf("3. Display List\n");
            printf("4. Back to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (listType) {
                case 1: // Doubly Linked List
                    switch (choice) {
                        case 1:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertDLL(data);
                            break;
                        case 2:
                            printf("Enter node value to search: ");
                            scanf("%d", &key);
                            searchDLL(key);
                            break;
                        case 3:
                            displayDLL();
                            break;
                        case 4:
                            goto exit_loop;
                        default:
                            printf("Invalid choice.\n");
                    }
                    break;

                case 2: // Circular Linked List
                    switch (choice) {
                        case 1:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertCLL(data);
                            break;
                        case 2:
                            printf("Enter node value to search: ");
                            scanf("%d", &key);
                            searchCLL(key);
                            break;
                        case 3:
                            displayCLL();
                            break;
                        case 4:
                            goto exit_loop;
                        default:
                            printf("Invalid choice.\n");
                    }
                    break;
            }
        }
        exit_loop: ;
    }

    return 0;
}
