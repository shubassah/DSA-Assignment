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

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to find the minimum value node in BST
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Function to search a node by value
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Function to find the In-order Successor of a given node in BST
struct Node* inorderSuccessor(struct Node* root, struct Node* target) {
    if (target->right != NULL)
        return findMin(target->right);

    struct Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

// In-order traversal
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
    struct Node* successor;
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

    printf("Enter the node value to find its In-order Successor: ");
    scanf("%d", &key);

    target = search(root, key);

    if (target == NULL)
        printf("Node not found in BST.\n");
    else {
        successor = inorderSuccessor(root, target);
        if (successor != NULL)
            printf("In-order Successor of %d is %d\n", key, successor->data);
        else
            printf("In-order Successor of %d does not exist.\n", key);
    }

    return 0;
}
