#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push Function
void push() {
    int value;

    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("Element %d inserted successfully.\n", value);
}

// Pop Function
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    printf("Popped element: %d\n", stack[top]);
    top--;
}

// Display Function
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
