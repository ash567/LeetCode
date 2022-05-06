#include<algorithm>
class Solution {
public:
    vector<int> smallestRange(const vector<vector<int>>& nums) {
        auto compare = [&nums](pair<int, int> p1, pair<int, int>p2){return nums[p1.first][p1.second] > nums[p2.first][p2.second];};
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(compare)> pq(compare);
        long d = numeric_limits<int>::min();
        for(int i = 0; i < nums.size(); i++) {
            d = max(d, (long) nums[i][0]);
            pq.push({i, 0});
        }
        long a, b;
        a = numeric_limits<int>::min();
        b = numeric_limits<int>::max();
        while(pq.size() == nums.size()) {
            pair<int, int> p = pq.top();
            long c = nums[p.first][p.second];
            if((d - c < b - a) || ((d - c == b - a) && (c < a))) {
                a = c;
                b = d;
            }
            pq.pop();
            if(nums[p.first].size() != p.second + 1) {
                d = max(d, (long) nums[p.first][p.second + 1]);
                pq.push({p.first, p.second + 1});
            }
        }
        vector<int> ans = {(int) a, (int) b};
        return ans;
    }
};
