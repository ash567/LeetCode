class Solution {
    int numHours(const vector<int>& piles, int rate) {
        int h = 0;
        for(int p : piles) {
            h += p/rate;
            if(p % rate != 0)
                h++;
        }
        return h;
    }
​
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size())
            return -1;
        int left = 1, right = 0;
        for(int p : piles)
            right = max(right, p);
        while(left < right) {
            int mid = left + (right - left)/2;
            if(numHours(piles, mid) <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
