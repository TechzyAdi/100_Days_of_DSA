#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int tokensSize) {
    
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {

        // If operator
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];  // second operand
            int a = stack[top--];  // first operand
            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;   // truncates toward zero in C

            stack[++top] = result;
        }
        else {
            // Convert string to integer and push
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}
