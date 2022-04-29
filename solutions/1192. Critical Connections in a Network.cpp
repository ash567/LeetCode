class Solution {
    struct hash {
        size_t operator() (const pair<int, int> & p) const {
            return p.first ^ p.second;
        }
    };
    
    int dfs(const int n, unordered_map<int, vector<int> > & adjList, unordered_set<pair<int, int>, hash>& criticalE, unordered_map<int, int>& rank, int drank) {
        if(rank.find(n) != rank.end())
            return rank[n];
        rank[n] = drank;
        int minRank = drank;
        for(int i : adjList[n]) {
            if(rank.find(i) != rank.end() and rank[i] == drank - 1)
                continue;
            int dfsRank = dfs(i, adjList, criticalE, rank, drank + 1);
            minRank = min(minRank, dfsRank);
            if(dfsRank <= drank) {
                int a = min(n, i), b = max(n, i);
                criticalE.erase({a, b});
            }
        }
        return minRank;
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, int> rank;
        unordered_map<int, vector<int> > adjList;
        unordered_set<pair<int, int>, hash> criticalE;
        for(auto &v : connections) {
            int a = min(v[0], v[1]), b = max(v[0], v[1]);
            criticalE.insert({a, b});
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        for(const auto & p : adjList) {
            int i = p.first;
            if(rank.find(i) != rank.end())
                continue;
            dfs(i, adjList, criticalE, rank, 0);
        }
        vector<vector<int>> ans;
        for(auto p : criticalE) {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};
