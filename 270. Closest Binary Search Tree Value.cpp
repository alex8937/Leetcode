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
    int closestValue(TreeNode* root, double target) {
			// version1: search 
        int ans = root -> val;
        double diff = abs(ans - target);
        while(root) {
            double new_diff = abs(root -> val - target);
            if(new_diff < diff) {
                ans = root -> val;
                diff = new_diff;
            }
            if(target > root -> val) {
                root = root -> right;
            }
            else {
                root = root -> left;
            }
        }
        return ans;
		  // version2: recursion: choose btween root or child
		    int rootval = root -> val;
		    double diff = abs(rootval - target);
		    TreeNode* child = (target < rootval)? root -> left : root -> right;
		    if(!child) return rootval;
		    int childval = closestValue(child, target);
		    double new_diff = abs(childval - target);
		    if(new_diff < diff) {
		    	return childval;
		    }
		    else {
		    	return ans;
				}			
    }
};