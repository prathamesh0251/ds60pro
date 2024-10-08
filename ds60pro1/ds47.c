#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* front;
    Node* rear;
} CircularQueue;

// Function to create a circular queue
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* q) {
    return q->front == NULL;
}

// Function to insert an element into the circular queue
void insert(CircularQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // Point rear to front to make it circular
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // Maintain circular nature
    }
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the circular queue
int delete(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete.\n");
        return -1; // Return -1 for underflow
    }
    Node* temp = q->front;
    int item = temp->data;

    if (q->front == q->rear) { // Only one element
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front; // Maintain circular nature
    }
    free(temp);
    return item;
}

// Function to display the circular queue
void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

// Main function
int main() {
    CircularQueue* q = createQueue();

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Check if empty\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(q, value);
                break;
            case 2:
                value = delete(q);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                if (isEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                free(q);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
