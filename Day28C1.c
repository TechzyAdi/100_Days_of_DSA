#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end in circular linked list
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        return newNode;
    }

    struct Node* temp = head;

    // Traverse till last node
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Function to traverse and print circular linked list
void traverse(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, value;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Circular Linked List elements:\n");
    traverse(head);

    return 0;
}
