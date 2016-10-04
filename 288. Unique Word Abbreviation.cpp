class ValidWordAbbr {
private:
    string encode(string str) {
        if(str.size() <= 2) return str;
        return str.front() + to_string(str.size() - 2) + str.back();
    }
    unordered_map<string, unordered_set<string>> dict;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto s : dictionary) {
            dict[encode(s)].insert(s);
        }
    }

    bool isUnique(string word) {
        return dict[encode(word)].count(word) == dict[encode(word)].size();
				
				// Either !dict.count(encode(word))
				// Or     dict[encode(word)].size() == 1 && dict[encode(word)].count(word)
				// return true else false;
    } 
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");