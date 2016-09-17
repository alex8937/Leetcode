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
// version1: traverse
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return valid(root, pre);
    }
    bool valid(TreeNode* root, TreeNode*& pre) {
        if(!root) return true;
        if(!valid(root -> left, pre)) return false;
        if(pre && pre -> val >= root -> val) return false;
        pre = root;
        if(!valid(root -> right, pre)) return false;
        return true;
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
struct Result {
// version2: Divide & Conquer
    Result(bool v, TreeNode* _min = nullptr, TreeNode* _max = nullptr) : isBST(v), minNode(_min), maxNode(_max) {}
    TreeNode* minNode;
    TreeNode* maxNode;
    bool isBST;
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root).isBST;
    }
    Result validate(TreeNode* root) {
        if(!root) return Result(true);
        Result left = validate(root -> left);
        Result right = validate(root -> right);
        if(!left.isBST || !right.isBST) return Result(false);
        if(left.maxNode && left.maxNode -> val >= root-> val) return Result(false);
        if(right.minNode && right.minNode -> val <= root-> val) return Result(false);  
        TreeNode* min = (left.minNode) ? left.minNode : root;
        TreeNode* max = (right.maxNode) ? right.maxNode : root;     
        return Result(true, min, max);
    }
};