class Solution {
    int countDays(vector<int>& nums, int divisor) {
        int countDays = 0;
        for(int n : nums) {
            countDays += n / divisor;
            if(n % divisor != 0)
                countDays++;
        }
        return countDays;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxNum = 0;
        for(int n : nums) {
            maxNum = max(maxNum, n);
        }
        int left = 1, right = maxNum;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(countDays(nums, mid) <= threshold) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
