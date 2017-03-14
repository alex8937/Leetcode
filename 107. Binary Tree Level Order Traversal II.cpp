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
        dfs(ans, root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(vector<vector<int>>& ans, TreeNode* root, int level) {
        if(!root) return;
        if(level == ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root -> val);
        dfs(ans, root -> left, level + 1);
        dfs(ans, root -> right, level + 1);
    }
};

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
        stack<pair<TreeNode*, int>> st;
        vector<vector<int>> ans;
        int level = 0;
        while(!st.empty() || root) {
            while(root) {
                if(ans.size() == level) ans.push_back(vector<int>());
                ans[level].push_back(root -> val);
                st.push(make_pair(root, level++));
                root = root -> left;
            }
            if(!st.empty()) {
                root = st.top().first;
                level = st.top().second;
                st.pop();
                root = root -> right;
                level++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};