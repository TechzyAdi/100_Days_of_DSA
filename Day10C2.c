int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};
    
    // Allocate maximum possible size
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    
    *returnSize = 0;

    // Count elements of nums1
    for (int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    // Find intersection with nums2
    for (int i = 0; i < nums2Size; i++) {
        if (freq[nums2[i]] > 0) {
            result[*returnSize] = nums2[i];
            (*returnSize)++;
            freq[nums2[i]]--;
        }
    }

    return result;
}
