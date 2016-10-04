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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        string cand;
        path(ans, cand, root);
        return ans;
    }
    void path(vector<string>& ans, string cand, TreeNode* root) {
        string link = (!cand.empty())? "->" : ""; 
        if(!root -> left && !root -> right) {
            ans.push_back(cand + link + to_string(root -> val));
            return;
        } 
        if(root -> left) path(ans, cand + link + to_string(root -> val), root -> left);
        if(root -> right) path(ans, cand + link + to_string(root -> val), root -> right);
    }
};