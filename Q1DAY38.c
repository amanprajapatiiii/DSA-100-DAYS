#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initDeque(Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

int empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}

void push_front(Deque* dq, int value) {
    Node* newNode = createNode(value);

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

void push_back(Deque* dq, int value) {
    Node* newNode = createNode(value);

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

void pop_front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

int front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->front->data;
}

int back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->rear->data;
}

void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void reverse(Deque* dq) {
    Node* current = dq->front;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        dq->rear = dq->front;
        dq->front = temp->prev;
    }
}

void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_front(&dq, 1);

    printf("Deque elements: ");
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    pop_front(&dq);
    pop_back(&dq);

    printf("After popping: ");
    display(&dq);

    reverse(&dq);
    printf("After reverse: ");
    display(&dq);

    clear(&dq);
    printf("Deque cleared. Empty: %d\n", empty(&dq));

    return 0;
}