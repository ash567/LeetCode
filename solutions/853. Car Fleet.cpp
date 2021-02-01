class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double> > posTimeTravelled(position.size(), make_pair(0, 0.0));
        for(int i = 0; i < position.size(); i++) {
            posTimeTravelled[i] = make_pair(position[i], (double) (target - position[i])/ ((double) speed[i]));
        }
        sort(posTimeTravelled.begin(), posTimeTravelled.end());
        int ans = 0;
//         TODO: fill this up
        double maxTime = -1.0;
        for(int i = posTimeTravelled.size()-1; i >= 0; i--) {
            if(posTimeTravelled[i].second > maxTime) {
                maxTime = posTimeTravelled[i].second;
                ans++;
            }
        }
        return ans;
    }
};
