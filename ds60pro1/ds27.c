#include <stdio.h>
#include <stdlib.h>

// Definition of the Queue structure
typedef struct Queue {
    int* arr;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

// Function to insert an element into the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    queue->arr[++queue->rear] = item;
    printf("Inserted %d into the queue.\n", item);
}

// Function to delete an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1; // Return -1 for underflow
    }
    return queue->arr[queue->front++];
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int capacity;
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    Queue* queue = createQueue(capacity);

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                free(queue->arr);
                free(queue);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
