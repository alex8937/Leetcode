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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto dummy = new ListNode(0);
        dummy -> next = head;
        auto pre = dummy;
        for(int i = 0; i < m - 1; ++i) pre = pre -> next;
        auto cur = pre -> next;
        for(int i = 0; i < n - m; ++i) {
            auto next = cur -> next;
            cur -> next = next -> next;
            next -> next = pre -> next;
            pre -> next = next;
            
        }
        auto newhead = dummy -> next;
        delete dummy;
        return newhead;
    }
};