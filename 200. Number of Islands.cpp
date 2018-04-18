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

// Union find
class UF {
public:
    UF(vector<vector<char>>& grid) {
        id = vector<int>(grid.size() * grid[0].size(), -1);
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '0') continue;
                count++;
                id[i * grid[0].size() + j] = i * grid[0].size() + j;
            }
        }
    }
    void unite(int p, int q) {
        int p_root = find(p);
        int q_root = find(q);
        if(p_root != q_root) {
            id[p_root] = q_root;
            count--;
        }
    }    
    int count = 0;
    
private:
    vector<int> id;   
    int find(int p) {
        while(p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        auto uf = new UF(grid);
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '0') continue;
                int p = i * grid[0].size() + j;
                if(i > 0 && grid[i - 1][j] == '1') uf -> unite(p, p - grid[0].size());
                if(j > 0 && grid[i][j - 1] == '1') uf -> unite(p, p - 1);              
            }
        }
        return uf -> count;
    }
};