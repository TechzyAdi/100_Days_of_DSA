#include <stdlib.h>

typedef struct {
    int small[50000]; // max heap
    int large[50000]; // min heap
    int smallSize;
    int largeSize;
} MedianFinder;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* -------- MAX HEAP -------- */

void maxHeapifyUp(int heap[], int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[parent] < heap[index]){
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void maxHeapifyDown(int heap[], int size, int index){
    while(1){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;

        if(left < size && heap[left] > heap[largest])
            largest = left;

        if(right < size && heap[right] > heap[largest])
            largest = right;

        if(largest != index){
            swap(&heap[index], &heap[largest]);
            index = largest;
        } else break;
    }
}

/* -------- MIN HEAP -------- */

void minHeapifyUp(int heap[], int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[parent] > heap[index]){
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void minHeapifyDown(int heap[], int size, int index){
    while(1){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index){
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

/* -------- HEAP OPERATIONS -------- */

void pushMax(MedianFinder* obj, int val){
    obj->small[obj->smallSize] = val;
    maxHeapifyUp(obj->small, obj->smallSize);
    obj->smallSize++;
}

void pushMin(MedianFinder* obj, int val){
    obj->large[obj->largeSize] = val;
    minHeapifyUp(obj->large, obj->largeSize);
    obj->largeSize++;
}

int popMax(MedianFinder* obj){
    int val = obj->small[0];
    obj->small[0] = obj->small[obj->smallSize-1];
    obj->smallSize--;
    maxHeapifyDown(obj->small, obj->smallSize, 0);
    return val;
}

int popMin(MedianFinder* obj){
    int val = obj->large[0];
    obj->large[0] = obj->large[obj->largeSize-1];
    obj->largeSize--;
    minHeapifyDown(obj->large, obj->largeSize, 0);
    return val;
}

/* -------- REQUIRED FUNCTIONS -------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->smallSize = 0;
    obj->largeSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    
    if(obj->smallSize == 0 || num <= obj->small[0])
        pushMax(obj, num);
    else
        pushMin(obj, num);

    if(obj->smallSize > obj->largeSize + 1)
        pushMin(obj, popMax(obj));
    else if(obj->largeSize > obj->smallSize)
        pushMax(obj, popMin(obj));
}

double medianFinderFindMedian(MedianFinder* obj) {
    
    if(obj->smallSize > obj->largeSize)
        return obj->small[0];

    return ((double)obj->small[0] + obj->large[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
