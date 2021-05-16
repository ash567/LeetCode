class Solution {
    int findBallHelper(const vector<vector<int>>& grid, vector<vector<int>>& fallCol, int x, int y) {
        if(x == grid.size())
            return y;
        if(fallCol[x][y] == -2) {
            if(((y == 0 || grid[x][y-1] == 1) && grid[x][y] == -1) || ((y == grid[0].size() - 1 || grid[x][y+1] == -1) && grid[x][y] == 1)) {
               fallCol[x][y] = -1;         
            } else {
                fallCol[x][y] = findBallHelper(grid, fallCol, x + 1, y + grid[x][y]);
            }
        }
        return fallCol[x][y];
    }
​
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        // cout << N << endl << M;
        vector<vector<int> > fallCol(N, vector<int>(M, -2));
        vector<int> ans(M, -1);
        
        // cout << "Here";
        for(int i = 0; i < M; i++) {
            ans[i] = findBallHelper(grid, fallCol, 0, i);
        }
        return ans;
    }
};
