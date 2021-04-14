class Solution {
    list<pair<int, int> > inc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int getMaximumGold(vector<vector<int> >& grid, int i, int j) {
        const int cellVal = grid[i][j];
        int maxGold = cellVal;
        grid[i][j] = 0;
        for(auto p : inc) {
            int x = i + p.first, y = j + p.second;
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 0) {
                maxGold = max(maxGold, cellVal + getMaximumGold(grid, x, y));
            }
        }
        grid[i][j] = cellVal;
        return maxGold;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0)
                    maxGold = max(maxGold, getMaximumGold(grid, i, j));
            }
        }
        return maxGold;
    }
};
