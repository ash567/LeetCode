class Solution {
public:
    int rob(vector<int>& nums) {
        int withLastRobbed, withoutLastRobbed;
        withLastRobbed = withoutLastRobbed = 0;
        for(auto money : nums) {
            int temWithLastRobbed = withoutLastRobbed + money;
            withoutLastRobbed = max(withLastRobbed, withoutLastRobbed);
            withLastRobbed = temWithLastRobbed;
        }
        return max(withLastRobbed, withoutLastRobbed);
    }
};
