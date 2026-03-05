#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        if (isalnum(infix[i])) {          // Operand
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {      // Opening bracket
            push(infix[i]);
        }
        else if (infix[i] == ')') {      // Closing bracket
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // remove '('
        }
        else {                            // Operator
            while (top != -1 && 
                   precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
