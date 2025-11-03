#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// (a) Search - Recursive approach
struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root; // Found or not found
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (b) Search - Non-Recursive approach
struct Node* searchNonRecursive(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}


int main() {
    struct Node* root = NULL;
    struct Node* result;

   
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);

    // Recursive search
    result = searchRecursive(root, key);
    if (result != NULL)
        printf("Recursive Search: %d found in BST\n", key);
    else
        printf("Recursive Search: %d not found in BST\n", key);

    // Non-recursive search
    result = searchNonRecursive(root, key);
    if (result != NULL)
        printf("Non-Recursive Search: %d found in BST\n", key);
    else
        printf("Non-Recursive Search: %d not found in BST\n", key);

    return 0;
}
