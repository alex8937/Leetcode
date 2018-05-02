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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key < root -> val) root -> left = deleteNode(root -> left, key);
        else if(key > root -> val) root -> right = deleteNode(root -> right, key);
        else {
            if(!root -> left) return root -> right;
            else {
                auto replace = root -> left;
                while(replace -> right) replace = replace -> right;
                root -> val = replace -> val;
                root -> left = deleteNode(root -> left, replace -> val);
            }
        }
        return root;
    }
};