#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count non-leaf nodes
int countNonLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    int leafCount = countLeafNodes(root);
    int nonLeafCount = countNonLeafNodes(root);

    printf("Leaf nodes count: %d\n", leafCount);
    printf("Non-leaf nodes count: %d\n", nonLeafCount);

    return 0;
}
