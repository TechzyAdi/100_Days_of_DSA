int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If middle element is greater than rightmost,
        // minimum is in right half
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // Otherwise, minimum is in left half (including mid)
        else {
            right = mid;
        }
    }

    // At the end, left == right → index of minimum
    return nums[left];
}
