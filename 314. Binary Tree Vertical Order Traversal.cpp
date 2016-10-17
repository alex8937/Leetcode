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
// BFS + hash_map
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> dict;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> qu;
        if(!root) return ans;
        qu.emplace(root, 0);
        while(!qu.empty()) {
            int len = qu.size();
            for(int i = 1; i <= len; ++i) {
                auto cur = qu.front().first;
                int col = qu.front().second;
                dict[col].push_back(cur -> val);
                if(cur -> left) qu.emplace(cur -> left, col - 1);
                if(cur -> right) qu.emplace(cur -> right, col + 1);
                qu.pop();
            }
        }
        for(auto it : dict) {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};