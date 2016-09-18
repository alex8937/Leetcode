
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