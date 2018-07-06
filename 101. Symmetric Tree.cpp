
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x)  val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public
    bool isSymmetric(TreeNode root) {
        if(!root) return true;
        return isSymmetric(root - right, root - left);
    }
    bool isSymmetric(TreeNode p, TreeNode q) {
        if(!p && !q) return true;
        if((p && !q)  (!p && q)) return false;
        return (p - val == q - val) && isSymmetric(p - left, q - right) && isSymmetric(p - right, q - left);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> leftq, rightq;
        leftq.push(root);
        rightq.push(root);
        while(!leftq.empty()) {
            auto left = leftq.front();
            auto right = rightq.front();
            leftq.pop();
            rightq.pop();
            if(!left && !right) continue;
            if(!left || !right) return false;
            if (left->val != right->val) return false;
            leftq.push(left->left);
            leftq.push(left->right);
            rightq.push(right->right);
            rightq.push(right->left);            
        }
        return true;
        
    }
};