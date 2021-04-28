class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<int> temp = {target, 0};
        stations.push_back(temp);
        priority_queue<int> currOption;
        currOption.push(startFuel);
        int currPos = 0, nStations = 0;
        bool reach = true;
        for(int i = 0; i < stations.size() and reach; i++) {
            while(currPos < stations[i][0] and !currOption.empty()) {
                nStations++;
                currPos += currOption.top();
                currOption.pop();
            }
            if(currPos < stations[i][0]) {
                reach = false;
            } else {
                currOption.push(stations[i][1]);
            }
        }
        if(reach)
            return nStations - 1;
        else
            return -1;
    }
};
