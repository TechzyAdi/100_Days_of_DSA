#include <ctype.h>

int calculate(char *s)
{
    long num = 0;
    char op = '+';
    long stack[300000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(isdigit(s[i]))
            num = num * 10 + (s[i] - '0');

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0')
        {
            if(op == '+')
                stack[++top] = num;
            else if(op == '-')
                stack[++top] = -num;
            else if(op == '*')
                stack[top] = stack[top] * num;
            else if(op == '/')
                stack[top] = stack[top] / num;

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    for(int i = 0; i <= top; i++)
        result += stack[i];

    return result;
}
