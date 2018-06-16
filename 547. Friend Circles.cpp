class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<bool>& visit, int k) {
        visit[k] = true;
        for(int i = 0; i < M.size(); ++i) {
            if(!visit[i] && M[k][i]) dfs(M, visit, i);
        }
    }

    int findCircleNum(vector<vector<int>> & M) {
        int ans = 0;
        vector<bool> visit(M.size(), false);
        for(int i = 0; i < M.size(); ++i) {
            if(!visit[i]) {
                dfs(M, visit, i);
                ans++;
            }
        }
        return ans;
    }
};