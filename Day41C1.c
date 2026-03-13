#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    if(front == NULL)
        return -1;

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

int main()
{
    int N, op, value;

    printf("Enter number of operations: ");
    scanf("%d", &N);

    printf("\n1 = Enqueue\n2 = Dequeue\n");

    for(int i = 0; i < N; i++)
    {
        printf("\nEnter operation: ");
        scanf("%d", &op);

        if(op == 1)
        {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if(op == 2)
        {
            printf("%d\n", dequeue());
        }
        else
        {
            printf("Invalid operation\n");
        }
    }

    return 0;
}
