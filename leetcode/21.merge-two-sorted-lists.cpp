#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            int val1 = list1 -> val;
            int val2 = list2 -> val;
            if (val1 <= val2) {
                cur -> next = list1;
                list1 = list1 -> next;
                cur = cur -> next;
            } else {
                cur -> next = list2;
                list2 = list2 -> next;
                cur = cur -> next;
            }
        }
        if (list1 != nullptr) {
            cur -> next = list1;
        } else if (list2 != nullptr) {
            cur -> next = list2;
        }
        return dummy.next;
    }
};
// @lc code=end

