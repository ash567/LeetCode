class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int maxPro, minPro, ans;
        ans = nums[0];
        maxPro = minPro = 1;
        for(int x: nums) {
            maxPro = x * maxPro;
            minPro = x * minPro;
            if(x < 0)
                swap(maxPro, minPro);
            maxPro = max(maxPro, x);
            minPro = min(minPro, x);
            ans = max(ans, maxPro);
        }
        return ans;
    }
};
