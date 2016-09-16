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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return valid(root, pre);
    }
    bool valid(TreeNode* root, TreeNode*& pre) {
        if(!root) return true;
        if(!valid(root -> left, pre)) return false;
        if(pre && pre -> val >= root -> val) return false;
        pre = root;
        if(!valid(root -> right, pre)) return false;
        return true;
    }
};