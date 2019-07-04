/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        string sub = "";
        int max = 0;
        for (int i = 0; i < 2 * s.size() - 1; i++) {
            int t = palindromicLenHere(s, i);
            if (t > max) {
                max = t;
                sub = s.substr((i + 1) / 2 - t / 2, t);
            }
        }
        return sub;
    }

private:
    int palindromicLenHere(string& s, int location) {
        int oe = (location + 1) % 2; // 1 = odd, 0 = even
        int lct = location / 2;
        int left = lct - oe;
        int right = lct + 1;
        int len = oe;
        while (true) {
            if (left < 0)
                return len;
            if (right >= s.size())
                return len;
            if (s[left] != s[right])
                return len;
            len += 2;
            left -= 1;
            right += 1;
        }
        return len; 
    };
    /**
     * 暴力法 O(N3)
     */
    bool isPalindromic(string s, size_t len) {
        for (size_t i = 0; i < len / 2; i++) {
            string left = s.substr(i, 1);
            string right = s.substr(len - 1 - i, 1);
            if (left.compare(right) != 0)
                return false;
        }
        return true;
    }
};

/* 
√ Accepted
  √ 103/103 cases passed (28 ms)
  √ Your runtime beats 81.61 % of cpp submissions
  √ Your memory usage beats 42.6 % of cpp submissions (15.9 MB) 
  */
