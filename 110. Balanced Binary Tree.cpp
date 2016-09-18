/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Result {
    int depth;
    bool balance;
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getinfo(root).balance;
    }
    Result getinfo(TreeNode* root) {
        Result result;
        if(!root) {
            result.depth = 0;
            result.balance = true;
            return result;
        }
        Result leftResult = getinfo(root -> left);
        Result rightResult = getinfo(root -> right);     
        result.depth = max(leftResult.depth, rightResult.depth) + 1;
        result.balance = leftResult.balance && rightResult.balance && (abs(leftResult.depth - rightResult.depth) <= 1);
        return result;
    }
};