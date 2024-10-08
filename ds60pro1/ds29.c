#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly circular linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Pointing to itself
    newNode->prev = newNode; // Pointing to itself
    return newNode;
}

// Function to insert a node at the end
Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // First node
    }
    
    Node* last = head->prev; // Last node
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

// Function to display the doubly circular linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to delete a node at a given position
Node* deleteNode(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* temp = head;
    int count = 0;

    // Handle deletion of the head
    if (position == 0) {
        if (head->next == head) { // Only one node
            free(head);
            return NULL;
        }

        Node* last = head->prev;
        last->next = head->next;
        head->next->prev = last;
        free(head);
        return last->next; // New head
    }

    // Find the node to delete
    while (temp->next != head && count < position) {
        temp = temp->next;
        count++;
    }

    // If position is out of bounds
    if (count != position) {
        printf("Position out of bounds.\n");
        return head;
    }

    // Delete the node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete a node at given position\n");
        printf("4. Exit\n");
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
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNode(head, position);
                break;
            case 4:
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
