#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m != n) {
        printf("Primary diagonal is defined only for square matrices.");
        return 0;
    }

    int sum = 0;

    for(int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements = %d", sum);

    return 0;
}
