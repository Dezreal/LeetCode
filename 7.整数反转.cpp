/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int d = x % 10;
            if (result > INT_MAX / 10 || result == INT_MAX / 10 && d > 7) {
                return 0;
            }
            if (result < INT_MIN / 10 || result == INT_MIN / 10 && d < -8) {
                return 0;
            }
            result = result * 10 + d;
            x = x / 10;
        }
        return result;
    }
};
/* 
√ Accepted
  √ 1032/1032 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 93.37 % of cpp submissions (8 MB) */

