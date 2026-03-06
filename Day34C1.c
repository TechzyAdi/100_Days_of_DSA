#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int evaluatePostfix(char exp[])
{
    int i = 0;

    while(exp[i] != '\0')
    {
        if(exp[i] == ' ')
        {
            i++;
            continue;
        }

        if(isdigit(exp[i]))
        {
            int num = 0;
            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int res;

            switch(exp[i])
            {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
            }

            push(res);
            i++;
        }
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
