#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int n, m, i, x;

    // Number of elements to enqueue
    scanf("%d", &n);

    // Enqueue n elements
    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        if(front == -1) {  // first element
            front = rear = 0;
            queue[rear] = x;
        } 
        else {
            rear = (rear + 1) % MAX; // circular increment
            queue[rear] = x;
        }
    }

    // Number of dequeue operations
    scanf("%d", &m);

    // Dequeue m times
    for(i = 0; i < m; i++) {
        if(front == -1) {
            printf("Queue is empty\n");
            return 0;
        }

        if(front == rear) {  // only one element
            front = rear = -1;
        } 
        else {
            front = (front + 1) % MAX; // circular increment
        }
    }

    // Print queue from front to rear
    if(front == -1) {
        printf("Queue is empty");
    } 
    else {
        i = front;
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % MAX;
        }
    }

    return 0;
}