#include <stdio.h>

// Function to check Min Heap
int isMinHeap(int arr[], int n) {
    int i;

    // Check only parent nodes
    for (i = 0; i <= (n - 2) / 2; i++) {

        // Left child check
        if (2*i + 1 < n && arr[i] > arr[2*i + 1])
            return 0;

        // Right child check
        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return 0;
    }

    return 1;
}

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in level order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES (It is a Min Heap)");
    else
        printf("NO (Not a Min Heap)");

    return 0;
}
