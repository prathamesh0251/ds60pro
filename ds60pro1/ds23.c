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

// Function to insert a node at the end
Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to concatenate two linked lists
Node* concatenate(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2; // Link the last node of list1 to the head of list2
    return list1;
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
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n1, n2, data;

    printf("Enter the number of nodes for list 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        list1 = insert(list1, data);
    }

    printf("Enter the number of nodes for list 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        list2 = insert(list2, data);
    }

    Node* concatenatedList = concatenate(list1, list2);
    displayList(concatenatedList);

    // Free allocated memory
    Node* current = concatenatedList;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
