#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
