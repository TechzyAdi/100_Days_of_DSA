#include <string.h>

#define SIZE 10000

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '#';
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

bool isValid(char* s) {
    top = -1;   // reset stack

    for (int i = 0; i < strlen(s); i++) {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else {
            char popped = pop();

            if (popped == '#' || !isMatchingPair(popped, s[i])) {
                return false;
            }
        }
    }

    return (top == -1);
}
