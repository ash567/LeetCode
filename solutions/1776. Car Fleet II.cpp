// Worse than n^2, lol!!
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(), -1.0);
        if(cars.size() == 0)
            return ans;
        set<int> notCollided;
        for(int i = 0; i < cars.size(); i++) {
            notCollided.insert(i);
        }
        multimap<double, int>  timeTaken;
        // position, speed
        for(int i = 0; i < cars.size() - 1; i++) {
            if(cars[i][1] <= cars[i+1][1])
                continue;
            double catchupTime = (((double)cars[i + 1][0] - cars[i][0])/((double) cars[i][1] - cars[i+1][1]));
            timeTaken.insert(make_pair(catchupTime, i));
            // timeTaken[catchupTime] = i;
        }
        // for(auto p : timeTaken) {
        //     cout << p.first << " " << p.second << endl;
        // }
        while(!timeTaken.empty()) {
            int carIdx = timeTaken.begin()->second;
            double catchupTime = timeTaken.begin()->first;
            timeTaken.erase(timeTaken.begin());
            if(notCollided.find(carIdx) == notCollided.end())
                continue;
            ans[carIdx] = catchupTime;
            auto carItr = notCollided.find(carIdx);
            auto carIdxBack = carItr;
            auto carIdxFront = notCollided.upper_bound(carIdx);
            if(carIdxBack != notCollided.begin() && carIdxFront != notCollided.end()) {
                --carIdxBack;
                int backIndex = *carIdxBack, frontIndex = *carIdxFront;
                if(cars[backIndex][1] > cars[frontIndex][1]) {
                    double catchupTime = (((double)cars[frontIndex][0] - cars[backIndex][0])/(cars[backIndex][1] - cars[frontIndex][1]));
                    timeTaken.insert(make_pair(catchupTime, backIndex));
                }
            }
            notCollided.erase(carItr);
        }
        return ans;
    }
};
