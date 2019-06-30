/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            vector<int> v = nums1;
            nums1 = nums2;
            nums2 = v;
            int t = m;
            m = n;
            n = t;
        }

        int oe = (m + n) % 2; // odd: 1, even: 0

        int pmin = 0;
        int pmax = m;

        while (true) {
            int p = (pmin + pmax) / 2;
            int q = (m + n
                     + oe /* can be const: 1 */
                     ) / 2 - p;
            
            if (p < m && q > 0 && nums2[q - 1] > nums1[p]) { // p is too small
                pmin = p + 1;
            } else if (p > 0 && q < n && nums1[p - 1] > nums2[q]) { // p is too large
                pmax = p - 1;
            } else {
                double left_max;
                if (p <= 0) {
                    left_max = nums2[q - 1];
                } else if(q <= 0) {
                    left_max = nums1[p - 1];
                } else {
                    left_max = nums1[p - 1] >= nums2[q - 1] ? nums1[p - 1] : nums2[q - 1];
                }
                if (oe) {
                    return left_max;
                }

                double right_min;
                if (p == m) {
                    right_min = nums2[q];
                } else if(q == n) {
                    right_min = nums1[p];
                }else {
                    right_min = nums1[p] <= nums2[q] ? nums1[p] : nums2[q];
                }
                return (left_max + right_min) / 2;
            }
        }
    }
};

