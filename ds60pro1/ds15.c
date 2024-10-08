#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack structure
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack operations
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return 0; // Return 0 for empty stack
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expression) {
    Stack* stack = createStack(100);
    int i;

    for (i = 0; expression[i]; i++) {
        // If the character is a number, push it to the stack
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0'); // Convert char to int
        } else {
            // Pop two elements from stack for the operation
            int val2 = pop(stack);
            int val1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, val1 + val2);
                    break;
                case '-':
                    push(stack, val1 - val2);
                    break;
                case '*':
                    push(stack, val1 * val2);
                    break;
                case '/':
                    push(stack, val1 / val2);
                    break;
            }
        }
    }
    return pop(stack); // The final result will be the only element in the stack
}

// Main function
int main() {
    char expression[100];

    printf("Enter a postfix expression (e.g., 23*54*+): ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}