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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return nullptr;
    }
};

void dfs(TreeNode* root, int depth, int& maxdepth, vector<TreeNode*>& pool) {
	if(!root) return;
	if(depth > maxdepth) {
		maxdepth = depth;
		pool.clear();
		pool.push_back(root);
	}
	else if(depth == maxdepth) {
		pool.push_back(root);
	}
	dfs(root -> left, depth + 1, maxdepth, pool);
	dfs(root -> right, depth + 1, maxdepth, pool);
}

int main() {
	int maxdepth;
	vector<TreeNode*> pool
	dfs(root, 1, -1, pool);
	if(pool.empty()) return nullptr;
	if(pool.size() == 1) return pool[0];
	for(int i = 1; i < pool.size(); ++i) {
		pool[i] = lowestCommonAncestor(root, pool[i - 1], pool[i]);
	}
	return pool.back();
}