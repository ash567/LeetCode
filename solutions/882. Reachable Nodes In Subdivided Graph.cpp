// Several silly mistakes:
// 1. Straigh away started to solve the problem using dij (that to in a wrong way).
// 2. Silly coding errors (static variables don't work, equation calculating was wrong)
​
​
// Tips:
// Whenever you pack informtaion in pair, always unpack it, name it and then use it.
// Sometimes, if you don't unpack, the program is less readable (specially problematic during interview) and you can make many errors
​
// When you are using a pair element, use typedef pair<int, int> pii
    
class Solution {
    const int INF = 1e9;
    
    void dij(int source, vector<int>& dis, const vector<vector<pair<int, int> > >& edges, int n) {
        dis.assign(n, INF);
        // using pii = pair<int, int>;
        set<pair<int, int> > q;
        q.insert({0, source});
        dis[source] = 0;
        while(!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());
            for(const auto& nei : edges[v]) {
                int to = nei.first, len = nei.second;
                if(dis[to] > dis[v] + len + 1) {
                    q.erase({dis[to], to});
                    dis[to] = dis[v] + len + 1;
                    q.insert({dis[to], to});
                }
            }
        }
        return;    
    }
    
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int> > > adj(n, vector<pair<int, int> >());
        for(const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> dis(n);
        dij(0, dis, adj, n);
        int reachCount = 0;
        for(int i = 0; i < dis.size(); i++) {
            // cout << dis[i] << '\n';
            if(dis[i] <= maxMoves) {
                reachCount++;
            }
        }
        for(const auto& edge : edges) {
            int subNodes = edge[2];
            int subNodesReachable = 0;
            for(int i = 0; i < 2; i++) {
                int node = edge[i];
                subNodesReachable += max(0, maxMoves - dis[node]);
            }
            subNodesReachable = min(subNodesReachable, subNodes);
            // cout << edge[0] << " " << edge[1] << ": " << subNodesReachable << endl;
            reachCount += subNodesReachable;
        }
        return reachCount;
    }
};
