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
    int findSecondMinimumValue(TreeNode* root) {
        long min1 = LONG_MAX, min2 = LONG_MAX;
        traverse(root, min1, min2);
        return min2 == LONG_MAX? -1 : min2;
    }
    void traverse(TreeNode* root, long& min1, long& min2) {
        if(!root) return;
        traverse(root -> left, min1, min2);
        if(root -> val < min2 && root -> val != min1) {
            min2 = root -> val;
        }
        if(min2 < min1) {
            swap(min2, min1);
        }
        traverse(root -> right, min1, min2);
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
    int findSecondMinimumValue(TreeNode* root) {
        long min1 = LONG_MAX, min2 = LONG_MAX;
        stack<TreeNode*> st;
        auto cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur -> left;
            }
            cur = st.top();
            st.pop();
            if(cur -> val < min2 && cur -> val != min1) min2 = cur -> val;
            if(min1 > min2) swap(min1, min2);            
            cur = cur -> right;
        }
        return min2 == LONG_MAX? -1 : min2;
    }
};