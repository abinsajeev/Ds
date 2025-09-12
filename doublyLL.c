#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    newNode->prev = NULL;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int value, int position) {
    
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}


void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    free(temp);
    temp->prev->next = NULL;
}


void deleteFromPosition(int position) {
    if (position < 1 || head == NULL) {
        printf("Invalid position or list is empty\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    free(nodeToDelete);
}


void search(int value) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element %d not found in the list\n", value);
}


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display Reverse\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 8:
                display();
                break;
            case 9:
                displayReverse();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
