class Solution {
    list< pair<int, int> > increment = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    int dfs(int i, int j, int id, vector<vector<int>>& grid) {
        grid[i][j] = id;
        int childCount = 0;
        for(auto inc : increment) {
            if(!(inc.first + i >= grid.size() or inc.first + i < 0 or inc.second + j >= grid.size() or inc.second + j < 0)) {
                if(grid[inc.first + i][inc.second + j] == 1)
                    childCount += dfs(inc.first + i, inc.second + j, id, grid);
            }
        }
        return 1 + childCount;
    }
    
//     void findMaxIland(int i, int j, vector<vector<int>>& grid, unordered_map<int, int>& sizeMap, int& maxSize) {
//         int id = grid[i][j];
//         grid[i][j] = -1;
//         maxSize = max(maxSize, sizeMap[id]);
//         for(auto inc : increment) {
//             int i1 = inc.first + i, j1 = inc.second + j;
//             if(!( i1 >= grid.size() or i1 < 0 or j1 >= grid.size() or j1 < 0)) {
//                 if(grid[i1][j1] == 0) {
//                     maxSize = max(maxSize, sizeMap[id] + 1);
//                     for(auto inc1 : increment) {
//                         int i2 = inc1.first + i1, j2 = inc1.second + j1;
//                         if(!( i2 >= grid.size() or i2 < 0 or j2 >= grid.size() or j2 < 0)) {
//                             if(grid[i2][j2] != id and grid[i2][j2] > 1) {
//                                 int id1 = grid[i2][j2];
//                                 maxSize = max(maxSize, 1 + sizeMap[id] + sizeMap[id1]);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         for(auto inc : increment) {
//             if(!(inc.first + i >= grid.size() or inc.first + i < 0 or inc.second + j >= grid.size() or inc.second + j < 0)) {
//                 if(grid[inc.first + i][inc.second + j] == id)
//                     findMaxIland(inc.first + i, inc.second + j, grid, sizeMap, maxSize);
//             }
//         }
//         return;
//     }
    
public:
