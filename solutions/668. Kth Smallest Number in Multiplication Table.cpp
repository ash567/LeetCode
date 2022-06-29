class Solution {
    int getSmaller(int m, int n, int val) {
        int count_ = 0;
        for(int i = 1; i <= m; i++) {
            count_ += min(n, val/i);
        }
        return count_;
    }
    
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while(l < r) {
            int mid = l + (r - l)/2;
            if(getSmaller(m, n, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
