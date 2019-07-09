/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int a = 0; 
        int b = height.size() - 1;
        while (b - a > 0) {
            int ah = height.at(a);
            int bh = height.at(b);
            int t;
            if (ah < bh) {
                t = ah * (b - a);
                a++;
            } else {
                t = bh * (b - a);
                b--;
            }
            if (t > max) {
                max = t;
            }
        }
        return max;
    }
};
/* 
√ Accepted
  √ 50/50 cases passed (16 ms)
  √ Your runtime beats 98.29 % of cpp submissions
  √ Your memory usage beats 71.84 % of cpp submissions (9.8 MB) */

