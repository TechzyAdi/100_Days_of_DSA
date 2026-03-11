#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(heap[parent] > heap[i])
        {
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapifyDown(int i)
{
    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    if(size == MAX)
    {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = x;
    size++;
    heapifyUp(size - 1);

    printf("Inserted: %d\n", x);
}

void extractMin()
{
    if(size == 0)
    {
        printf("-1 (Heap is empty)\n");
        return;
    }

    int min = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    printf("Extracted Min: %d\n", min);
}

void peek()
{
    if(size == 0)
    {
        printf("-1 (Heap is empty)\n");
        return;
    }

    printf("Minimum element: %d\n", heap[0]);
}

void display()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");
    for(int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- MIN HEAP MENU ---\n");
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Peek\n");
        printf("4. Display Heap\n");
        printf("5. Exit\n");

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
                extractMin();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
