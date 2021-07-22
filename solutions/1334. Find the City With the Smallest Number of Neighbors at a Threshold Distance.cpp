#define INF 1e9
​
class Solution {
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > d(n, vector<int>(n, INF));
        unordered_set<int> negativeSet;
        for(int i = 0; i < n; i++)
            d[i][i] = 0;
        for(auto& e : edges) {
            if(e[2] < 0)
                negativeSet.insert(max(e[0], e[1]));
            d[e[0]][e[1]] = e[2];
            d[e[1]][e[0]] = e[2];
        }        
        if(!negativeSet.empty()) {
            int ans = *negativeSet.begin();
            for(auto i : negativeSet) {
                ans = max(ans, i);
            }
            return ans;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int maxCountid = -1, maxCount = INF;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(d[i][j] <= distanceThreshold)
                    count++;
            }
            if(maxCount >= count) {
                maxCount = count;
                maxCountid = i;
            }
            // cout << count << " " << maxCount << endl;
​
        }
        return maxCountid;
    }
};
