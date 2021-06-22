class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int incVal;
        int ans = 0;
        incVal = target[0];
        for(int i = 1; i < target.size(); i++) {
            if(incVal > target[i]) {
                ans += incVal - target[i];
            }
            incVal = target[i];
        }
        ans += incVal;
        return ans;
    }
};
