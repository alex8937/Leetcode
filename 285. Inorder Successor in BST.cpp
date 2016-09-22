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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    //Explanation:
    // root > p: 
    // root is possible candidate;
    // next candidate should be smaller, i.e. root -> left
    // root <= p
    // next candidate should be larger, i.e. root -> right
        TreeNode* cand = nullptr;
        while(root) {
            if(root -> val > p -> val) {
                cand = root;
                root = root -> left;
            }
            else {
                root = root -> right;
            }
        }
        return cand;
    }
};