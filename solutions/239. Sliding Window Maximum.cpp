class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> maxNext;
        vector<int> maxWindow;
        for(int i = 0; i < nums.size(); i++) {
            while(!maxNext.empty() and nums[maxNext.back()] <= nums[i])
                maxNext.pop_back();
            maxNext.push_back(i);
            if(i >= k - 1) {
                while(!maxNext.empty() and maxNext.front() <= i - k)
                    maxNext.pop_front();
                maxWindow.push_back(nums[maxNext.front()]);
            }
        }
        return maxWindow;
    }
};
