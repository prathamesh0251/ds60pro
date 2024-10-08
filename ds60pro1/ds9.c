#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for operators
typedef struct {
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
    } else {
        printf("Stack underflow!\n");
        return '\0'; // Return null character on underflow
    }
}

// Function to peek the top element of the stack
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Function to determine the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char token = infix[i];

        if (isalnum(token)) { // If the token is an operand
            postfix[j++] = token;
        } else if (token == '(') { // If the token is '('
            push(&stack, token);
        } else if (token == ')') { // If the token is ')'
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        } else { // If the token is an operator
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove trailing newline

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}