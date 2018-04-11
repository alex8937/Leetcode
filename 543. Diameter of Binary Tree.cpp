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
  //ver1
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }
    int height(TreeNode* root, int& ans) {
        if(!root) return 0;
        int left = height(root -> left, ans);
        int right = height(root -> right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};

struct Result {
  //ver2
    int height;
    int max_diameter;
    Result(int _h, int _m) : height(_h), max_diameter(_m) {} 
};
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return help(root).max_diameter;
    }
    Result help(TreeNode* root) {
        if(!root) return Result(0, 0);
        Result left = help(root -> left);
        Result right = help(root -> right);
        int h = max(left.height, right.height) + 1;
        int m = max(max(left.max_diameter, right.max_diameter), left.height + right.height);
        return Result(h, m);
    }
};