#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // We assume prefix sum range is manageable
    int size = 200001;
    int offset = 100000;

    int *freq = (int*)calloc(size, sizeof(int));

    // Initial prefix sum = 0
    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + offset;

        if(index >= 0 && index < size) {
            count += freq[index];
            freq[index]++;
        }
    }

    printf("\nNumber of subarrays with sum = 0 is: %d\n", count);

    free(freq);

    return 0;
}
