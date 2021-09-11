class Solution {
    int getMaxCoins(const vector<int>& numArray, vector<vector<int> >& maxScore, int l, int r) {
        if(maxScore[l][r] == -1) {
            int intMax = INT_MIN;
            for(int i = l + 1; i < r; i++) {
                intMax = max(intMax, getMaxCoins(numArray, maxScore, l, i) + getMaxCoins(numArray, maxScore, i, r) + numArray[l]*numArray[i]*numArray[r]);
            }
            maxScore[l][r] = intMax;
        }
        return maxScore[l][r];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        vector<int> numArray(nums.size() + 2, 1);
        vector<vector<int> > maxScore(numArray.size(), vector<int>(numArray.size(), -1));
        for(int i = 0; i < nums.size(); i++) {
            maxScore[i][i+1] = 0;
            numArray[i+1] = nums[i];
        }
        maxScore[nums.size()][nums.size()+1] = 0;
        return getMaxCoins(numArray, maxScore, 0, numArray.size()-1);
    }
};
