class Solution {
    
    vector<int> getList(vector<int>& nums, int n, int sign = 1) {
        priority_queue<int> q;
        int qSize = 0;
        for(int i : nums) {
            q.push(i * sign);
            qSize++;
            if(qSize > n) {
                q.pop();
                qSize--;
            }
        }
        vector<int> l;
        while(!q.empty()) {
            l.push_back(q.top() * sign);
            q.pop();
        }
        sort(l.begin(), l.end());
        return l;
    }
    
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4)
            return 0;
        vector<int> bigList = getList(nums, 4, -1), smallList = getList(nums, 4);
        int ans = INT_MAX;
