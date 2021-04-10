class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int x, y;
        x = y = 0;
        bool freshFound = false;
        queue<pair<int, int> > rotten;
        while(x < grid.size()) {
            while(y < grid[x].size()) {
                if(grid[x][y] == 2) {
                    rotten.push(make_pair(x, y));
                }
                if(grid[x][y] == 1) {
                    freshFound = true;
                }
                y++;
            }
            y = 0;
            x++;
        }
        if(rotten.empty()) {
            if(freshFound)
                return -1;
            else
                return 0;
        }
        int timeNeeded = 0;
        list<pair<int, int> > inc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!rotten.empty()) {
            queue<pair<int, int> > nextRotten;
            while(!rotten.empty()) {
                int i = (rotten.front()).first;
                int j = (rotten.front()).second;
                rotten.pop();
                for(auto p : inc) {
                    if(i + p.first >= 0 && i + p.first < grid.size() && j + p.second >= 0 && j + p.second < grid[0].size()) {
                        if(grid[i + p.first][j + p.second] == 1) {
                            grid[i + p.first][j + p.second] = 2;
                            nextRotten.push(make_pair(i + p.first, j + p.second));
                        }
