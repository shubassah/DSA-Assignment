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

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Function to find the Minimum Element (Recursive)
struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root;   
    return findMin(root->left);
}

// Main function
int main() {
    struct Node* root = NULL;
    struct Node* minNode;

    // Inserting elements into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Find minimum element
    minNode = findMin(root);
    if (minNode != NULL)
        printf("Minimum element in BST: %d\n", minNode->data);
    else
        printf("BST is empty.\n");

    return 0;
}
