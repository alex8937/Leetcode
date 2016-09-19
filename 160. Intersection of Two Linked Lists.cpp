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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			// version1: need to know the difference length;
        auto curA = headA, curB = headB;
        int cntA = 0, cntB = 0;
        while(curA) {
            curA = curA -> next;
            cntA++;
        }
        while(curB) {
            curB = curB -> next;
            cntB++;
        }
        auto& longList = (cntA > cntB)? headA : headB;
        auto& shortList = (cntA <= cntB)? headA : headB;
        int diff = abs(cntA - cntB);
        while(diff) {
            longList = longList -> next;
            diff--;
        }
        while(longList && shortList) {
            if(longList == shortList) return longList;
            longList = longList -> next;
            shortList = shortList -> next;            
        }
        return nullptr;
			// version2: No need to know the difference length;	
        auto curA = headA, curB = headB;
        while(curA != curB) {
            curA = (curA)? curA -> next : headB;
            curB = (curB)? curB -> next : headA;
        }
        return curA;
				
    }
};