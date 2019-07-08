/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int r = reverse(x);
        return x == r;
    }

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

