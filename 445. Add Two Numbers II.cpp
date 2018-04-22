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
        stack<ListNode*> st1 = getStack(l1), st2 = getStack(l2);
        int car = 0;
        ListNode* cur = nullptr;
        while(!st1.empty() || !st2.empty() || car) {
            int n1 = !st1.empty()? st1.top() -> val : 0;
            int n2 = !st2.empty()? st2.top() -> val : 0;
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();   
            int sum = n1 + n2 + car;
            auto * pre = new ListNode(sum % 10);
            car = sum / 10;
            pre -> next = cur;
            cur = pre;
        }
        return cur;
    }
    
    stack<ListNode*> getStack(ListNode* l) {
        stack<ListNode*> st;
        while(l) {
            st.push(l);
            l = l -> next;
        }     
        return st;
    }
};