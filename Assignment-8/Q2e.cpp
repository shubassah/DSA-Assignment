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
    newNode->left = newNode->right = NULL;
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


struct Node* findMax(struct Node* node) {
    while (node && node->right != NULL)
        node = node->right;
    return node;
}

// Function to search a node by its value
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Function to find In-order Predecessor of a given node
struct Node* inorderPredecessor(struct Node* root, struct Node* target) {
    if (target->left != NULL)
        return findMax(target->left);

    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

// In-order traversal (for display)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    struct Node* target;
    struct Node* predecessor;
    int key;

   
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order Traversal of BST: ");
    inorder(root);
    printf("\n");

    printf("Enter the node value to find its In-order Predecessor: ");
    scanf("%d", &key);

    target = search(root, key);

    if (target == NULL)
        printf("Node not found in BST.\n");
    else {
        predecessor = inorderPredecessor(root, target);
        if (predecessor != NULL)
            printf("In-order Predecessor of %d is %d\n", key, predecessor->data);
        else
            printf("In-order Predecessor of %d does not exist.\n", key);
    }

    return 0;
}
