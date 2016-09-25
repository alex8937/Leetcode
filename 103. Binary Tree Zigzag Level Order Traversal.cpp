
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x)  val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public
    vectorvectorint zigzagLevelOrder(TreeNode root) {
        vectorvectorint ans;
        if(!root) return ans;
        int level = 1;
        queueTreeNode qu;
        qu.push(root);
        while(!qu.empty()) {
            int len = qu.size();
            vectorint dummy;
            for(int i = 1; i = len; ++i) {
                auto temp = qu.front();
                if(temp - left) qu.push(temp - left);
                if(temp - right) qu.push(temp - right);
                dummy.emplace_back(temp - val);
                qu.pop();
            }
            if(level % 2 == 0) reverse(dummy.begin(), dummy.end());
            level++;
            ans.emplace_back(dummy);
        }
        return ans;
        
    }
};