class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> next;
    bool isword;    
    TrieNode() {
        next= vector<TrieNode*> (26, nullptr);
        isword = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
         root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto cur = root;
        for(char c : word) {
            if(!cur -> next[c - 'a']) cur -> next[c - 'a'] = new TrieNode();
            cur = cur -> next[c - 'a'];
        }
        cur -> isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto cur = root;
        for(char c : word) {
            if(!cur -> next[c - 'a']) return false;
            cur = cur -> next[c - 'a'];
        } 
        return cur -> isword;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto cur = root;
        for(char c : prefix) {
            if(!cur -> next[c - 'a']) return false;
            cur = cur -> next[c - 'a'];
        }
        return true;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");