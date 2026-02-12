#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display entered matrix
    printf("\nEntered Matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Check if square
    if(m != n) {
        printf("\nResult: Not a Symmetric Matrix (Matrix is not square)\n");
        return 0;
    }

    // Check symmetric condition
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                printf("\nResult: Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("\nResult: Symmetric Matrix\n");

    return 0;
}
