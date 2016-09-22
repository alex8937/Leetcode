/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Version1: Recursion
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        return ans;
    }
    void dfs(TreeNode* node, int& k, int& ans) {
        if(!node) return;
        dfs(node -> left, k, ans);
        k--;
        if(k == 0) {
            ans = node -> val;
            return;
        }
        dfs(node -> right, k, ans);
    }
};
// Version2: Iteration
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        auto cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur -> left;
            }
            if(!st.empty()) {
                cur = st.top();
                k--;
                if(k == 0) break;
                st.pop();
                cur = cur -> right;
            }
        }
        return cur -> val;
    }
};