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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1 -> val <= l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if(l1) cur -> next = l1;
        if(l2) cur -> next = l2;  
        ListNode* head = dummy -> next;
        delete dummy;
        return head;
    }
};


class Solution {
public:
//recursion
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    auto& large = (l1->val > l2 -> val) ? l1 : l2;
    auto& small = (l1->val > l2 -> val) ? l2 : l1;
    small -> next = mergeTwoLists(small->next, large);
    return small;
  }
};



