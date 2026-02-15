#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    bool firstRowZero = false;
    bool firstColZero = false;
    
    // Step 1: Check first row
    for(int j = 0; j < cols; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    
    // Step 2: Check first column
    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    // Step 3: Use first row & column as markers
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Step 4: Set zeroes based on markers
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Step 5: Handle first row
    if(firstRowZero) {
        for(int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    
    // Step 6: Handle first column
    if(firstColZero) {
        for(int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}
