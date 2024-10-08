#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    char items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, char item) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = item;
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0'; // Return null character on underflow
}

// Function to reverse a string
void reverseString(char* str) {
    Stack stack;
    initStack(&stack);
    int length = strlen(str);

    // Push all characters onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack and overwrite the original string
    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

// Main function
int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}