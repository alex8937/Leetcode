/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* deserialize(stringstream& ss) {
        string val;
        ss >> val;
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root -> left = deserialize(ss);
        root -> right = deserialize(ss);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "# ";
        return to_string(root -> val) + " " + serialize(root -> left) + serialize(root -> right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));