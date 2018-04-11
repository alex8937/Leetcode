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
//ver1: recursion
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        string cand;
        path(ans, cand, root);
        return ans;
    }
    void path(vector<string>& ans, string cand, TreeNode* root) {
        auto link = (cand.empty())? "" : "->";
        cand += link + to_string(root -> val);
        if(!root -> left && !root -> right) {
            ans.push_back(cand);
            return;
        }
        if(root -> left) help(ans, cand, root -> left);
        if(root -> right) help(ans, cand, root -> right);    }
};

class Solution {
public:
//ver2: iteration using stacks
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        stack<string> pool;
        st.push(root);  
        pool.push(to_string(root -> val));
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            string cand = pool.top();
            pool.pop();
            if(!node -> left && !node -> right) {
                ans.push_back(cand);
            }
            if(node -> left) {
                st.push(node -> left);
                pool.push(cand + "->" + to_string(node -> left -> val));  
            }
            if(node -> right) {
                st.push(node -> right);
                pool.push(cand + "->" + to_string(node -> right -> val));  
            }              
        }
        return ans;
    }
};