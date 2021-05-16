class Solution {
    list<pair<int, int> > adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int waterClimb(const vector<vector<int>>& heights, vector<vector<int>>& reach, int x, int y) {
        if(reach[x][y] == 0) {
            reach[x][y] = 1;
            for(auto p : adj) {
                int x1 = x + p.first, y1 = y + p.second;
                if(x1 == heights.size() || x1 < 0 || y1 == heights[0].size() || y1 < 0)
                    continue;
                if(heights[x1][y1] >= heights[x][y])
                    waterClimb(heights, reach, x1, y1);
            }
        }
        return reach[x][y];
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int> > pac(heights.size(), vector<int>(heights[0].size(), 0)), atl(heights.size(), vector<int>(heights[0].size(), 0));
        for(int i = 0; i < heights.size(); i++) {
            waterClimb(heights, pac, i, 0);
            waterClimb(heights, atl, i, heights[0].size() - 1);
        }
        for(int j = 0; j < heights[0].size(); j++) {
            waterClimb(heights, pac, 0, j);
            waterClimb(heights, atl, heights.size() - 1, j);
        }
        vector<vector<int> > ans;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                if(pac[i][j] == 1 && atl[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
