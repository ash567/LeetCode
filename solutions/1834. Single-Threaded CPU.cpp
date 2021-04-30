class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int, pair<int, int>>> taskVector;
        taskVector.reserve(tasks.size());
        for(int i = 0; i < tasks.size(); i++) {
            const auto &task = tasks[i];
            taskVector.push_back(make_pair(task[0], make_pair(i, task[1])));
        }
        sort(taskVector.begin(), taskVector.end());
        // beg, index, duration
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int> > > > pq;
        long currIndex = 0, currTime = 0;
        vector<int> ans;
        ans.reserve(taskVector.size());
        while(currIndex < taskVector.size() or !pq.empty()) {
            if(pq.empty()) {
                int start = taskVector[currIndex].first, ind = taskVector[currIndex].second.first, dur = taskVector[currIndex].second.second;
                while(currIndex < taskVector.size() && taskVector[currIndex].first == start) {
                    pq.push(make_pair(taskVector[currIndex].second.second, make_pair(taskVector[currIndex].second.first, taskVector[currIndex].first)));
                    currIndex++;
                }
                currTime = start;
            } else {
                auto paPair = pq.top();
                pq.pop();
                int dur = paPair.first, ind = paPair.second.first, start = paPair.second.second;
                currTime += dur;
                while(currIndex < taskVector.size() && taskVector[currIndex].first <= currTime) {
                    pq.push(make_pair(taskVector[currIndex].second.second, make_pair(taskVector[currIndex].second.first, taskVector[currIndex].first)));
                    currIndex++;
                }
                ans.push_back(ind);
            }
        }
        return ans;
    }
};
