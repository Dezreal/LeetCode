/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode result;
    result.val = 0;
    result.next = NULL;
    struct ListNode *head;
    head = &result;
    
    int p, q;
    bool mark;
    int upon = 0;
    while(true) {
        mark = true;
        if(l1 != NULL) {
            p = l1.val;
            mark = false;
        } else {
            p = 0;
        }
        if(l2 != NULL) {
            q = l2.val;
            mark = false;
        } else {
            q = 0;
        }

        result.val = (p + q + upon) % 10;
        if(p + q + upon > 9) {
            upon = 1;
        } else {
            upon = 0;
        }
        struct ListNode node;
        result.next = &node;
        
    }
    return *result;
    
}



