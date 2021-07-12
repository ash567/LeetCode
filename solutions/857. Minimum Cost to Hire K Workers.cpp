class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        if(k > wage.size())
            return -1;
        vector<pair<double, int> > effective;
        for(int i = 0; i < quality.size(); i++) {
            effective.push_back({wage[i]/((double) quality[i]), quality[i]});
        }
        sort(effective.begin(), effective.end());
        int sum = 0, N = effective.size();
        priority_queue<int> pq;
        for(int i = 0; i < k-1; i++) {
            pq.push(effective[i].second);
            sum += effective[i].second;
        }
        double minWage = INT_MAX;
        for(int i = k - 1; i < wage.size(); i++) {
            minWage = min(minWage, (sum + effective[i].second) * effective[i].first);
            // cout << sum << endl << minWage << endl << endl;
            sum += effective[i].second;
            pq.push(effective[i].second);
            sum -= pq.top();
            pq.pop();
        }
        return minWage;
    }
};
