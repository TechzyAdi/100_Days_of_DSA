/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int lo=0,hi=n-1;
    while(lo<hi)
    {
        int temp=arr[lo];
        arr[lo]=arr[hi];
        arr[hi]=temp;
        lo++;
        hi--;
    }

    printf("The reversed will be:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
