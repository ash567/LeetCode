class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 or x == 1)
            return x;
        else if(x < 0)
            return -1;
        
        long left = 0, right = x;
        while(left < right) {
            long mid = left + (right - left)/2;
            if(mid * mid > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
