#include <stdio.h>
#define MAX 5  


typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}


void insert(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (q->front == -1) { // If the queue is empty
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

void delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete element\n");
    } else {
        printf("Deleted %d from the queue\n", q->arr[q->front]);
        q->front++;
        if (q->front > q->rear) {
            
            q->front = q->rear = -1;
        }
    }
}


void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;  
    int choice, value;

    
    initQueue(&q);
	while(1)
      {
        
        printf("\nQueue Operations:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } 

    return 0;
}
