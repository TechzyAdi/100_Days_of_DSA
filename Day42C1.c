#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

// Enqueue operation
void enqueue(int value)
{
    queue[++rear] = value;
}

// Dequeue operation
int dequeue()
{
    return queue[front++];
}

// Push operation
void push(int value)
{
    stack[++top] = value;
}

// Pop operation
int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    while(front <= rear)
    {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Move stack elements back to queue
    while(top != -1)
    {
        enqueue(pop());
    }

    printf("\nReversed Queue:\n");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
