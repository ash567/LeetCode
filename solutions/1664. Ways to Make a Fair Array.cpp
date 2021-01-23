class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int even_odd_sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i%2 == 0)
                even_odd_sum += nums[i];
            else
                even_odd_sum -= nums[i];
        }
        int prefix_even_odd_sum = 0, suffix_even_odd_sum = even_odd_sum;
        for(int i = 0; i < nums.size(); i++) {
            int mult_factor = 1;
            if(i % 2 == 0) {
                mult_factor = -1;
            }
            suffix_even_odd_sum += mult_factor * nums[i];
            if(prefix_even_odd_sum - suffix_even_odd_sum == 0)
                ans++;
            prefix_even_odd_sum += (-1) * mult_factor * nums[i];
         }
        return ans;
    }
};
