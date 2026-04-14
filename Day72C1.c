#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    
    printf("Enter a string: ");
    scanf("%s", s);

    int visited[26] = {0};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("First repeated character: %c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    printf("-1\n"); // no repeated character
    return 0;
}
