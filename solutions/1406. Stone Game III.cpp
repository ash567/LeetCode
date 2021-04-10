class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        string winner = "Tie";
        if(stoneValue.size() == 0)
            return winner;
        vector<int> noPicked(stoneValue.size(), 0);
        vector<long long> maxValue(stoneValue.size(), numeric_limits<long long>::min());
        maxValue[stoneValue.size() - 1] = stoneValue[stoneValue.size() - 1];
        long long totalSum = stoneValue[stoneValue.size() - 1];
        for(int i = stoneValue.size() - 2; i >= 0; i--) {
            totalSum += stoneValue[i];
            int currSum = 0;
            for(int j = 0; j < 3; j++) {
                if(i + j >= stoneValue.size())
                    break;
                currSum += stoneValue[i+j];
                int finalSum = currSum;
                int k = i + j + 1;
                if(k < stoneValue.size()) {
                    int jump = noPicked[k];
                    if(k + jump + 1 < stoneValue.size()) {
                        finalSum += maxValue[k + jump + 1];
                    }
                }
                if(finalSum > maxValue[i]) {
                    noPicked[i] = j;
