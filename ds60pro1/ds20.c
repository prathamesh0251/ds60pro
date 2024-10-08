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

// Function to search for an element in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to create a mirror of the tree
Node* mirror(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* newRoot = createNode(root->data);
    newRoot->left = mirror(root->right);
    newRoot->right = mirror(root->left);
    return newRoot;
}

// Function to perform inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    printf("Enter a number to search: ");
    scanf("%d", &data);
    if (search(root, data)) {
        printf("Element %d found in the tree.\n", data);
    } else {
        printf("Element %d not found in the tree.\n", data);
    }

    Node* mirroredTree = mirror(root);
    printf("Inorder Traversal of Mirrored BST: ");
    inorder(mirroredTree);
    printf("\n");

    return 0;
}
