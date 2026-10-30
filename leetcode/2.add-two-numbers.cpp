struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int sum = l1 -> val + l2 -> val;
        bool flag = false;
        ListNode * ans;
        if (sum < 10) {
            ans = new ListNode(sum);
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        else {
            ans = new ListNode(sum - 10);
            l1 = l1 -> next;
            l2 = l2 -> next;
            flag = true;
        }
        
        ListNode * tail = ans;

        while (l1 != nullptr || l2 != nullptr || flag) {
            int a = (l1 != nullptr) ? l1 -> val : 0;
            int b = (l2 != nullptr) ? l2 -> val : 0;
            sum = a + b;
            if (flag) {
                sum += 1;
            }
            if (sum < 10) {
                tail -> next = new ListNode(sum);
                flag = false;
            }
            else {
                tail -> next = new ListNode(sum - 10);
                flag = true;
            }
            tail = tail -> next;
            if (l1 != nullptr) l1 = l1 -> next;
            if (l2 != nullptr) l2 = l2 -> next;
        }
        return ans;
    }
};
// @lc code=end

