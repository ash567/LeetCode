class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int leftProd = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) {
                leftProd *= nums[i-1];
            }
            ans[i] *= leftProd;
        }
        int rightProd = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(i != nums.size()-1) {
                rightProd *= nums[i+1];
            }
            ans[i] *= rightProd;
        }
        return ans;
    }
};
