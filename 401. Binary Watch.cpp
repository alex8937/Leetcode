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
        for(int h = 0; h <= 4; ++h) {
            int m = num - h;
            if(m > 6 || m < 0) continue;
            vector<int> hours, mins;
            dfs(hours, 0, 0, 4, h);
            dfs(mins, 0, 0, 6, m);
            for(auto& hour : hours) {
                for(auto& min : mins) {
                    ans.emplace_back(to_string(hour) + ((min < 10)? ":0" : ":") + to_string(min));
                }
            }
        }
        return ans;
    }
    void dfs(vector<int>& ans, int cand, int start, int slots, int total) {
        if(total == 0) {
            if(slots == 4 && cand >= 0 && cand <= 11) ans.push_back(cand);
            if(slots == 6 && cand >= 0 && cand <= 59) ans.push_back(cand);
        }
        for(int i = start; i <= slots; ++i) {
            dfs(ans, cand + (1 << i), i + 1, slots, total - 1);
        }
    }
};