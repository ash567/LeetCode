class Solution {
public:
    void countK(const vector<int>& nums, const int k, const long nsum, set<int>& ans, int m, int c) {
        long rsum = 0;
        unordered_map<long, int> sumCount;
        for(int i = 0; i < nums.size() - 1; i++) {
            rsum += nums[i];
            if(k != nums[i])
                sumCount[nsum + nums[i] - k] += 1;
            if(sumCount.find(2 * rsum) != sumCount.end()) {
                ans.insert(m * i + c);
            }
        }
        return;
    }
    
    int waysToPartition(vector<int>& nums, int k) {
        long nsum = 0;
        for(int n : nums)
            nsum += n;
        set<int> ans;
        if(((nsum % 2) + 2) % 2 == 0) {
            long rsum = 0;
            for(int i = 0; i < nums.size() - 1; i++) {
                rsum += nums[i];
                if(2 * rsum == nsum)
                    ans.insert(i);
            }
        }
        countK(nums, k, nsum, ans, 1, 0);
        reverse(nums.begin(), nums.end());
        countK(nums, k, nsum, ans, -1, nums.size() - 2);
        for(int n : ans)
            cout << n << " ";
        return ans.size();
    }
};
