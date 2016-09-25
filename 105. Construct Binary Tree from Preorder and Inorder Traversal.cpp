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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len == 0) return nullptr;
        return buildTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe) return nullptr;
        if(ps == pe) return new TreeNode(preorder[ps]);
        int rootval = preorder[ps];
        TreeNode* root = new TreeNode(rootval);
        int root_index = find(inorder.begin() + is, inorder.begin() + ie, rootval) - inorder.begin();
        root -> left = buildTree(preorder, inorder, ps + 1, ps + root_index - is, is, root_index - 1);
        root -> right = buildTree(preorder, inorder, ps + root_index - is + 1, pe, root_index + 1, ie);
        return root;
    }
};