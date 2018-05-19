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
//iteration
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur -> next) {
            if(cur -> val == cur -> next -> val) {
                ListNode* del = cur -> next;
                cur -> next = cur -> next -> next;
                delete del;
            }
            else {
                cur = cur -> next;
            }
        }
        return head;
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
//recursioin
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        if(head -> val == head -> next -> val) {
            auto next = head -> next;
            delete head;
            return deleteDuplicates(next);
        }
        else {
            head -> next = deleteDuplicates(head -> next);
            return head;
        }
    }
};

class Solution {
public:
//recursioin: using while loop
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        auto cur = head;
        while(cur -> next && cur -> val == cur -> next -> val) {
            cur = cur -> next;
        }
        head -> next = deleteDuplicates(cur -> next);
        return head;
    }
};