class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int, int> > amCount(nums.size());
        int maxAmLen = 2;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                int d = nums[i] - nums[j];
                int prevCount = (amCount[i].find(d) != amCount[i].end())? prevCount = amCount[i][d]:0;
                if(prevCount > 0)
                    continue;
                int jdCount = (amCount[j].find(d) != amCount[j].end())? amCount[j][d]:0;
                amCount[i][d] = max(1 + jdCount, prevCount);
                maxAmLen = max(maxAmLen, amCount[i][d] + 1);
            }
        }
        return maxAmLen;
    }
};
