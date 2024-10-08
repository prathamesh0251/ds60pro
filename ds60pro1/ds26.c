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

// Function to search for a specific element
void search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", key);
}

// Function to delete a specific element
Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Check if the head needs to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Change head
        free(temp); // Free old head
        return head;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return head;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
    return head;
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Search specific element\n");
        printf("4. Delete specific element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 5:
                // Free allocated memory
                while (head != NULL) {
                    Node* next = head->next;
                    free(head);
                    head = next;
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
