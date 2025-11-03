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


struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// (b) Find Maximum Element - Recursive approach
struct Node* findMaxRecursive(struct Node* root) {
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;  // rightmost node is the maximum
    return findMaxRecursive(root->right);
}

// (b) Find Maximum Element - Non-Recursive approach
struct Node* findMaxNonRecursive(struct Node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}


int main() {
    struct Node* root = NULL;
    struct Node* maxNode;

    // Insert elements into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 90);

    // Find maximum element (Recursive)
    maxNode = findMaxRecursive(root);
    if (maxNode != NULL)
        printf("Maximum element (Recursive): %d\n", maxNode->data);

    // Find maximum element (Non-Recursive)
    maxNode = findMaxNonRecursive(root);
    if (maxNode != NULL)
        printf("Maximum element (Non-Recursive): %d\n", maxNode->data);

    return 0;
}
