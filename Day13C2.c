#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int total = rows * cols;
    int* result = (int*)malloc(total * sizeof(int));
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    int index = 0;
    
    while(top <= bottom && left <= right) {
        
        // 1. Traverse top row (Left → Right)
        for(int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;
        
        // 2. Traverse right column (Top → Bottom)
        for(int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;
        
        // 3. Traverse bottom row (Right → Left)
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }
        
        // 4. Traverse left column (Bottom → Top)
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }
    
    *returnSize = total;
    return result;
}
