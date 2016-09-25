class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int> res;
        for(int cand = 1; cand <= 9; ++cand){
          dfs(cand, n, res); 
        }
        return res;
    }
    
     void dfs(int cand, const int& n, vector<int>& res){
        if(cand > n) return;
        res.push_back(cand);
        for(int i = 0; i <= 9; ++i){
            dfs(10 * cand + i, n, res);
        }
    }
};