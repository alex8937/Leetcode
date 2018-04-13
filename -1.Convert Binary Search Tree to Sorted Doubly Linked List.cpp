/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* left = NULL;
    Node* right = NULL;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        auto dummy = new Node(0, root);
        auto pre = dummy;
        auto head = root;
        while(head -> left) head = head -> left;
        auto cur = root;
        while(cur) {
            while(cur -> left) {
                auto left = cur -> left;
                auto link = left;
                while(link -> right) link = link -> right;
                link -> right = cur;
                cur -> left = nullptr;
                cur = left;
            }
            pre -> right = cur;
            cur -> left = pre;
            pre = cur;
            cur = cur -> right;
        }
        pre -> right = head;
        head -> left = pre;
        delete dummy;
        return head;
        
    }
};