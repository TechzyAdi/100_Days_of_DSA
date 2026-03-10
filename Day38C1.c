#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (rear + 1) % MAX == front;
}

void push_front(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = value;
}

void push_back(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
}

void pop_front()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void pop_back()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;
}

void display()
{
    if(isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    while(1)
    {
        printf("%d ", deque[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void show_front()
{
    if(isEmpty())
        printf("Deque empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void show_back()
{
    if(isEmpty())
        printf("Deque empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

int size()
{
    if(isEmpty())
        return 0;

    if(rear >= front)
        return rear - front + 1;

    return MAX - front + rear + 1;
}

void clear()
{
    front = rear = -1;
    printf("Deque cleared\n");
}

void reverse()
{
    if(isEmpty())
        return;

    int arr[MAX];
    int n = size();
    int i = front;

    for(int j = 0; j < n; j++)
    {
        arr[j] = deque[i];
        i = (i + 1) % MAX;
    }

    for(int j = 0; j < n/2; j++)
    {
        int t = arr[j];
        arr[j] = arr[n-j-1];
        arr[n-j-1] = t;
    }

    front = 0;
    rear = n-1;

    for(int j = 0; j < n; j++)
        deque[j] = arr[j];
}

void sort()
{
    if(isEmpty())
        return;

    int arr[MAX];
    int n = size();
    int i = front;

    for(int j = 0; j < n; j++)
    {
        arr[j] = deque[i];
        i = (i + 1) % MAX;
    }

    for(int a = 0; a < n-1; a++)
    {
        for(int b = 0; b < n-a-1; b++)
        {
            if(arr[b] > arr[b+1])
            {
                int t = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = t;
            }
        }
    }

    front = 0;
    rear = n-1;

    for(int j = 0; j < n; j++)
        deque[j] = arr[j];
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1 Push Front\n");
        printf("2 Push Back\n");
        printf("3 Pop Front\n");
        printf("4 Pop Back\n");
        printf("5 Front Element\n");
        printf("6 Rear Element\n");
        printf("7 Size\n");
        printf("8 Check Empty\n");
        printf("9 Display\n");
        printf("10 Reverse\n");
        printf("11 Sort\n");
        printf("12 Clear\n");
        printf("13 Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                show_front();
                break;

            case 6:
                show_back();
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                if(isEmpty())
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;

            case 9:
                display();
                break;

            case 10:
                reverse();
                printf("Deque reversed\n");
                break;

            case 11:
                sort();
                printf("Deque sorted\n");
                break;

            case 12:
                clear();
                break;

            case 13:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
