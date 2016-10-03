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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size() - 1);
    }
    TreeNode* toBST(vector<int>& nums, int start, int end) {
        if(start == end) return new TreeNode(nums[start]);
        if(start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = toBST(nums, start, mid - 1);
        root -> right = toBST(nums, mid + 1, end);
        return root;
    } 
};