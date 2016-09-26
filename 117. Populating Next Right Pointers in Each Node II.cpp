/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root) {
            TreeLinkNode* head = nullptr;
            TreeLinkNode* last = nullptr;
            while(root) {
                if(root -> left) {
                    if(!head) head = root -> left;
                    if(last) last -> next = root -> left;
                    last = root -> left;
                }
                if(root -> right) {
                    if(!head) head = root -> right;
                    if(last) last -> next = root -> right; 
                    last = root -> right;
                }
                root = root -> next;
            }
            root = head;
        }
    }
};