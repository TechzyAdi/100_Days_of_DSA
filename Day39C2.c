#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Node;

int compare(const void* a, const void* b)
{
    Node* n1 = (Node*)a;
    Node* n2 = (Node*)b;
    return n2->freq - n1->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    Node arr[10001];
    int count = 0;

    for(int i = 0; i < numsSize; i++)
    {
        int found = 0;

        for(int j = 0; j < count; j++)
        {
            if(arr[j].num == nums[i])
            {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            arr[count].num = nums[i];
            arr[count].freq = 1;
            count++;
        }
    }

    qsort(arr, count, sizeof(Node), compare);

    int* result = malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++)
        result[i] = arr[i].num;

    *returnSize = k;

    return result;
}
