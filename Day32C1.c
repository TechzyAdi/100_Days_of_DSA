#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// Push function
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    top--;
}

// Display function
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Remaining stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}
