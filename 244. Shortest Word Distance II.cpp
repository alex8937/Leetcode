class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) {
            dict[words[i]].emplace_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int ans = INT_MAX, i = 0, j = 0;
        while(i < dict[word1].size() && j < dict[word2].size()) {
            ans = min(ans, abs(dict[word1][i] - dict[word2][j]));
            if(dict[word1][i] < dict[word2][j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
        
    }
private:
    unordered_map<string, vector<int>> dict;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");