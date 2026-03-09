#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    if(size == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    pq[size++] = x;
    printf("Element inserted successfully\n");
}

void deleteElement()
{
    if(size == 0)
    {
        printf("-1 (Queue is empty)\n");
        return;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    int deleted = pq[minIndex];

    for(int i = minIndex; i < size-1; i++)
        pq[i] = pq[i+1];

    size--;

    printf("Deleted element: %d\n", deleted);
}

void peek()
{
    if(size == 0)
    {
        printf("-1 (Queue is empty)\n");
        return;
    }

    int min = pq[0];

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
            min = pq[i];
    }

    printf("Highest priority element: %d\n", min);
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                peek();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
