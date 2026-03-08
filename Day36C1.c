#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;

void enqueue(int value)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % size;
    queue[rear] = value;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nQueue elements from front to rear:\n");

    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
}

int main()
{
    int n, m, element;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    size = MAX;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        enqueue(element);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}
