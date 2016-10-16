class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        string ans, temp;
        stringstream ss(path);
        while(getline(ss, temp, '/')) {
            if(temp == "." || temp == "") continue;
            if(temp == ".." && !tokens.empty()) tokens.pop_back();
            if(temp != "..") tokens.push_back(temp);
        }
        for(string it : tokens) {
            ans += "/" + it;
        }
        return (ans.empty())? "/" : ans;
    }
};