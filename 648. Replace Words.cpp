class Trie {
private:
    struct TrieNode {
        bool isword;
        vector<TrieNode*> child;
        TrieNode() : isword(false), child(26, nullptr) {}
        ~TrieNode() {
            for(auto c : child) {
                if(c) delete c;
            }
        }
    };
    TrieNode* root;
    
    
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {}
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = root;
        for(auto c : word) {
            if(!cur -> child[c - 'a']) cur -> child[c - 'a'] = new TrieNode();
            cur = cur -> child[c - 'a'];
        }
        cur -> isword = true;
    }
    
    string find_root(string& word) {
        auto cur = root;
        string root;
        for(auto c : word) {
            if(cur -> isword) return root;
            if(!cur -> child[c - 'a']) return word;
            else {
                root.push_back(c);
                cur = cur -> child[c - 'a'];
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* t = new Trie();
        for(auto word : dict) {
            t -> insert(word);
        }
        stringstream ss(sentence);
        string word;
        string ans;
        while(ss >> word) {
            auto root = t -> find_root(word);
            if(!ans.empty()) ans.push_back(' ');
            ans.append(root);
        }
        return ans;
        
    }
};

