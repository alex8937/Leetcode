/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        auto cur = head;
        while(cur) {
            cur = cur -> next;
            len++;
        }
        return helper(head, 0, len - 1);
    }
    TreeNode* helper(ListNode*& cur, int start, int end) {
        if(start > end) return nullptr;
        int mid = start + (end - start) / 2;
        auto left = helper(cur, start, mid - 1);
        auto root = new TreeNode(cur -> val);
        root -> left = left;
        cur = cur -> next;
        auto right = helper(cur, mid + 1, end);
        root-> right = right;
        return root;
    }
};