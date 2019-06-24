/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *result = new ListNode(0);
        struct ListNode *head = result;
        
        int p, q, z;
        bool mark; //current digit is NOT available
        int upon = 0;
        while(true) {
            mark = true;
            if(l1 != NULL) {
                p = l1 -> val;
                mark = false;
                l1 = l1 -> next;
            } else {
                p = 0;
            }
            if(l2 != NULL) {
                q = l2 -> val;
                mark = false;
                l2 = l2 -> next;
            } else {
                q = 0;
            }
            
            z = p + q + upon;

            if(z > 0) {
                mark = false;
            }

            if(z > 9) {
                upon = 1;
            } else {
                upon = 0;
            }

            if(mark) {
                head -> next = NULL;
                break;
            }
            
            head -> val = z % 10;
            if(upon == 1 || l1 || l2) { // next digit is available
                struct ListNode *node = new ListNode(0);
                head -> next = node;
                head = head -> next;
            }
        }
        return result;
    }
};

