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
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int idx=0;
    for(int i=m;i<nums1Size;i++)
    {
        nums1[i]=nums2[idx];
        idx++;
    }
    sort(nums1,nums1Size);
}
