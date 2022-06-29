class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        // k = min((long) k, (long) nums1.size() * (long) nums2.size());
        auto compare = [&nums1, &nums2](pair<int, int> p1, pair<int, int> p2) {
          return (nums1[p1.first] +  nums2[p1.second]) > (nums1[p2.first] +  nums2[p2.second]);
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        for(int i = 0; i < nums1.size(); i++) {
            pq.push({i, 0});
        }
        while(k-- and !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            // cout << pq.size() << endl;
            ans.push_back({nums1[p.first], nums2[p.second]});
            // cout << p.first << " " << p.second << endl;
            if(p.second < (int) nums2.size() - 1) {
                pq.push({p.first, p.second + 1});
            }
        }
        return ans;
    }
};
