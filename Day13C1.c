#include <stdio.h>

int main() {
    int r, c;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("\nSpiral Traversal: ");

    while(top <= bottom && left <= right) {

        //  Traverse top row (Left → Right)
        for(int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        //  Traverse right column (Top → Bottom)
        for(int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        //  Traverse bottom row (Right → Left)
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        //  Traverse left column (Bottom → Top)
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}
