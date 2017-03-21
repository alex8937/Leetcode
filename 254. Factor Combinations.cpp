class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> cand;
        help(ans, cand, n, 2);
        return ans;
    }
    
    void help(vector<vector<int>>& ans, vector<int>& cand, int num, int factor) {
        if(num >= factor && cand.size() > 0) {  // append num if possible
            cand.push_back(num);		
            ans.push_back(cand);
            cand.pop_back();
        }
        for(int i = factor; i * i <= num; ++i) {  // subdivide num
            if(num % i != 0) continue;
            cand.push_back(i);
            help(ans, cand, num / i, i);
            cand.pop_back();
        }
    }
}; 