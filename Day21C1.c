#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("List is empty\n");
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traversing and printing
    printf("\nLinked List elements are:\n");

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
