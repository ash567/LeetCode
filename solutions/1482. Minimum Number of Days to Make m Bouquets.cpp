class Solution {
    int numDays(const vector<int>& bloomDay, int d, int k) {
        int nboquet = 0, currCount = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] > d) {
                currCount = 0;
                continue;
            }
            currCount++;
            if(currCount >= k) {
                currCount = 0;
                nboquet++;
            }
        }
        return nboquet;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() / m < k) {
            return -1;
        }
        int left = 0, right = 0;
        for(int d : bloomDay) {
            right = max(right, d);
        }
        while(left < right) {
            int mid = left + (right - left)/2;
            if(numDays(bloomDay, mid, k) >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
        
    }
};
