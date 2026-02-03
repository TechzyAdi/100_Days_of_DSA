int missingNum(int arr[], int size) {
    long long n = size + 1;
    long long expectedSum = n * (n + 1) / 2;
    long long actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}
