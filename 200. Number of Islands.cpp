class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		//DFS
      int ans = 0;
      if(grid.empty()) return ans;
      for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
          if(grid[i][j] == '1') {
            ans++;
            dfs(i, j, grid);
          }
        }
      }
      return ans;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
      if(grid[i][j] != '1') return;
      grid[i][j] = '2';
      if(i - 1 >= 0) dfs(i - 1, j, grid);
      if(i + 1 < grid.size()) dfs(i + 1, j, grid);
      if(j - 1 >= 0) dfs(i, j - 1, grid);
      if(j + 1 < grid[0].size()) dfs(i, j + 1, grid);
    }
};