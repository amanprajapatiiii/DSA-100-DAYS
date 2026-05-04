#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0");
        return 0;
    }

    struct Node *head = NULL, *current = NULL, *temp = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        temp = createNode(value);

        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }

        current = temp;
    }

    // Count nodes
    int result = countNodes(head);

    // Print result
    printf("%d", result);

    return 0;
}