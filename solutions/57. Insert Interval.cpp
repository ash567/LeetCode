class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        if(intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        } else if(newInterval[1] < intervals[0][0]) {
            ans.push_back(newInterval);
            ans.insert(ans.end(), intervals.begin(), intervals.end());
            return ans;
        } else if(newInterval[0] > intervals[intervals.size()-1][1]) {
            ans.insert(ans.end(), intervals.begin(), intervals.end());
            ans.push_back(newInterval);
            return ans;
        } else {
            int firstVal, lastVal;
            firstVal = newInterval[0];
            lastVal = newInterval[1];
            bool insertFlag = true;
            for(int i = 0; i < intervals.size(); i++) {
                if(intervals[i][1] < newInterval[0]) {
                    ans.push_back(intervals[i]);
                } else if(intervals[i][0] > newInterval[1]) {
                    if(insertFlag) {
                        vector<int> unionInterval = {firstVal, lastVal};
                        ans.push_back(unionInterval);
                        insertFlag = false;
                    }
                    ans.push_back(intervals[i]);
                } else {
                    firstVal = min(firstVal, intervals[i][0]);
                    lastVal = max(lastVal, intervals[i][1]);
                    if(i == intervals.size() - 1 || lastVal < intervals[i+1][0]) {
                        vector<int> unionInterval = {firstVal, lastVal};
                        ans.push_back(unionInterval);
                        insertFlag = false;
                    }
                }
            }
            // for(auto i : ans) {
            //     cout << "(" + to_string(i[0]) + ", " + to_string(i[1]) + ") ";
            // }
            // cout << endl;
            return ans;
        }
        
        // map<int, int> endIndexMap;
        // for(int i = 0; i < intervals.size(); i++) {
        //     endIndexMap[intervals[i][1]]= i;
        // }
        // auto firstItr = endIndexMap.lower_bound(newInterval[0]);
        // int firstIndex = 0;
        // if(firstItr == endIndexMap.end()) {
        //     ans.insert(ans.begin(), intervals.begin(), intervals.end());
        //     ans.push_back(newInterval);
        //     return ans;
        // } else {
