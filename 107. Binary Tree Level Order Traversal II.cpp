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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()) {
            int len = q.size();
            vector<int> dummy;
            for(int i = 1; i <= len; ++i) {
                auto temp = q.front();
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                dummy.push_back(temp -> val);
                q.pop();
            }
            ans.push_back(dummy);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};