class Solution {
    long long getMaxScore(int M, int ind, vector<int>& piles, map<pair<int, int>, long long>& maxScore, vector<long long>& rightSum) {
        if(ind >= piles.size())
            return 0;
        if(M > piles.size())
            M = piles.size();
        pair<int, int> p = make_pair(M, ind);
        if(maxScore.find(p) == maxScore.end()) {
            long long maxSum = numeric_limits<long long>::min();
            for(int X = 0; X < 2 * M; X++) {
                long long sumX = rightSum[ind];
                if((ind + X + 1) >= piles.size()) {
                    maxSum = max(maxSum, sumX);
                    break;
                } else {
                    sumX -= getMaxScore(max(X+1, M), ind + X + 1, piles, maxScore, rightSum);
                    maxSum = max(maxSum, sumX);
                }
            }
            maxScore[p] = maxSum;
        }
        return maxScore[p];
    }
public:
    int stoneGameII(vector<int>& piles) {
        map<pair<int, int>, long long> maxScore;
        vector<long long> rightSum(piles.size(), 0);
        long long sumTotal = 0;
        for(int i = piles.size() - 1; i >= 0; i--) {
            sumTotal += piles[i];
            rightSum[i] = sumTotal;
        }
        return getMaxScore(1, 0, piles, maxScore, rightSum);
    }
};
