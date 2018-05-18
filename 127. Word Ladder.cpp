class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if(!wordDict.count(endWord)) return 0;
        queue<string> qu;
        qu.push(beginWord);
        wordDict.erase(beginWord);
        int ans = 0;
        while(!qu.empty()) {
            int len = qu.size();
            ans++;
            for(int i = 0; i < len; ++i) {
                auto head = qu.front();
                qu.pop();
                if(head == endWord) return ans;
                for(int k = 0; k < head.size(); ++k) {
                    for(char c = 'a'; c <= 'z'; ++c) {
                        auto temp = head;
                        temp[k] = c;
                        if(wordDict.count(temp)) {
                            qu.push(temp);
                            wordDict.erase(temp);
                        }
                    }
                }                
            }
        }
        return 0;
    }
};