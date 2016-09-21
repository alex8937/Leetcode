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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cand;
        dfs(ans, cand, sum, root);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& cand, int sum, TreeNode* root) {
        if(!root) return;
        if(!root -> left && !root -> right && sum == root -> val) {
            cand.push_back(root -> val);
            ans.push_back(cand);
            cand.pop_back();
            return;
        }
        cand.push_back(root -> val);
        dfs(ans, cand, sum - root -> val, root -> left);
        dfs(ans, cand, sum - root -> val, root -> right);     
        cand.pop_back();

    }
};