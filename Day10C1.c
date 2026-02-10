#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome (case-insensitive, ignores non-alphanumeric)
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum((unsigned char)str[left])) left++;
        while (left < right && !isalnum((unsigned char)str[right])) right--;

        // Compare characters ignoring case
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    char s[1001]; // Buffer for input string (up to 1000 chars)

    printf("Enter a word or phrase: ");

    // Read full line including spaces
    if (!fgets(s, sizeof(s), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    // Check palindrome and print result
    if (isPalindrome(s)) {
        printf(" It's a palindrome!\n");
    } else {
        printf("Not a palindrome.\n");
    }

    return 0;
}
