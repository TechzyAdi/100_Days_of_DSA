#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nQueue elements (Front to Rear): ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}
