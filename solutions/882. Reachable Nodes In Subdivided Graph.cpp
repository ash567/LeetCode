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
​
//Programming errors:
    // Setting the distance of the new node will be **1** + edge_weight + d[v]
    // Important Learning: When you had to get infromation at edge level, (number of nodes between edge that are reachable), iterate over edge. This was similar to on dfs question where you had to find out what is the size of maximum component by switching one node from 0 to 1 in a grid
​
class Solution {
    const int INF = 1e9;
    
    void dij(int source, vector<int>& dis, const vector<vector<pair<int, int> > >& edges) {
        dis.assign(edges.size(), INF);
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
