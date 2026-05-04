#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node
struct Queue {
    struct Node* data;
    struct Queue* next;
};

// Queue operations
struct Queue *front = NULL, *rear = NULL;

void enqueue(struct Node* root) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = root;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

struct Node* dequeue() {
    if (front == NULL)
        return NULL;

    struct Queue* temp = front;
    struct Node* node = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return node;
}

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (front != NULL) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}