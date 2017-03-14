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
    vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		auto cur = root;
		vector<int> ans;
		while(!s.empty() || cur) {
			while(cur) {
				s.push(cur);
				ans.push_back(cur -> val);
				cur = cur -> left;
			}
			if(!s.empty()) {
				cur = s.top();
				s.pop();
				cur = cur -> right;
			}
		}
		return ans;
        
    }
};