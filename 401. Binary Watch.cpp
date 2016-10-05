class Solution {
public:
	//version1: iteration
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int h = 0; h < 12; ++h) {
            for(int m = 0; m < 60; ++m) {
                if(bitset<10>((h << 6) | m).count() == num) {
                    ans.push_back(to_string(h) + ((m < 10)? ":0" : ":") + to_string(m));
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
	//version2: recursion
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int h = 0; h < 4; ++h) {
            vector<int> hours, mins;
            dfs(hours, 0, 0, 0, h, 4);
            dfs(mins, 0, 0, 0, num - h, 6);
            for(auto& hour : hours) {
                for(auto& min : mins) {
                    ans.push_back(to_string(hour) + ((min < 10)? ":0" : ":") + to_string(min));                        
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<int>& ans, int cand, int start, int picked, int& total, int slots) {
        if(picked == total) {
            if(slots == 4 && cand <= 11) ans.push_back(cand);
            else if(slots == 6 && cand <= 59) ans.push_back(cand);
            return;
        }
        for(int i = start; i < slots; ++i) {
            cand += (1 << i);
            dfs(ans, cand, i + 1, picked + 1, total, slots);
            cand -= (1 << i);
        }
    }
};