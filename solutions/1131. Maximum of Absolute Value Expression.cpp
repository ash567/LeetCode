class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<long> maxExpr(4, 0), minVal(4, INT_MAX);
        for(int i = 0; i < arr1.size(); i++) {
            maxExpr[0] = max((long) i - arr1[i] - arr2[i] - minVal[0], maxExpr[0]);
            maxExpr[1] = max((long) i - arr1[i] + arr2[i] - minVal[1], maxExpr[1]);
            maxExpr[2] = max((long) i + arr1[i] - arr2[i] - minVal[2], maxExpr[2]);
            maxExpr[3] = max((long) i + arr1[i] + arr2[i] - minVal[3], maxExpr[3]);
            
            // cout << maxExpr[3] << endl;
            
            minVal[0] = min((long) i - arr1[i] - arr2[i], minVal[0]);
            minVal[1] = min((long) i - arr1[i] + arr2[i], minVal[1]);
            minVal[2] = min((long) i + arr1[i] - arr2[i], minVal[2]);
            minVal[3] = min((long) i + arr1[i] + arr2[i], minVal[3]);
        }
        return max(maxExpr[0], max(maxExpr[1], max(maxExpr[2], maxExpr[3])));
    }
};
