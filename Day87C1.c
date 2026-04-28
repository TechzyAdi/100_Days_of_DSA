#include <stdio.h>

int main() {
    int n, target;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    printf("Enter %d sorted integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target
    printf("Enter target to search: ");
    scanf("%d", &target);

    // Binary Search
    int left = 0, right = n - 1;
    int found = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            found = mid;
            break;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // Output
    if(found != -1)
        printf("Element found at index: %d\n", found);
    else
        printf("Element not found (-1)\n");

    return 0;
}
