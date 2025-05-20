#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertAtFirst(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtLast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at given position
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted node with value: %d, Address: %p\n", temp->data, (void*)temp);
    free(temp);
}

// Delete last node
void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted node with value: %d, Address: %p\n", head->data, (void*)head);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted node with value: %d, Address: %p\n", temp->next->data, (void*)temp->next);
    free(temp->next);
    temp->next = NULL;
}

// Delete at given position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteAtFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted node with value: %d, Address: %p\n", toDelete->data, (void*)toDelete);
    free(toDelete);
}

// Display list with addresses
void display() {
    struct Node* temp = head;
    printf("\nCurrent Linked List:\n");
    while (temp != NULL) {
        printf("Data: %d, Address: %p ->\n", temp->data, (void*)temp);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtFirst(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtLast(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d%d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteAtFirst();
                break;
            case 5:
                deleteAtLast();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 8);

    return 0;
}
