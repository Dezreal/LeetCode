/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += atLine(s, i, numRows);
        }
        return result;
    };
private:
    string atLine(string s, int line, int numRows) {
        string result = "";
        if(line == 0 || line == numRows - 1) {
            for(int i = 0; i < s.size(); i++) {
                if(i % (2 * numRows - 2) == line) {
                    result += s[i];
                }
            }
        }else {
            for(int i = 0; i < s.size(); i++) {
                if(i % (2 * numRows - 2) == line || i % (2 * numRows - 2) == 2 * numRows - 2 - line) {
                    result += s[i];
                }
            }
        }
        return result;
    }
};
/* 
√ Accepted
  √ 1158/1158 cases passed (144 ms)
  √ Your runtime beats 6.73 % of cpp submissions
  √ Your memory usage beats 9.75 % of cpp submissions (39.8 MB) */

