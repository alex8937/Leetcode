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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        auto cur = head;
        if(cur -> val != cur -> next -> val) {
            cur -> next = deleteDuplicates(cur -> next);
            return cur;
        }
        while(cur -> next && cur -> val == cur -> next -> val) cur = cur -> next;
        return deleteDuplicates(cur -> next);
        
    }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy -> next = head;
        auto pre = dummy, cur = head;
        while(cur) {
            while(cur -> next && cur -> val == cur -> next -> val) {
                cur = cur -> next;
            }
            if(pre -> next == cur) {
                pre = pre -> next;
            }
            else {
                pre -> next = cur -> next;
            }
            cur = cur -> next;
        }
        head = dummy -> next;
        delete dummy;
        return head;
        
    }
};