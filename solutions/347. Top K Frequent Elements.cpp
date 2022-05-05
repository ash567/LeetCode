class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n : nums) {
            freq[n] += 1;
        }
        auto compare = [&freq](int n1, int n2) {
            return freq[n1] > freq[n2];
        };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        for(auto p : freq) {
            pq.push(p.first);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        ans.reserve(k);
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
