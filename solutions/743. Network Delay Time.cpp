typedef pair<int, int> pii;
​
class Solution {
    const int INF = 1e9;
    
    void dij(int source, const vector<vector<pii>>& adj, vector<int>& d) {
        d.assign(adj.size(), INF);
        set<pii> q;
        d[source] = 0;
        q.insert({0, source});
        while(!q.empty()) {
            int s = q.begin()->second;
            q.erase(q.begin());
            for(const auto& e : adj[s]) {
                int v = e.first;
                int len = e.second;
                if(d[v] > len + d[s]) {
                    q.erase({d[v], v});
                    d[v] = len + d[s];
                    q.insert({d[v], v});
                }
            }
        }
        return;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n);
        for(const auto& edge : times) {
            adj[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        }
        vector<int> d;
        dij(k - 1, adj, d);
        int maxTime = 0;
        for(auto dis : d) {
            // cout << dis << endl;
            if(dis == INF)
                return -1;
            else
                maxTime = max(maxTime, dis);
        }
        return maxTime;
    }
};
