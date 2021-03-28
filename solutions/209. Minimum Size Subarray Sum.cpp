class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(target == 0)
            return 0;
        int back, front, smallLen;
        long rangeSum;
        smallLen = nums.size() + 1;
        front = back = rangeSum = 0;
        while(front < nums.size()) {
            if(rangeSum < target) {
                rangeSum += nums[front];
                front++;
            } else {
                rangeSum -= nums[back];
                back++;
            }
            if(rangeSum >= target)
                smallLen = min(smallLen, front - back);
        }
        while(back < nums.size() && target <= rangeSum) {
            smallLen = min(smallLen, front - back);
            rangeSum -= nums[back];
            back++;
        }
        if(smallLen == nums.size() + 1)
            smallLen = 0;
        return smallLen;
    }
};
