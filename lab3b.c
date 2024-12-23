#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct CircularQueue {
    int front, rear;
    int arr[MAX];
};

void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

void insert(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

void delete(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! The queue is empty.\n");
    } else {
        int deletedValue = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("Deleted %d from the queue\n", deletedValue);
    }
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main() {
    struct CircularQueue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
