class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<pair<int, int> > monQueue;
        for(int i = T.size() - 1; i >= 0; i--) {
            while(!monQueue.empty() and monQueue.top().first <= T[i]) {
                monQueue.pop();
            }
            if(!monQueue.empty()) {
                ans[i] = monQueue.top().second - i;
            }
            monQueue.push(make_pair(T[i], i));
        }
        return ans;
    }
};
