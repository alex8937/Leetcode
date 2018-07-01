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
// recursion O(lgN)
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root -> left) return root;
        auto left = root -> left, right = root -> right;
        auto back = upsideDownBinaryTree(root -> left);
        left -> left = right;
        left -> right = root;
        root -> left = nullptr;
        root -> right = nullptr;
        return back;
    }
};


class Solution {
public:
// iteration O(lgN)
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* cur = root, *pre = nullptr, *nxt = nullptr, *right = nullptr;
        while(cur) {
            nxt = cur -> left;           
            cur -> left = right;
            right = cur -> right;
            cur -> right = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};