            adj[s].push_back({v, w});
            adj[v].push_back({s, 1.0/w});
        }
        unordered_map<string, int> seen;
        unordered_map<string, double> val;
        int id = 0;
        for(const auto& edgeList : adj) {
            const string& s = edgeList.first;
            // auto& l = edgeList->second;
            if(seen.find(s) != seen.end())
                continue;
            else {
                // cout << s << endl;
                dfs(s, adj, seen, val, 1.0, id);
                id++;
            }
        }
        // for(auto it : val) {
        //     cout << it.first << ": " << it.second << endl;
        // }
        vector<double> result;
        for(auto& q : queries) {
            string s = q[0], v = q[1];
            if(seen.count(s) == 0 || seen.count(v) == 0 || seen[s] != seen[v])
                result.push_back(-1);
            else
                result.push_back(val[s]/val[v]);
        }
        return result;
    }
};
