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

void deleteNodeDLL(int key) {
    struct Node *temp = head;


    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }


    if (head->data == key) {
        struct Node *toDelete = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(toDelete);
        printf("Node %d deleted (head node).\n", key);
        return;
    }


    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node %d deleted.\n", key);
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

void deleteNodeCLL(int key) {
    if (chead == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct CNode *curr = chead, *prev = NULL;

  
    if (chead->data == key) {
       
        if (chead->next == chead) {
            free(chead);
            chead = NULL;
            printf("Node %d deleted (only node).\n", key);
            return;
        }

       
        struct CNode *last = chead;
        while (last->next != chead)
            last = last->next;

        last->next = chead->next;
        struct CNode *toDelete = chead;
        chead = chead->next;
        free(toDelete);
        printf("Node %d deleted (head node).\n", key);
        return;
    }

  
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key)
            break;
    } while (curr != chead);

    if (curr == chead) {
        printf("Node %d not found.\n", key);
        return;
    }

    prev->next = curr->next;
    free(curr);
    printf("Node %d deleted.\n", key);
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
            printf("2. Delete Node (e.g., Delete Node 60)\n");
            printf("3. Display List\n");
            printf("4. Back to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (listType) {
                case 1: 
                    switch (choice) {
                        case 1:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertDLL(data);
                            break;
                        case 2:
                            printf("Enter node value to delete: ");
                            scanf("%d", &key);
                            deleteNodeDLL(key);
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

                case 2: 
                    switch (choice) {
                        case 1:
                            printf("Enter data: ");
                            scanf("%d", &data);
                            insertCLL(data);
                            break;
                        case 2:
                            printf("Enter node value to delete: ");
                            scanf("%d", &key);
                            deleteNodeCLL(key);
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
