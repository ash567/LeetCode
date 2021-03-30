class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size() == 0 || heights[0].size() == 0)
            return 0;
        vector< vector<int> > maxEffort(heights.size(), vector<int>(heights[0].size(), -1));
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > leastDist;
        leastDist.push(make_pair(0, make_pair(0, 0)));
        const list<pair<int, int> > indexInc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!leastDist.empty()) {
            auto leastDistNode = leastDist.top();
            leastDist.pop();
            int leastDistVal, x, y;
            leastDistVal = leastDistNode.first;
            x = leastDistNode.second.first;
            y = leastDistNode.second.second;
            if(maxEffort[x][y] == -1) {
                maxEffort[x][y] = leastDistVal;
                // if(x == heights.size() - 1 && y == heights[0].size() - 1)
                //     break;
                for(auto p : indexInc) {
                    int i = p.first, j = p.second;
                    if(x + i >= 0 && y + j >= 0 && x + i < heights.size() && y + j < heights[0].size()) {
                        int localEffort = max(abs(heights[x][y] - heights[x + i][y + j]), maxEffort[x][y]);
                        leastDist.push(make_pair(localEffort, make_pair(x + i, y + j)));
                    }
                }
            }
        }
        return maxEffort[heights.size()-1][heights[0].size() - 1];
    }
};
