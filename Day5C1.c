/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/
#include<stdio.h>
void sort(int*,int);
int main(){
    int size1,size2;
    printf("Enter the number of entries in server log 1:");
    scanf("%d",&size1);
    int nums1[size1];
    printf("Enter %d the sorted integers representing arrival times from server 1:\n",size1);
    for(int i=0;i<size1;i++)
    {
        scanf("%d",&nums1[i]);
    }

    printf("Enter the number of entries in server log 2:");
    scanf("%d",&size2);
    int nums2[size2];
    printf("Enter %d the sorted integers representing arrival times from server 2:\n",size2);
    for(int i=0;i<size2;i++)
    {
        scanf("%d",&nums2[i]);
    }

    int n=size1+size2;
    int arr[n],idx=0;
    for(int i=0;i<size1;i++)
    {
        arr[i]=nums1[i];
    }
    for(int i=size1;i<n;i++)
    {
        arr[i]=nums2[idx];
        idx++;
    }

    sort(arr,n);
    
    printf("Array containing all arrival times in chronological order, separated by spaces:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void sort(int* arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++) 
        {
            if(arr[j]>arr[j + 1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
