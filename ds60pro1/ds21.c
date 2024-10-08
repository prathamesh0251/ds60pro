#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    int* arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; // Return -1 for underflow
    }
    return stack->arr[stack->top--];
}

// Function to display the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int capacity;
    printf("Enter stack capacity: ");
    scanf("%d", &capacity);
    Stack* stack = createStack(capacity);

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                if (isEmpty(stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                if (isFull(stack)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                display(stack);
                break;
            case 6:
                free(stack->arr);
                free(stack);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
