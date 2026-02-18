/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    int* answer = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Step 1: Store prefix products in answer
    answer[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    
    // Step 2: Multiply with suffix products
    int suffix = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix = suffix * nums[i];
    }
    
    return answer;
}
