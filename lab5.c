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


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode;  
    }
}


void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete first element.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;  
    printf("Deleted first element: %d\n", temp->data);
    free(temp);  // Free the memory of the deleted node
}

void deleteElement(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete element.\n");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;  
        printf("Deleted element: %d\n", temp->data);
        free(temp);  
        return;
    }

    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);  
}


void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete last element.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

   
    if (temp->next == NULL) {
        *head = NULL;  
        printf("Deleted last element: %d\n", temp->data);
        free(temp);
        return;
    }

        while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;  
    printf("Deleted last element: %d\n", temp->data);
    free(temp);  // Free the memory of the deleted node
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
    struct Node* head = NULL;      int choice, value;

    while(1) {
        
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at the end\n");
        printf("3. Delete first element\n");
        printf("4. Delete specified element\n");
        printf("5. Delete last element\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
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
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Inserted %d at the end.\n", value);
                break;
            case 3:
                deleteFirst(&head);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteElement(&head, value);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } 

    return 0;
}
