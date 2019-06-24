/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *z = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(i = 0; i < numsSize - 1; i++) {
        z[0] = i;
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                z[1] = j;
                return z;
            }
        }
    }
    
    return z;
}



