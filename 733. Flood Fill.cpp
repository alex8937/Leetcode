class Solution {
private:
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        helper(image, sr, sc, newColor, oldColor);
        return image;
    }
    void helper(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor) return;
        image[i][j] = newColor;
        for(int k = 0; k < 4; ++k) {
            helper(image, i + x[k], j + y[k], newColor, oldColor);
        }
    }
};