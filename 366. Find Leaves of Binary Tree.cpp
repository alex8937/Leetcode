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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        helper(ans, root);
        return ans;
    }
    int helper(vector<vector<int>>& ans, TreeNode* root) {
        if(!root) return -1;
        auto left = helper(ans, root -> left);
        auto right = helper(ans, root -> right);
        int index = max(left, right) + 1;
        if(ans.size() == index) ans.push_back(vector<int>());
        ans[index].push_back(root -> val);
        return index;
    }
};