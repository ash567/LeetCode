class Solution {
    int cond(const vector<int>& nums, int ths) {
        int count = 0;
        int i = 0, j = 0;
        for(; i < nums.size(); i++) {
            while(j < i and nums[i] - nums[j] > ths) {
                j++;
            }
            count += (i-j);
        }
        return count;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        while(left < right) {
            int mid = left + (right - left)/2;
            if(cond(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
