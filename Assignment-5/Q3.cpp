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

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the middle of the linked list
void findMiddle() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Move 'fast' two steps and 'slow' one step at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
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

    displayList();
    findMiddle();

    return 0;
}
