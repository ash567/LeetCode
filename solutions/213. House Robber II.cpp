class Solution {
    int robHelper(vector<int>& nums, int beg, int end) {
        int withLastRobbed, withoutLastRobbed;
        withLastRobbed = withoutLastRobbed = 0;
        for(int i = beg; i < end; i++) {
            int temWithLastRobbed = withoutLastRobbed + nums[i];
            withoutLastRobbed = max(withoutLastRobbed, withLastRobbed);
            withLastRobbed = temWithLastRobbed;
        }
        return max(withLastRobbed, withoutLastRobbed);
    }
    
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        else
            return max(nums[0] + robHelper(nums, 2, nums.size()-1), robHelper(nums, 1, nums.size()));
    }
};
