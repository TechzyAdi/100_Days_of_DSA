#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL) {
        return newNode;
    }

    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Forward Traversal
void displayForward(struct Node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nDoubly Linked List (Forward Traversal):\n");

    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("No nodes to insert.\n");
        return 0;
    }

    printf("Enter %d values:\n", n);

    for(int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    displayForward(head);

    return 0;
}
