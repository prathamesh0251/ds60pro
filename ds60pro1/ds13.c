#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create the linked list
Node* createList(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode; // First node
            tail = newNode;
        } else {
            tail->next = newNode; // Link the new node
            tail = newNode; // Update the tail
        }
    }
    return head;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node* head = createList(n);
    displayList(head);

    // Free allocated memory
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}