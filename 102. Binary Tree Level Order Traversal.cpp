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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root) {
            return result;
        }
        
        queue<TreeNode*> queueNode;
        queueNode.push(root);
        while(!queueNode.empty()){
            int size = queueNode.size();
            vector<int> cand;
            for(int i = 0; i < size; ++i) {
                TreeNode* head = queueNode.front();
                cand.push_back(head -> val);
                if(head -> left) {
                    queueNode.push(head -> left);
                }
                if(head -> right) {
                    queueNode.push(head -> right);
                }
                queueNode.pop();
            }
            result.push_back(cand);
        }
        
        return result;
    }
};