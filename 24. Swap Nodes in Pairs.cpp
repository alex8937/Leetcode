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
    ListNode* swapPairs(ListNode* head) {
    // version1: recursion
        if(!head || !head -> next) return head;
        ListNode* cur = head;
        ListNode* newhead = cur -> next;
        ListNode* swaped = swapPairs(newhead -> next);
        cur -> next = swaped;
        newhead -> next = cur;
        return newhead; 
    // version2: iteration
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = dummy;
        while(cur -> next && cur -> next -> next) {
            ListNode* n1 = cur -> next;
            ListNode* n2 = cur -> next -> next;
            cur -> next = n2;
            n1 -> next = n2 -> next;
            n2 -> next = n1;
            cur = n1;
        }
        ListNode* newhead = dummy -> next;
        delete dummy;
        return newhead;
    }
};