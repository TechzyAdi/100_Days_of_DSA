#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest* obj, int i)
{
    while(i > 0)
    {
        int p = (i - 1) / 2;
        if(obj->heap[p] > obj->heap[i])
        {
            swap(&obj->heap[p], &obj->heap[i]);
            i = p;
        }
        else break;
    }
}

void heapifyDown(KthLargest* obj, int i)
{
    while(1)
    {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if(l < obj->size && obj->heap[l] < obj->heap[smallest])
            smallest = l;

        if(r < obj->size && obj->heap[r] < obj->heap[smallest])
            smallest = r;

        if(smallest != i)
        {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        }
        else break;
    }
}

void push(KthLargest* obj, int val)
{
    obj->heap[obj->size] = val;
    obj->size++;
    heapifyUp(obj, obj->size - 1);
}

void pop(KthLargest* obj)
{
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;
    heapifyDown(obj, 0);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
{
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(int) * (numsSize + 10001));
    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++)
    {
        push(obj, nums[i]);
        if(obj->size > k)
            pop(obj);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val)
{
    push(obj, val);

    if(obj->size > obj->k)
        pop(obj);

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj)
{
    free(obj->heap);
    free(obj);
}
