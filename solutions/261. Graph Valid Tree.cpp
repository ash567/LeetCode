class unionFind {
    vector<int> t_size, parent;
public:
    unionFind(int N) {
        t_size.resize(N, 1);
        parent.resize(N, -1);
        for(int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    int fi(int i) {
        if(parent[i] != i)
            parent[i] = fi(parent[i]);
        return parent[i];
    }
    
    int un(int i, int j) {
        int pi = fi(i), pj = fi(j);
        if(pi != pj) {
            if(t_size[pi] > t_size[pj])
                swap(pi, pj);
            parent[pi] = pj;
            t_size[pj] += t_size[pi];
        }
        return pj;
    }
};
​
class Solution {
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;
        unionFind uf(n);
        for(const auto & v : edges) {
            uf.un(v[0], v[1]);
        }
        int parent = uf.fi(0);
        for(int i = 1; i < n; i++) {
            if(uf.fi(i) != parent)
                return false;
        }
        return true;
    }
};
