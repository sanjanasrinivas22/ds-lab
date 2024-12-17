#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);  
    } else {
        top++;
        stack[top] = value;  
        printf("Pushed %d to the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");  
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;      }
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");  // Stack is empty
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        // Display menu
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:  
                pop();
                break;

            case 3:  
                display();
                break;

            case 4:  
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}
