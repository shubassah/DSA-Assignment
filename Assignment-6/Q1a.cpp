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


void insertAtBeginningDLL(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtEndDLL(int data) {
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

void insertAfterDLL(int key, int data) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void insertBeforeDLL(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key) {
        insertAtBeginningDLL(data);
        return;
    }

    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;
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


void insertAtBeginningCLL(int data) {
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

    newNode->next = chead;
    temp->next = newNode;
    chead = newNode;
}

void insertAtEndCLL(int data) {
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

void insertAfterCLL(int key, int data) {
    if (chead == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct CNode *temp = chead;
    do {
        if (temp->data == key) {
            struct CNode *newNode = (struct CNode *)malloc(sizeof(struct CNode));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != chead);

    printf("Node with value %d not found.\n", key);
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
            printf("1. Insert at Beginning\n");
            printf("2. Insert at End\n");
            printf("3. Insert After a Node\n");
            printf("4. Insert Before a Node (DLL only)\n");
            printf("5. Display\n");
            printf("6. Back to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (listType) {
                case 1: // Doubly Linked List
                    switch (choice) {
                        case 1:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertAtBeginningDLL(data);
                            break;
                        case 2:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertAtEndDLL(data);
                            break;
                        case 3:
                            printf("Enter key and data: ");
                            scanf("%d%d", &key, &data);
                            insertAfterDLL(key, data);
                            break;
                        case 4:
                            printf("Enter key and data: ");
                            scanf("%d%d", &key, &data);
                            insertBeforeDLL(key, data);
                            break;
                        case 5:
                            displayDLL();
                            break;
                        case 6:
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
                            insertAtBeginningCLL(data);
                            break;
                        case 2:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertAtEndCLL(data);
                            break;
                        case 3:
                            printf("Enter key and data: ");
                            scanf("%d%d", &key, &data);
                            insertAfterCLL(key, data);
                            break;
                        case 4:
                            printf("Not applicable for Circular LL.\n");
                            break;
                        case 5:
                            displayCLL();
                            break;
                        case 6:
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
