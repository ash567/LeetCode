class Solution {
    long double fastPow(long double x, long n) {
        if(n == 0)
            return 1.0;
        long double half = fastPow(x, n/2);
        long double result = half * half;
        if(n % 2 == 1)
            result *= x;
        return result;
    }
​
public:
    long double myPow(long double x, long n) {
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        cout << x << endl;
        return fastPow(x, n);
    }
};
