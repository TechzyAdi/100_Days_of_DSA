#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if(root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if(temp->left != NULL)
            queue[rear++] = temp->left;

        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    struct Node* nodes[n];

    printf("Enter level order elements (-1 for NULL):\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Create nodes
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Connect nodes
    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    printf("Level Order Traversal:\n");
    levelOrder(nodes[0]);

    return 0;
}
