class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int>();
        int up = 0, left = 0, down = matrix.size() - 1, right = matrix[0].size() - 1;
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        int cnt = 0, len = matrix.size() * matrix[0].size();
        while(cnt < len) {
            ans.push_back(matrix[i][j]);
            cnt++;
            if(i + y[k] > down || i + y[k] < up || j + x[k] > right || j + x[k] < left) {
                if(i + y[k] > down) right--;
                else if(i + y[k] < up) left++;
                else if(j + x[k] > right) up++;
                else if(j + x[k] < left) down--;  
                k = (k + 1) % 4;
            }
            i += y[k];
            j += x[k];
        }
        return ans;
    }
};