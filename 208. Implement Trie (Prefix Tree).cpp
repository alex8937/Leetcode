class Trie {
private:
    struct TrieNode {
        bool isword;
        vector<TrieNode*> child;
        TrieNode() : isword(false), child(26, nullptr) {}
        ~TrieNode() {
            for (TrieNode* c : child)
                if (c) delete c;
        }
    };
    TrieNode* root;
    

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = root;
        for(auto c : word) {
            if(!cur -> child[c - 'a']) return false;
            cur = cur -> child[c - 'a'];
        }
        return cur -> isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = root;
        for(auto c : prefix) {
            if(!cur -> child[c - 'a']) return false;
            cur = cur -> child[c - 'a'];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */