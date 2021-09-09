class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapSum = {{0, 1}};
        int tot = 0, sumCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            tot += nums[i];
            sumCount += mapSum[tot - k];
            mapSum[tot]++;
        }
        return sumCount;
    }
};
