/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        bool start = false;
        int sign = 1;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c >= 48 && c <= 57) {
                start = true;
            }
            if (start) {
                if (c < 48 || c > 57) {
                    return result;
                } else {
                    if (result > INT_MAX / 10 || result == INT_MAX / 10 && c > 55) {
                        return INT_MAX;
                    }
                    if (result < INT_MIN / 10 || result == INT_MIN / 10 && c > 56) {
                        return INT_MIN;
                    }
                    result = result * 10 + sign * (c - 48);
                }
            } else {
                if (c == 45) {
                    sign = -1;
                    start = true;
                } else if(c == 43) {
                    start = true;
                } else if (c == 32) {
                    continue;
                } else {
                    return 0;
                }
            }
        }
        return result;
    }
};
/* 
√ Accepted
  √ 1079/1079 cases passed (4 ms)
  √ Your runtime beats 96.37 % of cpp submissions
  √ Your memory usage beats 86.59 % of cpp submissions (8.4 MB) */
