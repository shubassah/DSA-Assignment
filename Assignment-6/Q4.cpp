#include <stdio.h>
#include <stdlib.h>


struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;


void insertEnd(char ch) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = ch;
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


int isPalindrome() {
    if (head == NULL)
        return 1;  

  
    struct Node *start = head;
    struct Node *end = head;
    while (end->next != NULL)
        end = end->next;

   
    while (start != end && end->next != start) {
        if (start->data != end->data)
            return 0; 
        start = start->next;
        end = end->prev;
    }

    return 1; 
}


void displayList() {
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int n, i;
    char ch;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters one by one:\n");
    for (i = 0; i < n; i++) {
        scanf(" %c", &ch); 
        insertEnd(ch);
    }

    displayList();

    if (isPalindrome())
        printf("✅ The Doubly Linked List is a Palindrome.\n");
    else
        printf(" The Doubly Linked List is NOT a Palindrome.\n");

    return 0;
}
