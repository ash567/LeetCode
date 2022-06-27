class Solution {
    int numDays(const vector<int>& weights, int capasity) {
        int days = 0;
        int currCap = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > capasity) {
                return numeric_limits<int>::max();
            }
            currCap += weights[i];
            if(currCap > capasity) {
                ++days;
                currCap = weights[i];
            }
        }
        return ++days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long left = 0, right = 0;
        for(int w : weights) {
            right += w;
        }
        
        while(left < right) {
            int mid = left + (right - left)/2;
            if(numDays(weights, mid) <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
