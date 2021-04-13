class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(N >= K + W - 1 || K == 0)
            return 1.0;
        else if(K > N)
            return 0.0;
        double P = (1.0)/W;
        vector<double> prob(K + W, 1.0);
        double lastWSum = 1.0;
        for(int i = 1; i < K + W; i++) {
            if(i > W)
                lastWSum -= prob[i-W-1];
            prob[i] = lastWSum * P;
            if(i < K)
                lastWSum += prob[i];
        }
        double ans = 0.0;
        for(int i = K; i <= N; i++) {
            ans += prob[i];
        }
        return ans;
    }
};
