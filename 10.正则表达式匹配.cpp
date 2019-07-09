/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        if (s.empty()) {
            if (p.size() == 2) {
                return p[1] == '*';
            } else if (p.size() > 2) {
                return p[1] == '*' && isMatch(s, p.substr(2));
            } else {
                return false;
            }
        }
        bool first_match = s[0] == p[0] || p[0] == '.';
        if (first_match) {
            if (p[1] == '*') {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            } else {
                return isMatch(s.substr(1), p.substr(1));
            }
        } else {
            if (p.size() < 2) {
                return false;
            }
            if (p[1] == '*') {
                return isMatch(s, p.substr(2));
            } else {
                return false;
            }
        }
    }
};
/* 
√ Accepted
  √ 447/447 cases passed (352 ms)
  √ Your runtime beats 19.49 % of cpp submissions
  √ Your memory usage beats 13.38 % of cpp submissions (16.1 MB) */

