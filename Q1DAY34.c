#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    char *token = strtok(exp, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0])) {
            push(atoi(token));
        }
        // If operator
        else {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expression[100];

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluatePostfix(expression);

    printf("Result: %d\n", result);

    return 0;
}