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
		// Iterative
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(k == 1 || !head) return head;
      int num = 0;
      ListNode* dummy = new ListNode(0);
      dummy -> next = head;
      auto pre = dummy, cur = head;
      while(cur) {
        cur = cur -> next;
        num++;
      }
      while(num >= k) {
        cur = pre -> next;
        for(int i = 1; i < k; ++i) {
          auto nxt = cur -> next;
          cur -> next = nxt -> next;
          nxt -> next = pre -> next;
          pre -> next = nxt;
        }
        num -= k;
        pre = cur;
      }
      return dummy -> next;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
			//Recursive
        if(!head || k == 1) return head;
        auto kplus = head;
        int num = 0;
        while(kplus && num < k) {
            kplus = kplus -> next;
            num++;
        }
        if(num == k) {
            auto tail = reverseKGroup(kplus, k);
            while(num-- > 0) {
                auto nxt = head -> next;
                head -> next = tail;
                tail = head;
                head = nxt;
            }
            head = tail;
        }
        return head;
        
    }
};