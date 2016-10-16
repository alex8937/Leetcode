/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp {
    bool operator()(ListNode*& p, ListNode*& q) {
        return p -> val > q -> val;
    }   
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto node : lists) {
            if(node) pq.push(node);
        }
        ListNode* dummy = new ListNode(0);
        auto cur = dummy;
        while(!pq.empty()) {
            cur -> next = pq.top();
            cur = cur -> next;
            if(pq.top() -> next) pq.push(pq.top() -> next);
            pq.pop();
        }
        auto head = dummy -> next;
        delete dummy;
        return head;
    }
};