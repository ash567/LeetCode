class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if(nums.size() == 0 or target <= nums[0])
        //     return 0;
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left)/2;
            if(target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
