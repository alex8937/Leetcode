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
 //worst case: O(n^2) T(n) = T(m) + T(n - m) + O(n)
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len == 0) return nullptr;
        return buildTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe) return nullptr;
        if(ps == pe) return new TreeNode(preorder[ps]);
        int rootval = preorder[ps];
        TreeNode* root = new TreeNode(rootval);
        int root_index = find(inorder.begin() + is, inorder.begin() + ie, rootval) - inorder.begin();
        root -> left = buildTree(preorder, inorder, ps + 1, ps + root_index - is, is, root_index - 1);
        root -> right = buildTree(preorder, inorder, ps + root_index - is + 1, pe, root_index + 1, ie);
        return root;
    }
};

class Solution {
   //Improved case: using hash table O(n) T(n) = T(m) + T(n - m) + O(1)
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> dict;
        for(int i = 0; i < inorder.size(); ++i) dict[inorder[i]] = i;
        return help(dict, preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* help(unordered_map<int, int>& dict, vector<int>& p, vector<int>& i, int pl, int pr, int il, int ir) {
        if(il > ir) return nullptr;
        auto cur = new TreeNode(p[pl]);
        int index = dict[p[pl]];
        int left_len = index - il;
        cur -> left = help(dict, p, i, pl + 1, pl + left_len, il, index - 1);
        cur -> right = help(dict, p, i, pl + left_len + 1, pr, index + 1, ir);
        return cur;
    }
};