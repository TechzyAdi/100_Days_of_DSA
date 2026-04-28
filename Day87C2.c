long long calculateHours(int* piles, int n, int k) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
        // ceil(piles[i] / k)
        hours += (piles[i] + k - 1) / k;
    }

    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = 0;

    // find max element
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        long long requiredHours = calculateHours(piles, pilesSize, mid);

        if (requiredHours <= h) {
            ans = mid;        // possible answer
            right = mid - 1;  // try smaller speed
        } else {
            left = mid + 1;   // increase speed
        }
    }

    return ans;
}
