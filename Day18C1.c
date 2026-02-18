#include <stdio.h>

void rotateRight(int arr[], int n, int k) {
    k = k % n;   // Handle if k > n

    int temp[100];   // Fixed size array (simple for beginners)

    // Store last k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Store remaining elements
    for(int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    // Copy back to original array
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;
    int arr[100];   // Maximum size = 100

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    rotateRight(arr, n, k);

    printf("Array after rotation:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
