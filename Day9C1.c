#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter the code name: ");
    scanf("%s", str);   // no spaces as per problem

    int len = strlen(str);

    printf("Mirror format: ");

    // Print characters in reverse order
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
