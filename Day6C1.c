#include <stdio.h>

int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) return 0;

  
    int j = 0; 
    for (int i = 0; i < n - 1; i++) {
       
        if (arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
  
    arr[j++] = arr[n-1];

  
    printf("Result: ");
    for (int i = 0; i < j; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
