class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> incVal;
        int ans = 0;
        incVal.push(target[0]);
        for(int i = 1; i < target.size(); i++) {
            if(incVal.top() > target[i]) {
                ans += incVal.top() - target[i];
                while(!incVal.empty() and incVal.top() > target[i]) {
                    incVal.pop();
                }
            }
            incVal.push(target[i]);
        }
        ans += incVal.top();
        return ans;
    }
};
