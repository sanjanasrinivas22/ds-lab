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
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct Node* i = *head;
    struct Node* j = NULL;
    int temp;
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    while (1) {
       
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Print List 1\n");
        printf("4. Print List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 into List 1\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        int choice, value, n, i;
        scanf("%d", &choice);
   
   
        switch (choice) {
            case 1:
                printf("Enter value to insert into List 1: ");
                scanf("%d", &value);
                insert(&list1, value);
                break;

            case 2:
                printf("Enter value to insert into List 2: ");
                scanf("%d", &value);
                insert(&list2, value);
                break;

            case 3:
                printf("List 1: ");
                printList(list1);
                break;

            case 4:
                printf("List 2: ");
                printList(list2);
                break;

            case 5:
                sortList(&list1);
                printf("List 1 sorted.\n");
                break;

            case 6:
                reverseList(&list1);
                printf("List 1 reversed.\n");
                break;

            case 7:
                concatenateLists(&list1, &list2);
                printf("Lists concatenated.\n");
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
