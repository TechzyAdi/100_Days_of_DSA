int maxSubArray(int* nums, int numsSize) {
    
    int currentSum = nums[0];
    int maxSum = nums[0];
    
    for(int i = 1; i < numsSize; i++) {
        
        // Decide whether to continue subarray or start new
        if(currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];
        
        // Update global maximum
        if(currentSum > maxSum)
            maxSum = currentSum;
    }
    
    return maxSum;
}
