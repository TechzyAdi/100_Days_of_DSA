#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Function to count occurrences
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    struct Node* head = createList(n);

    printf("Enter key to count: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);

    printf("%d\n", result);

    return 0;
}
