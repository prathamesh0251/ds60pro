#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the circular linked list
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
    newNode->next = newNode; // Point to itself for circular nature
    return newNode;
}

// Function to create a circular linked list
Node* createList() {
    int data;
    printf("Enter the first element: ");
    scanf("%d", &data);
    Node* head = createNode(data);
    return head;
}

// Function to insert a node at the end
void insert(Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        Node* newNode = createNode(data);
        Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Complete the circular link
    }
}

// Function to delete a node
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;

    // Check if the node to delete is the head
    if (temp->data == key) {
        // Find the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        // If there's only one node
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
        } else {
            temp->next = (*head)->next; // Point last node to second node
            free(*head);
            *head = temp->next; // Update head
        }
        return;
    }

    // Search for the node to delete
    prev = *head;
    temp = (*head)->next; // Start from the second node
    while (temp != *head) {
        if (temp->data == key) {
            prev->next = temp->next; // Bypass the node
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", key);
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function with menu
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                printf("Circular linked list created.\n");
                break;
            case 2:
                printf("Enter integer to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                printf("Inserted %d into the list.\n", data);
                break;
            case 3:
                printf("Enter integer to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}