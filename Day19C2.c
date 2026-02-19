int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    
    int totalSum = 0;
    
    int currentMax = nums[0];
    int maxSum = nums[0];
    
    int currentMin = nums[0];
    int minSum = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
        
        if(i > 0) {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);
            
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);
        }
    }
    
    // If all elements are negative
    if(maxSum < 0)
        return maxSum;
    
    return max(maxSum, totalSum - minSum);
}
