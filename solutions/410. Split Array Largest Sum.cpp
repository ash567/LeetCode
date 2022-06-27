class Solution {
    int numDays(vector<int>& nums, int maxCap) {
        int currCap = 0, days = 0;
        for(int n : nums) {
            if(n > maxCap)
                return numeric_limits<int>::max();
            currCap += n;
            if(currCap > maxCap) {
                days++;
                currCap = n;
            }
        }
        return ++days;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right;
        for(int n : nums)
            right += n;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(numDays(nums, mid) <= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
