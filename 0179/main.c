#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a,const void *b){
    char nums1[50],nums2[50];

    strcpy(nums1,*(char **)a);
    strcat(nums1,*(char **)b);

    strcpy(nums2,*(char **)b);
    strcat(nums2,*(char **)a);

    return strcmp(nums2,nums1);
}


char* largestNumber(int* nums, int numsSize) 
{
    int length=0;
    char *strNums[numsSize];
    for(int i=0;i<numsSize;i++){
        strNums[i]=(char *)malloc(sizeof(char)*12);
        sprintf(strNums[i],"%d",nums[i]);
        length+=strlen(strNums[i]);

    }

    qsort(strNums,numsSize,sizeof(char *),compare);

    if (*strNums[0]=='0'){
        char *result=(char*)malloc(sizeof(char)*2);
        strcpy(result,"0");
        return result;
    }
    
    char *result=(char *)malloc(sizeof(char)*(length+1));
    result[0]='\0';
    for(int i=0;i<numsSize;i++){
        strcat(result,strNums[i]);
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
    
    return 0;
}