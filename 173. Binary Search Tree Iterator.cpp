/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* cur;
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(cur || !st.empty()) return true;
        else return false;
    }

    /** @return the next smallest number */
    int next() {
        int ans;
        while(cur) {
            st.push(cur);
            cur = cur -> left;
        }
        if(!st.empty()) {
            cur = st.top();
            ans = cur -> val;
            st.pop();
            cur = cur -> right;
        }
        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */