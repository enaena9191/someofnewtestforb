#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *s1, const void *s2) {
    char st1[50], st2[50];

    strcpy(st1, *(char **)s1);
    strcat(st1, *(char **)s2);

    strcpy(st2, *(char **)s2);
    strcat(st2, *(char **)s1);

    return strcmp(st2, st1);
}

char* largestNumber(int* nums, int numsSize) {
    char *strnums[numsSize];
    int i;
    int length = 0;
    for (i = 0; i < numsSize; i++) {
        strnums[i] = (char*)malloc(12);
        sprintf(strnums[i], "%d", nums[i]);
        length += strlen(strnums[i]);
    }

    qsort(strnums, numsSize, sizeof(char*), compare);

    if (*strnums[0] == '0') {
        char *result = malloc(sizeof(char) * 2);
        result = "0\0";
        return result;
    }

    char *result=(char *)malloc(sizeof(char)*(length+1));
    result[0]='\0';
    for(i = 0; i < numsSize; i++) {
        strcat(result, strnums[i]);
    }
    return result;
}

int main() {
        // 示例 1
        int nums1[] = {9, 9, 98};
        int size1 = sizeof(nums1) / sizeof(nums1[0]);
        char *res1 = largestNumber(nums1, size1);
        printf("Largest Number: %s\n", res1);  // 输出应为 "9998"
        free(res1);
        
        // 示例 2
        int nums2[] = {7, 6, 78, 779};
        int size2 = sizeof(nums2) / sizeof(nums2[0]);
        char *res2 = largestNumber(nums2, size2);
        printf("Largest Number: %s\n", res2);  // 输出应为 "7877976"
        free(res2);
    
        int nums3[] = {786, 99, 7, 6, 78, 779};
        int size3 = sizeof(nums3) / sizeof(nums3[0]);
        char *res3 = largestNumber(nums3, size3);
        printf("Largest Number: %s\n", res3);  // 输出应为 "7877976"
        free(res3);
        LONG_LONG_MAX;

    return 0;
}