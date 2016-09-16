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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int diff_p = root -> val - p -> val;
        int diff_q = root -> val - q -> val;
        if(diff_p * diff_q <= 0) return root;
        if(diff_p > 0 && diff_q > 0) return lowestCommonAncestor(root -> left, p, q);
        else return lowestCommonAncestor(root -> right, p, q);
    }
};