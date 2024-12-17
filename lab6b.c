#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", data);
}
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. \n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    printf("%d popped from the stack.\n", temp->data);
    free(temp);
}
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued into the queue.\n", data);
}
void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);
}
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push onto Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue into Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push onto the stack: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;

            case 2:
                pop(&stackTop);
                break;

            case 3:
                displayStack(stackTop);
                break;

            case 4:
                printf("Enter value to enqueue into the queue: ");
                scanf("%d", &value);
                enqueue(&queueFront, &queueRear, value);
                break;

            case 5:
                dequeue(&queueFront, &queueRear);
                break;

            case 6:
                displayQueue(queueFront);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
return 0;
}
