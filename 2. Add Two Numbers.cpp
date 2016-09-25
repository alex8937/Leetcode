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
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        auto cur = dummy;
        while(l1 || l2 || carry) {
            int num1 = (l1)? l1 -> val : 0;
            int num2 = (l2)? l2 -> val : 0;   
            int sum = num1 + num2 + carry;
            cur -> next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        auto head = dummy -> next;
        delete dummy;
        return head;
    }
};