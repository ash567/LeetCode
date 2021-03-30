class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int backIdx = 0, frontIdx = 0, maxDiff = numeric_limits<int>::min();
        map<int, int> maxVal;
        while(backIdx < points.size()) {
            if(frontIdx == backIdx) {
                maxVal[-(points[backIdx][0] + points[backIdx][1])]++;
                frontIdx++;
                continue;
            }
            maxVal[-(points[backIdx][0] + points[backIdx][1])]--;
            if(maxVal[-(points[backIdx][0] + points[backIdx][1])] == 0)
                maxVal.erase(-(points[backIdx][0] + points[backIdx][1]));
​
            while(frontIdx < points.size() && points[frontIdx][0] - points[backIdx][0] <= k) {
                maxVal[-(points[frontIdx][0] + points[frontIdx][1])]++;
                frontIdx++;
            }
            if(!maxVal.empty()) {
                maxDiff = max(maxDiff, - ((maxVal.begin())->first) - (points[backIdx][0] - points[backIdx][1]));
            }
            backIdx++;
        }
        return maxDiff;
    }
};
