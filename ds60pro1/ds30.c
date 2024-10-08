#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new element in the BST
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

// Function to get the height of the tree
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print nodes at a given level
void printLevel(Node* node, int level) {
    if (node == NULL) return;
    if (level == 1) {
        printf("%d ", node->data);
    } else if (level > 1) {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

// Function to display the tree level-wise
void displayLevelWise(Node* root) {
    int h = height(root);
    printf("Tree Level-wise:\n");
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

// Main function
int main() {
    Node* root = NULL;
    int n, data;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    displayLevelWise(root);

    // Free allocated memory
    // (Memory deallocation not implemented for brevity)

    return 0;
}
