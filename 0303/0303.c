#include <stdlib.h>

typedef struct {
    int* s;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* arr = (NumArray*)malloc(sizeof(NumArray));
    arr->s=malloc(sizeof(int)*(numsSize+1));
    arr->s[0]=0;
    for (int i=0;i<numsSize;i++) {
        arr->s[i+1]=arr->s[i]+nums[i];
    } 
    return arr;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->s[right+1]-obj->s[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->s);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/