/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> z;
        z.resize(2);
        for(i = 0; i < nums.size() - 1; i++) {
            z[0] = i;
            for(j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    z[1] = j;
                    return z;
                }
            }
        }
        return z;
    }
};

