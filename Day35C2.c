#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int s1[100];
    int s2[100];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

void transfer(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
