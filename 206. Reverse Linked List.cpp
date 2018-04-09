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
    ListNode* reverseList(ListNode* head) {
    //version 1: recursion
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    //version 2: recursion
        if(!head || !head -> next) return head;  
          
        ListNode* nxt = head -> next;  
        ListNode* back = reverseList(nxt);  
          
        head -> next = nullptr;  
        nxt -> next = head;  
        return back;  
        
    }
};