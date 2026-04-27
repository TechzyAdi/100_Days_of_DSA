#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use long long to avoid overflow
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            ans = mid;        // possible answer
            left = mid + 1;   // move right
        } else {
            right = mid - 1;  // move left
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = integerSqrt(n);

    printf("Integer square root: %d\n", result);

    return 0;
}
