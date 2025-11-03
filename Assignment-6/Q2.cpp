#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;  
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}


void displayCircularList() {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Output: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

 
    printf("%d\n", head->data);
}


int main() {
   
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    printf("Circular Linked List: 20 -> 100 -> 40 -> 80 -> 60 -> (back to head)\n");
    displayCircularList();  

    return 0;
}
