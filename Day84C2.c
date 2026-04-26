int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            // You are in decreasing slope → peak is on left (including mid)
            right = mid;
        } else {
            // Increasing slope → peak is on right
            left = mid + 1;
        }
    }

    return left; // or right (both same here)
}
