#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Maximum size of the stack

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1; // Indicates that the stack is empty
}

// Function to check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed onto the stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; // Indicating underflow
    }
    return s->items[(s->top)--];
}

// Main function to demonstrate stack operations
int main() {
    Stack stack;
    initStack(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    while (!isEmpty(&stack)) {
        printf("%d popped from the stack\n", pop(&stack));
    }
    
    return 0;
}