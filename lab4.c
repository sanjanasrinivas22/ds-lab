#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(int data) {
    return createNode(data);
}


void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;  
    *head = newNode;        
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;      } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {  
            temp = temp->next;
        }
        temp->next = newNode;  
    }
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  
    int choice, value;

    while(1) {
        
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at the first position\n");
        printf("3. Insert at the end\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to create the list: ");
                scanf("%d", &value);
                head = createList(value);
                printf("Linked list created with value %d\n", value);
                break;
            case 2:
                printf("Enter the value to insert at the first position: ");
                scanf("%d", &value);
                insertAtFirst(&head, value);
                printf("Inserted %d at the first position.\n", value);
                break;
            case 3:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Inserted %d at the end.\n", value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } 

    return 0;
}

