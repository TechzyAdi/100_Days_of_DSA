#include <stdlib.h>

// comparator for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// check if we can place m balls with minimum distance = dist
int canPlace(int* pos, int n, int m, int dist) {
    int count = 1;           // first ball placed
    int lastPos = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - lastPos >= dist) {
            count++;
            lastPos = pos[i];

            if (count == m)
                return 1;
        }
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    // sort positions
    qsort(position, positionSize, sizeof(int), compare);

    int left = 1;
    int right = position[positionSize - 1] - position[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;        // valid → try bigger
            left = mid + 1;
        } else {
            right = mid - 1;  // not possible → reduce
        }
    }

    return ans;
}
