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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, int(lists.size()) - 1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if(start > end) return nullptr;
        if(start == end) return lists[start];
        int mid = start + (end - start) / 2;
        auto l1 = mergeKLists(lists, start, mid);
        auto l2 = mergeKLists(lists, mid + 1, end);
        return mergeTwoLists(l1, l2);
    }
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        auto& small = (l1 -> val < l2 -> val)? l1 : l2;
        auto& large = (l1 -> val < l2 -> val)? l2 : l1;
        small -> next = mergeTwoLists(small -> next, large);
        return small;
    }
};