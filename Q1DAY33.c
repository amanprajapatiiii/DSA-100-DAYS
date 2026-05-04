#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>

#define MAX 100

// Stack declaration
char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

// Pop function
char pop() {
    if (top >= 0)
        return stack[top--];
    return -1;
}

// Function to check precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[]) {
    int i;
    char postfix[MAX];
    int k = 0;  // index for postfix

    for (i = 0; infix[i] != '\0'; i++) {
        
        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        
        // If '(', push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        
        // If ')', pop until '('
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];

    scanf("%s", infix);   // Input infix expression
    infixToPostfix(infix);

    return 0;
}